//
//  MTMapViewController.m
//  Maptenna
//
//  Created by Ryan Cohen on 4/29/17.
//  Copyright © 2016 goTenna. All rights reserved.
//

@import GoTennaSDK;
@import Mapbox;

#import "MTMapViewController.h"
#import "ChatViewController.h"
#import "MaptennaKit.h"
#import "MTNodeAnnotation.h"
#import "MTNodePointAnnotation.h"

@interface MTMapViewController () <GTPairingHandlerProtocol, MGLMapViewDelegate, MaptennaKitDelegate>

@property (nonatomic, weak) IBOutlet UIBarButtonItem *connectBarButton;

@property (nonatomic, weak) IBOutlet UIView *nodeHUDView;
@property (nonatomic, weak) IBOutlet UILabel *nodeInformationLabel;

@property (nonatomic, strong) MGLMapView *mapView;
@property (nonatomic, strong) NSMutableArray<MTNodePointAnnotation *> *mapNodes;

@end

@implementation MTMapViewController

# pragma mark - Map

- (BOOL)mapView:(MGLMapView *)mapView annotationCanShowCallout:(id<MGLAnnotation>)annotation {
    return YES;
}

- (void)mapView:(MGLMapView *)mapView didUpdateUserLocation:(MGLUserLocation *)userLocation {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        double zoomLevel = (1 << 4);
        [mapView setCenterCoordinate:userLocation.coordinate zoomLevel:zoomLevel animated:YES];
    });
}

- (MGLAnnotationView *)mapView:(MGLMapView *)mapView viewForAnnotation:(id<MGLAnnotation>)annotation {
    if (![annotation isKindOfClass:[MTNodePointAnnotation class]]) {
        return nil;
    }
    
    static NSString *reuseIdentifier = @"PinIdentifier";
    MTNodeAnnotation *annotationView = [mapView dequeueReusableAnnotationViewWithIdentifier:reuseIdentifier];
    
    if (!annotationView) {
        annotationView = [[MTNodeAnnotation alloc] initWithReuseIdentifier:reuseIdentifier];
        annotationView.frame = CGRectMake(0, 0, 75, 75);
    }
    
    return annotationView;
}

- (void)updateNodeOnMap:(MTNode *)node {
    dispatch_async(dispatch_get_main_queue(), ^{
        MTNodePointAnnotation *pin = [[MTNodePointAnnotation alloc] initWithNode:node];
        [self.mapView addAnnotation:pin];
        
        // Debug
        self.nodeInformationLabel.text = [NSString stringWithFormat:@"Received node: %@", node.displayName];
        
        //        if ([self mapContainsNode:node]) {
        //            // dont fucking add it, replace it
        //            NSUInteger index = [self.mapNodes indexOfObject:pin];
        //            [self.mapNodes replaceObjectAtIndex:index withObject:pin];
        //
        //            [self.mapView removeAnnotation:pin];
        //            [self.mapView addAnnotation:pin];
        //        } else {
        //            // fucking add it
        //            [self.mapView addAnnotation:pin];
        //            [self.mapNodes addObject:pin];
        //        }
        //
        //        for (MTNodePointAnnotation *p in self.mapNodes) {
        //            NSLog(@"ID: %@", p.nodeIdentifier);
        //        }
    });
    
    // [self updateStatusLabel:[NSString stringWithFormat:@"%@ @ %@", [[[MTNode currentNode] owner] gid], [[MTNode currentNode] displayName]]];
}

- (BOOL)mapContainsNode:(MTNode *)node {
    for (MTNodePointAnnotation *point in self.mapNodes) {
        if ([point.nodeIdentifier isEqualToString:node.identifier]) {
            return YES;
        }
    }
    
    return NO;
}

- (void)setGID {
    // Debug
    NSString *name = @"Ryan";
    NSNumber *gid = @9088393634;
    
    if ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"]) {
        name = @"iPod";
        gid = @9088393635;
    }
    
    [[MaptennaKit shared] updateUserWithGID:gid name:name block:^(MTUser *user, MTNode *node, NSError *error) {
        if (!error) {
            NSLog(@"User: %@ / %@\nNode: %@", user.name, user.gid, node);
            [self updateStatusLabel:self.nodeInformationLabel.text = [NSString stringWithFormat:@"%@ @ %@", [[[MTNode currentNode] owner] gid], [[MTNode currentNode] displayName]]];
        } else {
            NSLog(@"Error: %@", error);
        }
    }];
}

# pragma mark - MaptennaKitDelegate

- (void)maptenna:(MaptennaKit *)maptenna didPostNodeUpdate:(MTNode *)node {
    //    NSLog(@"%@: %@", NSStringFromSelector(_cmd), node.location);
    [self updateNodeOnMap:node];
}

- (void)maptenna:(MaptennaKit *)maptenna didReceiveNodeUpdate:(MTNode *)node {
    //    NSLog(@"%@: %@", NSStringFromSelector(_cmd), node.location);
    [self updateNodeOnMap:node];
    
    NSLog(@"**** RECEIVED FROM: (%f, %f)", node.location.coordinate.latitude, node.location.coordinate.longitude);
}

- (void)maptenna:(MaptennaKit *)maptenna didReceiveNodeUpdateRequest:(MTNodeRequest *)request {
    // Authenticate request (key exchange) and
    // reply with our node's location
    NSLog(@"Incoming request: %@", request);
    
    [[MaptennaKit shared] updateDeviceLocationForGID:request.senderGID block:^(NSError * _Nullable error) {
        if (error) return;
    }];
}

# pragma mark - GTPairingHandlerProtocol

- (void)updateState:(GTConnectionState)state {
    switch (state) {
        case BluetoothOff:
            [self showAlertWithTitle:@"Maptenna" message:@"Turn on Bluetooth to begin scanning for devices."];
            break;
        case Connecting:
            
            break;
        case Connected: {
            dispatch_async(dispatch_get_main_queue(), ^{
                self.connectBarButton.enabled = YES;
            });
            
            [self setGID];
            
            // Device connected, see who's around the area. Preferably once
            // until a manual refresh.
            // [[MaptennaKit shared] requestNearbyNodesUpdate:nil];
        }
            break;
        default:
            break;
    }
}

# pragma mark - Helpers

- (void)showAlertWithTitle:(NSString *)title message:(NSString *)message {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Dismiss" style:UIAlertActionStyleCancel handler:nil];
    [alertController addAction:cancel];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)updateDeviceInformation {
    [[GTCommandCenter shared] sendGetSystemInfoOnSuccess:^(SystemInfoResponseData *response) {
        //        self.deviceDictionary[@"Battery"] = [NSString stringWithFormat:@"%.f%%", response.batteryLevel.floatValue / 100.f];
        //        self.deviceDictionary[@"Firmware"] = [NSString stringWithFormat:@"%.2f", response.firmwareVersion];
        //        self.deviceDictionary[@"Serial"] = response.goTennaSerialNumber;
    } onError:^(NSError *error) {
        NSLog(@"Error: %@", error);
    }];
}

- (void)updateStatusLabel:(NSString *)status {
    if (!status) return;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.nodeInformationLabel.text = status;
    });
}

# pragma mark - View

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.mapNodes = [NSMutableArray array];
    
    self.mapView = (MGLMapView *)self.view;
    self.mapView.delegate = self;
    
    [[MaptennaKit shared] setDelegate:self];
    
    [[GTPairingManager shared] setPairingHandler:self];
    [[GTPairingManager shared] clearSavedScannedDevice];
    [[GTPairingManager shared] initiateScanningConnect];
    
    // Debug
    UIBarButtonItem *fetchButton = [[UIBarButtonItem alloc] initWithTitle:@"Fetch" style:UIBarButtonItemStylePlain target:self action:@selector(debugFetch)];
    self.navigationItem.leftBarButtonItems = @[fetchButton];
}

- (void)debugFetch {
    // Push
    // MTNode *node = [MTNode currentNode];
    // [self updateNodeOnMap:node];
    
    [[MaptennaKit shared] requestNearbyNodesUpdate:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
