//
//  BluetoothConnectionManager.h
//  GoTenna
//
//  Created by Julietta Yaunches on 30/05/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol BluetoothPairingProtocol;

static dispatch_queue_t GTBluetoothConnectionQueue() {
    static dispatch_queue_t bluetooth_activity_queue;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        bluetooth_activity_queue = dispatch_queue_create("com.GT.GTBluetoothConnectionQueue", DISPATCH_QUEUE_CONCURRENT);
    });
    
    return bluetooth_activity_queue;
}

extern NSString * const kGoTennaServiceUUID;
extern NSString * const kGoTennaDeviceInformationUUID;
extern NSString * const kGoTennaKeepAliveCharacteristicUUID;
extern NSString * const kGoTennaWriteCharacteristicUUID;
extern NSString * const kGoTennaReadCharacteristicUUID;
extern NSString * const kGoTennaBluetoothProtocolRevisionCharacteristicUUID;

@interface BluetoothConnectionManager : NSObject<CBCentralManagerDelegate>
@property (weak, nonatomic) id<BluetoothPairingProtocol> pairingDelegate;
@property(nonatomic) BOOL connectionNotRequired;

+ (BluetoothConnectionManager *) shared;
- (void)scanAndConnect;
- (void)stopScan;
- (void)resetCentralManager;
- (void)userDisconnect;
- (void)clearScannedDevice;

- (BOOL)isScannedDeviceSaved;
- (BOOL)isConnected;
- (BOOL)isScanning;

@end
