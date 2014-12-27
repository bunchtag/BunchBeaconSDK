//
//  BNCHInternalDefinitions.h
//  BunchBeaconSDK
//
//  Version : 1.1.0
//  Created by Igor Parfenov on 01.01.14.
//  Copyright (c) 2014 RnD Lab. All rights reserved.
//


#import "NSLog2.h"


#ifdef CONFIG_BUNCH
//обычный банч
#define _bunchBeaconProximityNSUUIDs    [[NSUUID alloc] initWithUUIDString:@"16e913b6-6eb9-4869-a1fc-3ac5ceb58aee"]
#define _bunchBeaconProximityUUIDs      [CBUUID UUIDWithString:@"16e913b6-6eb9-4869-a1fc-3ac5ceb58aee"]

//зашифрованный банч
#define _bunchSecuredBeaconProximityNSUUIDs    [[NSUUID alloc] initWithUUIDString:@"845fdd77-1670-44da-ba63-3f24986dc821"]
#define _bunchSecuredBeaconProximityUUIDs      [CBUUID UUIDWithString:@"845fdd77-1670-44da-ba63-3f24986dc821"]
#endif

#ifdef CONFIG_BORODICH
//обычный банч
#define _bunchBeaconProximityNSUUIDs    [[NSUUID alloc] initWithUUIDString:@"16e913b6-6eb9-4869-a1fc-3ac5ceb58aee"]
#define _bunchBeaconProximityUUIDs      [CBUUID UUIDWithString:@"16e913b6-6eb9-4869-a1fc-3ac5ceb58aee"]

//зашифрованный банч
#define _bunchSecuredBeaconProximityNSUUIDs    [[NSUUID alloc] initWithUUIDString:@"b19b3a86-b0c7-4071-b175-dfc5a31fd3c3"]
#define _bunchSecuredBeaconProximityUUIDs      [CBUUID UUIDWithString:@"b19b3a86-b0c7-4071-b175-dfc5a31fd3c3"]
#endif


//суффикс для зашифрованного банча
#define _bunchSecuredBeaconSuffix   @"30b67069-1c56-4afe-8b4f-a644f26af9c3"
#define _bunchBeaconSuffix          @"8f8c9243-5887-4d9e-bd8d-94b0880621d1"
#define _bunchSecuredSpecialSuffix  @"823fefd1-a909-4658-b4be-07f2ef6b3726"
#define _bunchSimpleSpecialSuffix   @"6d445f09-84c3-4f46-b5c1-ed54475227bb"
#define _bunchSuffixLength          (37)

//BLE банч для установки настроек
#define _bunchUUIDs                     [CBUUID UUIDWithString:@"c2d28fcd-8cbf-4986-8f79-5db2987ff3b0"]

//отдельные сервисы BLE банча
#define _bunchProximityUUID             [CBUUID UUIDWithString:@"74f0"]
#define _bunchMajorUUID                 [CBUUID UUIDWithString:@"74f1"]
#define _bunchMinorUUID                 [CBUUID UUIDWithString:@"74f2"]
#define _bunchMeasuredPowerUUID         [CBUUID UUIDWithString:@"74f3"]
#define _bunchAdvIntUUID                [CBUUID UUIDWithString:@"74f4"]
#define _bunchTxPowerUUID               [CBUUID UUIDWithString:@"74f5"]
#define _bunchFirmwareUUID              [CBUUID UUIDWithString:@"74f6"]
#define _bunchHarwareUUID               [CBUUID UUIDWithString:@"74f7"]
#define _bunchMacUUID                   [CBUUID UUIDWithString:@"74f8"]
#define _bunchBunchTypeUUID             [CBUUID UUIDWithString:@"74f9"]
#define _bunchBatteryServUUID           [CBUUID UUIDWithString:@"180f"]
#define _bunchBatteryCharUUID           [CBUUID UUIDWithString:@"2a19"]

#define _maintainanceTimerTimeout       (30)
#define _rangingAndMonitoringPeriodicTasksTimerInterval   (1)
#define _outOfTheRegionTimerInterval   (30)

typedef enum : char
{
    BNCHBunchRegionUnknown    = 0,
    BNCHBunchRegionSimple     = 1,
    BNCHBunchRegionSecured    = 2,
    BNCHBunchRegionForRangingSecuredBeacon    = 3,
    BNCHBunchRegionForRangingSimpleBeacon    = 4,
} BNCHRegionExtendedType;

