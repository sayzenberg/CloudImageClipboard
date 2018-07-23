//
//  ViewController.swift
//  CloudImageClipboard
//
//  Created by Stanley Ayzenberg on 7/23/18.
//  Copyright © 2018 Studio VN. All rights reserved.
//

import UIKit
import OAuthSwift

class ViewController: UIViewController {
    //MARK: Properties
    var oauthswift: OAuth2Swift?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    //MARK: Actions
    
    @IBAction func signIn(_ sender: UIButton) {
        oauthswift = OAuth2Swift(
            consumerKey: "03890202-e68d-4781-910a-586a45e29df0",
            consumerSecret: "",
            authorizeUrl:   "https://login.microsoftonline.com/common/oauth2/v2.0/authorize",
            accessTokenUrl: "https://login.microsoftonline.com/common/oauth2/v2.0/token",
            responseType:   "code"
        )
        
        let _ = oauthswift?.authorize(
            withCallbackURL: URL(string: "msal03890202-e68d-4781-910a-586a45e29df0://auth")!,
            scope: "UserActivity.ReadWrite.CreatedByApp",
            state: generateState(withLength: 32),
            success: { credential, response, parameters in
                print(credential.oauthToken)
                let alert = UIAlertController(title: "Got a token!", message: credential.oauthToken, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Close", style: .cancel, handler: nil))
                self.present(alert, animated: true)
                // Do your request
            },
            failure: { error in
                print(error.localizedDescription)
            })

    }
    
}

