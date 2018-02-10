//
//  GroupSecretManager.h
//  GoTenna
//
//  Created by Thomas Colligan on 1/12/16.
//  Copyright © 2016 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GroupSecretManager : NSObject

+ (GroupSecretManager *) shared;
+ (NSData *) generateSharedSecret;

- (NSData *) createAndSaveSecretForGroup:(NSNumber *)groupGID;
- (void)saveSecret:(NSData *)sharedSecret forGroup:(NSNumber *)groupGID;
- (NSData *)getSharedSecretForGroup:(NSNumber *)groupGID;

@end
