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

class ViewController: UIViewController {
    //MARK: Properties
    var oauthswift: OAuth2Swift!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        oauthswift = OAuth2Swift(
            consumerKey: "03890202-e68d-4781-910a-586a45e29df0",
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
        var user: User?
        
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
                    user = refreshToken(credentialData: keyData)
                    return
                }
                else
                {
                    user = loadCredentials()
                    return
                }
            }
        }
        
        user = self.handleUserSignIn()
        
        
    }
    
    func handleUserSignIn() -> User?
    {
        var user: User? = nil
        
        oauthswift.authorizeURLHandler = SafariURLHandler(viewController: self, oauthSwift: oauthswift)
        let _ = oauthswift.authorize(
            withCallbackURL: URL(string: "msal03890202-e68d-4781-910a-586a45e29df0://auth")!,
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

