//
//  TLVTypes.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 12/14/15.
//  Copyright © 2015 goTenna. All rights reserved.
//

const int TLV_TYPE_MESSAGE_TYPE = 1;
const int TLV_TYPE_SENDER_INITIALS = 3;
const int TLV_TYPE_TEXT = 4;
const int TLV_TYPE_RECEIVING_GID = 5;
const int TLV_TYPE_LOCATION_MESSAGE_DATA = 6;

// LocationMessageData
const int TLV_TYPE_LOCATION_NAME = 7;
const int TLV_TYPE_LOCATION_LATITUDE = 8;
const int TLV_TYPE_LOCATION_LONGITUDE = 9;
const int TLV_TYPE_LOCATION_TYPE = 10;

// GroupCreationMessageData
const int TLV_TYPE_GROUP_GID = 11;
const int TLV_TYPE_GROUP_MEMBER_LIST = 12;
const int TLV_TYPE_GROUP_SHARED_SECRET = 13;


// For File Transfer
const int TLV_TYPE_FILE_TRANSFER_NAME = 14;
const int TLV_TYPE_FILE_TRANSFER_SIZE = 15;
const int TLV_TYPE_FILE_TRANSFER_UUID = 16;
const int TLV_TYPE_FILE_TRANSFER_STATUS = 17;
const int TLV_TYPE_FILE_TRANSFER_DATA = 18;

// For extended TLV sections
const int TLV_TYPE_ENCRYPTION_INFO = 251;

// For Public Key Exchange
const int TLV_TYPE_PUBLIC_KEY_DATA = 252;

const int TLV_TYPE_EXTENDER_JACKET_2B = 253;
const int TLV_TYPE_EXTENDER_JACKET_3B = 254;
const int TLV_TYPE_EXTENDER_JACKET_4B = 255;
