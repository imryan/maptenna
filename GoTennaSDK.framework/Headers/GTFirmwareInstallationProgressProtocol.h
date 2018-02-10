#import <Foundation/Foundation.h>

@protocol GTFirmwareInstallationProgressProtocol <NSObject>
- (void)initializeComplete;
- (void)finalizeComplete;
- (void)newProgressAmount:(float)progress;
- (void)updateComplete;
- (void)updateFailed;
- (void)updateInitialized;
@end