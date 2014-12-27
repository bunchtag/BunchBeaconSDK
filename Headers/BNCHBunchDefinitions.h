//
//  BNCHBunchDefinitions.h
//  BunchSDK
//
//  Version : 1.1.0
//  Created by Igor Parfenov on 01/01/14.
//  Copyright (c) 2014 Bunch. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * \defgroup BNCHBunchPower BNCHBunchPower
 Значение мощности передатчика Bunch, которое можно установить через беспроводной интерфейс
 @{
 */
typedef enum : char
{
    BNCHBunchPowerMinus23dBm    = 0,
    BNCHBunchPowerMinus6dBm     = 1,
    BNCHBunchPower0dBm          = 2,
    BNCHBunchPower4dBm          = 3,
} BNCHBunchPower;
/** @} */

/**
 * \defgroup BNCHParameterType BNCHParameterType
 Тип параметра, хранимого на Bunch
 @{
 */
typedef enum : char
{
    BNCHParameterUnknown = -1,
    BNCHParameterProximity,
    BNCHParameterMajor,
    BNCHParameterMinor,
    BNCHParameterMeasuredPower,
    BNCHParameterAdvInt,
    BNCHParameterTxPower,
    BNCHParameterFirmware,
    BNCHParameterHardware,
    BNCHParameterBattery,
    BNCHParameterMacAddress,
    BNCHParameterBunchType
}BNCHParameterType;
/** @} */

/**
 * \defgroup BNCHRegionType BNCHRegionType
 Тип Bunch-региона (защищенный или обычный iBeacon)
 @{
 */
typedef enum : char
{
    BNCHRegionTypeSimple     = 0,
    BNCHRegionTypeSecured    = 1,
} BNCHRegionType;
/** @} */

/**
 * \defgroup BNCHBunchType BNCHBunchType
 Тип Bunch (защищенный или обычный iBeacon)
 @{
 */
typedef enum : char
{
    BNCHBunchTypeSimple     = 0,
    BNCHBunchTypeSecured    = 1,
} BNCHBunchType;
/** @} */


