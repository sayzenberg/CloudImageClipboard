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
    var oauthswift: OAuth2Swift?
    
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
        if let keyData = Locksmith.loadDataForUserAccount(userAccount: "dummyuseraccount")
        {
            if let expiration = keyData["expiration"]
            {
                let expirationString = expiration as! String
                let formatter = DateFormatter()
                formatter.dateFormat = "yyyy-MM-dd hh:mm:ss"
                formatter.timeZone = TimeZone(secondsFromGMT: 0)
                if (formatter.date(from: expirationString)! < Date.init())
                {
                    refreshToken(credentialData: keyData)
                }
                else
                {
                    loadCredentials()
                    return
                }
            }
        }
        else
        {
            self.handleUserSignIn()
        }
    }
    
    func handleUserSignIn()
    {
        let _ = oauthswift?.authorize(
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
                }
                catch
                {
                    
                }
                
                // Do your request
        },
            failure: { error in
        })
    }
    
    func refreshToken(credentialData: Dictionary<String, Any>)
    {
        if let refreshToken = credentialData["refresh_token"]
        {
            oauthswift?.renewAccessToken(
                withRefreshToken: refreshToken as! String,
                success: { credential, response, paraters in
                    let alert = UIAlertController(title: "Got a token!", message: credential.oauthToken, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
                    self.present(alert, animated: true)
                    do
                    {
                        try self.saveCredentials(credential: credential)
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
            handleUserSignIn()
        }
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
            "expiration": expirationString], forUserAccount: "dummyuseraccount")
    }
    
    func loadCredentials()
    {
        let keyData = Locksmith.loadDataForUserAccount(userAccount: "dummyuseraccount")
        
        let accessToken = keyData!["access_token"] as! String;
        let alert = UIAlertController(title: "Got a token!", message: accessToken, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
        self.present(alert, animated: true)
    }
}

