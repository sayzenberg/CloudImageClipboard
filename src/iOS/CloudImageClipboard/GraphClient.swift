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
    
    func putImageActivity(activityId: String, imageUrl: String)
    {
        let url = "https://graph.microsoft.com/v1.0/me/activities/\(activityId)"
        let parameters: Parameters = [
            "appActivityId": activityId,
            "activitySourceHost": "cloudimageclipboard.com",
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
}
