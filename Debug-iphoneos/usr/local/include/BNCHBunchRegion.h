//
//  BNCHBunchRegion.h
//  BunchSDK
//
//  Version : 1.1.0
//  Created by Igor Parfenov on 01/01/14.
//  Copyright (c) 2014 Bunch. All rights reserved.
//



#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BNCHBunchDefinitions.h"


/*
 *  BNCHBunchMajorValue
 *
 *    Тип, представляющий старшее значение для Bunch
 *
 */
typedef uint16_t    BNCHBunchMajorValue;

/*
 *  BNCHBunchMinorValue
 *
 *    Тип, представляющий младшее значение для Bunch
 *
 */
typedef uint16_t    BNCHBunchMinorValue;


/**
 
 Объект класса BNCHBunchRegion представляет Bunch-регион определенный близостью устройства пользователя к Bunch. Bunch-регион ищет Bunch-и, параметры которых соответствуют заданным в регионе. Когда такое устройство найдено, срабатывает соответствующий триггер и соответсвующее сообщение доставляется.
 
 Вы можете отслеживать Bunch-регионы двумя способами. Чтобы получить уведомление о том, что пользователь зашел или вышел из какого-либо Bunch-региона необходимо использовать метод startMonitoringForRegion: Если соответствующие Bunch-и находятся в области видимости, то вы можете отслеживать изменение расстояния до них, используя метод startRangingBunchesInRegion:
 
 */
@interface BNCHBunchRegion : CLBeaconRegion

/**
 *
 *  Тип Bunch-региона (обычный реигон или защищенный регион)
 *  BNCHRegionTypeSimple - это обычный регион
 *  BNCHRegionTypeSecured - это защищенный регион
 *
 */
@property (nonatomic, readonly)   BNCHRegionType               regionType;


/**
 * Инициализация Bunch-региона. Старшее и младшее значение игнорируется.
 *
 * @param identifier уникальный внутри приложения идентификатор для этого региона. Должен отличаться от nil
 * @return инициализированный BNCHBunchRegion объект
 **/
- (id)initRegionWithIdentifier:(NSString *)identifier;

/**
 * Инициализация Bunch-региона вместе со старшим значением. Младшее значение игнорируется.
 *
 * @param major старшее значение для Bunch-региона
 * @param identifier уникальный внутри приложения идентификатор для этого региона. Должен отличаться от nil
 * @return инициализированный BNCHBunchRegion объект
 **/
- (id)initRegionWithMajor:(BNCHBunchMajorValue)major identifier:(NSString *)identifier;

/**
 * Инициализация Bunch-региона вместе со старшим и младшим значениями.
 *
 * @param major старшее значение для Bunch-региона
 * @param minor младшее значение для Bunch-региона
 * @param identifier уникальный внутри приложения идентификатор для этого региона. Должен отличаться от nil
 * @return инициализированный BNCHBunchRegion объект
 **/
- (id)initRegionWithMajor:(BNCHBunchMajorValue)major minor:(BNCHBunchMinorValue)minor identifier:(NSString *)identifier;


@end
