//
//  GTPairingManager.h
//  GoTenna
//
//  Created by Julietta Yaunches on 11/25/14.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "GTPairingConnectionState.h"

@protocol GTPairingHandlerProtocol <NSObject>
- (void)updateState:(GTConnectionState)state;
@end

@protocol BluetoothPairingProtocol <NSObject>
- (void)didConnectToPeripheral;
- (void)bluetoothConnectionNotAvailable:(CBManagerState)state;
- (void)canNotConnectToPeripheral;
- (void)bluetoothPoweredOn;
- (void)nonUserDisconnectionOccurred;
@end

@interface GTPairingManager : NSObject <BluetoothPairingProtocol>
@property(nonatomic) id<GTPairingHandlerProtocol> pairingHandler;
@property(nonatomic) BOOL shouldReconnect;

// Shared singleton instance
// This class is a singleton. Use this method to get the global instance.
+ (GTPairingManager *)shared;

// Disconnect
// Call this to disconnect a connected goTenna
- (void)initiateDisconnect;

// Connect
// Call this to connect to your goTenna
// NOTE: before calling this, ensure to set the pairingHandler delegate to get callbacks on when the state changes to
// connected or any other possible states
- (void)initiateScanningConnect;
- (void)stopScanningConnect;
- (void)clearSavedScannedDevice;

// ConnectState
// Use this method to get the current connection status of your goTenna
- (GTConnectionState)connectingState;

- (BOOL)isScannedDeviceSaved;

@end
