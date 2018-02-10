//
//  BluetoothTlvConstants.h
//  GoTenna
//
//  Created by Thomas Colligan on 2/16/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const int BLUETOOTH_TLV_TYPE_PUBLIC_KEY;
extern const int BLUETOOTH_TLV_TYPE_PUBLIC_KEY_HASH;
extern const int BLUETOOTH_TLV_TYPE_MSG_PAYLOAD;
extern const int BLUETOOTH_TLV_TYPE_MSG_HEADER;
extern const int BLUETOOTH_TLV_TYPE_KEY_EXCHANGE_FAILED;
extern const int BLUETOOTH_TLV_TYPE_TIMESTAMP_STRING;
extern const int BLUETOOTH_TLV_TYPE_TIMESTAMP_DATA;
extern const int BLUETOOTH_TLV_TYPE_EMERGENCY_MESSAGE;
extern const int BLUETOOTH_TLV_TYPE_FREQUENCY_LIST;
extern const int BLUETOOTH_TLV_TYPE_FREQUENCY_CONTROL_INDEX;

@interface BluetoothTlvConstants : NSObject

@end
