//
//  ViewController.swift
//  CloudImageClipboard
//
//  Created by Stanley Ayzenberg on 7/23/18.
//  Copyright © 2018 Studio VN. All rights reserved.
//

import UIKit
import OAuthSwift
import Locksmith
import PromiseKit

class ViewController: UIViewController {
    //MARK: Properties
    var oauthswift: OAuth2Swift!
    var signedInUser: User?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        oauthswift = OAuth2Swift(
            consumerKey: "8b45908d-7e92-4e34-9ade-e69aebee04f0",
            consumerSecret: "",
            authorizeUrl:   "https://login.microsoftonline.com/common/oauth2/v2.0/authorize",
            accessTokenUrl: "https://login.microsoftonline.com/common/oauth2/v2.0/token",
            responseType:   "code"
        )
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    //MARK: Actions
    
    @IBAction func signIn(_ sender: UIButton) {
        
        if let keyData = Locksmith.loadDataForUserAccount(userAccount: "OAUTH")
        {
            if let expiration = keyData["expiration"]
            {
                let expirationString = expiration as! String
                let formatter = DateFormatter()
                formatter.dateFormat = "yyyy-MM-dd hh:mm:ss"
                formatter.timeZone = TimeZone(secondsFromGMT: 0)
                if (formatter.date(from: expirationString)! < Date.init())
                {
                    self.signedInUser = refreshToken(credentialData: keyData)
                    return
                }
                else
                {
                    self.signedInUser = loadCredentials()
                    return
                }
            }
        }
        
        self.signedInUser = self.handleUserSignIn()
    }
    
    @IBAction func signOut(_ sender: UIButton) {
        self.signedInUser = nil
        do
        {
            try Locksmith.deleteDataForUserAccount(userAccount: "OAUTH")
        }
        catch
        {
        }
    }
    
    @IBAction func getActivities(_ sender: UIButton) {
        let client = GraphClient(ticket: self.signedInUser!.authTicket!)
        var imageUrl: String = ""
        client.getImageActivities().then { activities -> Promise<UIImage> in
            imageUrl = activities.value![0].contentInfo!.imageUrl!
            return client.getImage(imageUrl: imageUrl)
        }.map { image in
            let pasteboard: UIPasteboard = UIPasteboard.general
            pasteboard.image = image
            let alert = UIAlertController(title: "Image copied to clipboard!", message: "The most recent image in your feed is on your clipboard now. Go ahead and paste it into your preferred app.", preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
            self.present(alert, animated: true)
        }
    }
    
    @IBAction func postActivity(_ sender: UIButton) {
        let client = GraphClient(ticket: self.signedInUser!.authTicket!)
        let pasteboard: UIPasteboard = UIPasteboard.general
        var imageUrl: String = ""
        if pasteboard.hasStrings
        {
            imageUrl = pasteboard.string!
        }
        else if pasteboard.hasURLs
        {
            imageUrl = (pasteboard.url?.absoluteString)!
        }
        else
        {
            return
        }
        
        client.putImageActivity(imageUrl: imageUrl).map { activity in
            let alert = UIAlertController(title: "Image uploaded to Graph! ", message: "Uploaded image to Graph. Activity ID: " + activity.id!, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
            self.present(alert, animated: true)
        }

    }
    
    
    func handleUserSignIn() -> User?
    {
        var user: User? = nil
        
        oauthswift.authorizeURLHandler = SafariURLHandler(viewController: self, oauthSwift: oauthswift)
        let _ = oauthswift.authorize(
            withCallbackURL: URL(string: "msal8b45908d-7e92-4e34-9ade-e69aebee04f0://auth")!,
            scope: "UserActivity.ReadWrite.CreatedByApp offline_access",
            state: generateState(withLength: 32),
            success: { credential, response, parameters in
                let alert = UIAlertController(title: "Got a token!", message: credential.oauthToken, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
                self.present(alert, animated: true)
                do
                {
                    try self.saveCredentials(credential: credential)
                    user = User(authTicket: credential.oauthToken, refreshTicket: credential.oauthRefreshToken, ticketExpiration: credential.oauthTokenExpiresAt!)
                    self.signedInUser = user
                }
                catch
                {
                    
                }
                
                // Do your request
        },
            failure: { error in
        })
        
        return user
    }
    
    func refreshToken(credentialData: Dictionary<String, Any>) -> User?
    {
        var user: User? = nil
        if let refreshToken = credentialData["refresh_token"]
        {
            oauthswift.renewAccessToken(
                withRefreshToken: refreshToken as! String,
                success: { credential, response, paraters in
                    let alert = UIAlertController(title: "Got a token!", message: credential.oauthToken, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
                    self.present(alert, animated: true)
                    do
                    {
                        try self.saveCredentials(credential: credential)
                        user = User(authTicket: credential.oauthToken, refreshTicket: credential.oauthRefreshToken, ticketExpiration: credential.oauthTokenExpiresAt!)
                        self.signedInUser = user
                    }
                    catch
                    {
                        
                    }
                },
                failure: { error in
            })
        }
        else
        {
            user = handleUserSignIn()
        }
        
        return user
    }
    
    func saveCredentials(credential: OAuthSwiftCredential)
    throws {
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd hh:mm:ss"
        formatter.timeZone = TimeZone(secondsFromGMT: 0)
        let expirationString = formatter.string(from: credential.oauthTokenExpiresAt!)
        
        try Locksmith.updateData(data: [
            "access_token": credential.oauthToken,
            "refresh_token": credential.oauthRefreshToken,
            "expiration": expirationString], forUserAccount: "OAUTH")
        
    }
    
    func loadCredentials() -> User?
    {
        var user: User? = nil
        if let keyData = Locksmith.loadDataForUserAccount(userAccount: "OAUTH")
        {
            let formatter = DateFormatter()
            formatter.dateFormat = "yyyy-MM-dd hh:mm:ss"
            formatter.timeZone = TimeZone(secondsFromGMT: 0)
            let accessToken = keyData["access_token"] as! String
            let refreshToken = keyData["refresh_token"] as! String
            let expirationString = keyData["expiration"] as! String
            let expiration = formatter.date(from: expirationString)
            
            let alert = UIAlertController(title: "Got a token!", message: accessToken, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
            self.present(alert, animated: true)
            
            user = User(authTicket: accessToken, refreshTicket: refreshToken, ticketExpiration: expiration!)
        }
        
        return user
    }
}

