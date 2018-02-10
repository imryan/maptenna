// Copyright (c) 2014 goTenna. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class ChunkProcessor;
@class GTPacket;
@class GTCommand;
@class GTKeepAliveProcessor;

static dispatch_queue_t GTPeripheralWriteCommandSerialQueue() {
    static dispatch_queue_t peripheralWriteCommandQueue;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        peripheralWriteCommandQueue = dispatch_queue_create("com.GT.GTPeripheralWriteCommandSerialQueue", DISPATCH_QUEUE_SERIAL);
    });

    return peripheralWriteCommandQueue;
}

@interface GTPeripheralManager : NSObject <CBPeripheralDelegate>
@property(nonatomic, strong) CBPeripheral *peripheral;

+ (GTPeripheralManager *) shared;
- (void)updatePeripheral:(CBPeripheral *)peripheral;
- (void)writeCommandPackets:(GTCommand *)command;
- (BOOL)peripheralIsConnected;

- (void)scanPeripheralServices:(void (^)())onCharacteristicsReceived;

@end