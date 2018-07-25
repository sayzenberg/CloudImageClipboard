//
//  GraphClient.swift
//  CloudImageClipboard
//
//  Created by Stanley Ayzenberg on 7/23/18.
//  Copyright © 2018 Studio VN. All rights reserved.
//

import Foundation
import Alamofire
import AlamofireObjectMapper

class GraphClient
{
    var ticket: String
    
    init(ticket: String)
    {
        self.ticket = ticket
    }
    
    func putImageActivity(imageUrl: String)
    {
        let activityId = base64ToBase64url(base64: imageUrl.data(using: .utf8)!.base64EncodedString())
        let url = "https://graph.microsoft.com/v1.0/me/activities/\(activityId)"
        let parameters: Parameters = [
            "appActivityId": activityId,
            "activitySourceHost": "studiovn.life",
            "activationUrl": "blah",
            "visualElements": [
                "displayText": "Test"
                ],
            "contentInfo": [
                "imageUrl": imageUrl
            ]
            ]
        let headers: HTTPHeaders = ["Authorization": "Bearer \(ticket)"]
        Alamofire.request(
            url,
            method: .put,
            parameters: parameters,
            encoding: JSONEncoding.default,
            headers: headers).responseObject { (response: DataResponse<Activity>) in
                let activityResponse = response.result.value
                print(activityResponse?.appActivityID)
        }
    }
    
    func base64ToBase64url(base64: String) -> String {
        let base64url = base64
            .replacingOccurrences(of: "+", with: "-")
            .replacingOccurrences(of: "/", with: "_")
            .replacingOccurrences(of: "=", with: "")
        return base64url
    }
}
