//
//  GTFileReceived.h
//  GoTenna
//
//  Created by JOSHUA M MAKINDA on 1/27/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    GTFileReceivedTypeText,
    GTFileReceivedTypeImage,
} GTFileReceivedType;


@interface GTFileReceived : NSObject <NSCoding>

- (instancetype)initWithFileName:(NSString*)fileName fileData:(NSData*)fileData fileType:(GTFileReceivedType)fileType;

@property (nonatomic, readonly) NSString *fileName;
@property (nonatomic, readonly) NSData *fileData;
@property (nonatomic, readonly) GTFileReceivedType fileType;
@property (nonatomic, readonly) NSDictionary *parsedContent;

@end
