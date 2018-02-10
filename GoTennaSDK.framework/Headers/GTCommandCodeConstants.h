//
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kMessageTypeTextOnly;
extern NSString *const kMessageTypeTextAndLocation;
extern NSString *const kMessageTypeLocationOnly;
extern NSString *const kMessageTypeLocationRequestOnly;
extern NSString *const kMessageTypeLocationRequestAndText;
extern NSString *const kMessageTypeSetGroupGID;
extern NSString *const kMessageTypeLogOnTextOnly;
extern NSString *const kMessageTypePingTextOnly;
extern NSString *const kMessageTypeFirmwarePublicKeyResponse;
extern NSString *const kMessageTypeUserPublicKeyResponse;
extern NSString *const kMessageTypePublicKeyRequest;
extern NSString *const kMessageTypeFileTransfer;

extern char *const gtSetGIDCommandCode;
extern char *const gtSetGIDResponseCode;
extern char *const gtSetGIDFailureCode;

extern char *const gtResetGotennaCommandCode;
extern char *const gtResetGotennaResponseCode;
extern char *const gtResetGotennaFailureCode;

extern char *const gtSetPublicKeyCommandCode;
extern char *const gtSetPublicKeyResponseCode;
extern char *const gtSetPublicKeyFailureCode;

extern char *const gtDeleteLastMessageCommandCode;
extern char *const gtDeleteLastMessageResponseCode;
extern char *const gtDeleteLastMessageFailureCode;

extern char *const gtGetMessageCommandCode;
extern char *const gtGetMessageResponseCode;
extern char *const gtGetMessageFailureCode;

extern char *const gtSendMessageCommandCode;
extern char *const gtSendMessageResponseCode;
extern char *const gtSendMessageFailureCode;

extern char *const gtGetSystemInfoCommandCode;
extern char *const gtGetSystemInfoResponseCode;
extern char *const gtGetSystemInfoFailureCode;

extern char *const gtEchoCommandCode;
extern char *const gtEchoResponseCode;
extern char *const gtEchoFailureCode;

extern char *const gtDisconnectGotennaCommandCode;
extern char *const gtDisconnectGotennaResponseCode;
extern char *const gtDisconnectGotennaFailureCode;

extern char *const gtDeleteGIDCommandCode;
extern char *const gtDeleteGIDResponseCode;
extern char *const gtDeleteGIDFailureCode;

extern char *const gtInitiateNewFirmwareWriteCommandCode;
extern char *const gtInitiateNewFirmwareWriteResponseCode;
extern char *const gtInitiateNewFirmwareWriteFailureCode;

extern char *const gtWriteFirmwareDataCommandCode;
extern char *const gtWriteFirmwareDataResponseCode;
extern char *const gtWriteFirmwareDataFailureCode;

extern char *const gtFinalizeFirmwareCommandCode;
extern char *const gtFinalizeFirmwareResponseCode;
extern char *const gtFinalizeFirmwareFailureCode;

extern char *const gtSetAppTokenCode;
extern char *const gtSetAppTokenResponseCode;
extern char *const gtSetAppTokenFailureCode;

extern char *const gtGIDTypeOneToOne;
extern char *const gtGIDTypeGroup;
extern char *const gtGIDTypeShout;
extern char *const gtGIDTypeEmergency;

extern char *const gtSetAppTokenCode;
extern char *const gtSetAppTokenResponseCode;

extern char *const gtActivateAntennaSweepCommandCode;
extern char *const gtActivateAntennaSweepResponseCode;
extern char *const gtActivateAntennaSweepFailureCode;

extern char *const gtFrequencyModeCommandCode;
extern char *const gtFrequencyModeResponseCode;
extern char *const gtFrequencyModeFailureCode;

extern char *const gtFrequencyModeNormal;
extern char *const gtFrequencyModeLow;
extern char *const gtFrequencyModeHigh;

extern char *const gtHardwareTransmitCommandCode;

extern char *const gtGetBinaryLogCommandCode;
extern char *const gtGetBinaryLogResponseCode;
extern char *const gtGetBinaryLogFailureCode;

extern char *const gtDeleteBinaryLogCommandCode;
extern char *const gtDeleteBinaryLogResponseCode;
extern char *const gtDeleteBinaryLogFailureCode;

extern char *const gtBERTestCommandCode;
extern char *const gtBERTestResponseCode;
extern char *const gtBERTestFailureCode;

extern char *const gtStoreDateTimeCommandCode;
extern char *const gtStoreDateTimeResponseCode;
extern char *const gtStoreDateTimeFailureCode;

extern char *const gtPowerSavingCommandCode;
extern char *const gtPowerSavingResponseCode;
extern char *const gtPowerSavingFailureCode;

extern char *const gtHardResetCommandCode;
extern char *const gtHardResetResponseCode;
extern char *const gtHardResetFailureCode;

extern char *const gtFrequencyCommandCode;
extern char *const gtFrequencyResponseCode;
extern char *const gtFrequencyFailureCode;

@interface GTCommandCodeConstants : NSObject
@end
