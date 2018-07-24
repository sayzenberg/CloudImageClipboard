import Foundation
import ObjectMapper

class Activity: Mappable {
    var appActivityID, activitySourceHost, userTimezone, appDisplayName: String?
    var activationURL, contentURL, fallbackURL, createdDateTime: String?
    var lastModifiedDateTime, expirationDateTime, id, status: String?
    var contentInfo: ContentInfo?
    var visualElements: VisualInfo?
    var historyItems: [HistoryItem]?
//
//    init(appActivityID: String, activitySourceHost: String, userTimezone: String, appDisplayName: String, activationURL: String, contentURL: String, fallbackURL: String, createdDateTime: String, lastModifiedDateTime: String, expirationDateTime: String, id: String, status: String, contentInfo: ContentInfo, visualElements: VisualInfo, historyItems: [HistoryItem]) {
//        self.appActivityID = appActivityID
//        self.activitySourceHost = activitySourceHost
//        self.userTimezone = userTimezone
//        self.appDisplayName = appDisplayName
//        self.activationURL = activationURL
//        self.contentURL = contentURL
//        self.fallbackURL = fallbackURL
//        self.createdDateTime = createdDateTime
//        self.lastModifiedDateTime = lastModifiedDateTime
//        self.expirationDateTime = expirationDateTime
//        self.id = id
//        self.status = status
//        self.contentInfo = contentInfo
//        self.visualElements = visualElements
//        self.historyItems = historyItems
//    }
    
    required init?(map: Map) {
        
    }
    
    func mapping(map: Map) {
        self.appActivityID <- map["appActivityId"]
        self.activitySourceHost <- map["activitySourceHost"]
        self.userTimezone <- map["userTimezone"]
        self.appDisplayName <- map["appDisplayName"]
        self.activationURL <- map["activationURL"]
        self.contentURL <- map["contentURL"]
        self.fallbackURL <- map["fallbackURL"]
        self.createdDateTime <- map["createdDateTime"]
        self.lastModifiedDateTime <- map["lastModifiedDateTime"]
        self.expirationDateTime <- map["expirationDateTime"]
        self.id <- map["id"]
        self.status <- map["status"]
        self.contentInfo <- map["contentInfo"]
        self.visualElements <- map["visualElements"]
        self.historyItems <- map["historyItems"]
    }
}

class ContentInfo: Mappable {
    var dataType: String?
    var imageUrl: String?
    
    init(dataType: String?) {
        self.dataType = dataType
    }
    
    required init?(map: Map) {
        
    }
    
    func mapping(map: Map) {
        self.dataType <- map["dataType"]
        self.imageUrl <- map["imageUrl"]
    }
}

class HistoryItem: Mappable {
    var odataType: String?
    
    init(odataType: String?) {
        self.odataType = odataType
    }
    
    required init?(map: Map) {
        
    }
    
    func mapping(map: Map) {
        self.odataType <- map["odataType"]
    }
}

class VisualInfo: Mappable {
    var dataType: String?
    
    required init?(map: Map) {
        
    }
    
    func mapping(map: Map) {
        self.dataType <- map["dataType"]
    }
}
