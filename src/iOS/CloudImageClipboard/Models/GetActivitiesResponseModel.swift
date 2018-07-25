//
//  GetActivitiesResponseModel.swift
//  CloudImageClipboard
//
//  Created by Stanley Ayzenberg on 7/25/18.
//  Copyright © 2018 Studio VN. All rights reserved.
//

import Foundation
import ObjectMapper

class GetActivitiesResponseModel: Mappable
{
    var value: [Activity]?

    required init?(map: Map) {
        
    }
    
    func mapping(map: Map) {
        self.value <- map["value"]
    }
}
