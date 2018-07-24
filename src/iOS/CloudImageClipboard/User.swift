//
//  User.swift
//  CloudImageClipboard
//
//  Created by Stanley Ayzenberg on 7/23/18.
//  Copyright © 2018 Studio VN. All rights reserved.
//

import Foundation

class User
{
    //MARK: Properties
    var username: String?
    var firstName: String?
    var lastName: String?
    var authTicket: String?
    var refreshTicket: String?
    var ticketExpiration: Date?
    
    init(authTicket: String, refreshTicket: String, ticketExpiration: Date) {
        self.authTicket = authTicket;
        self.refreshTicket = refreshTicket;
        self.ticketExpiration = ticketExpiration;
    }
}
