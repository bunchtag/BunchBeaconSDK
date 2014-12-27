//
//  BNCHBunch.h
//  BunchSDK
//
//  Version : 1.1.0
//  Created by Igor Parfenov on 01/01/14.
//  Copyright (c) 2014 Bunch. All rights reserved.
//

/*! \mainpage Документация на BunchBeaconSDK
 *
 * \section intro_sec Описание содержимого SDK
 *
 * SDK состоит из библиотеки:
 *  
 *      libBunchBeaconSDK.a
 *
 * и пяти заголовочных файлов:
 *
 *    BNCHBunchManager.h
 *
 *    BNCHMutableBunch.h
 *
 *    BNCHBunch.h
 *
 *    BNCHBunchRegion.h
 *
 *    BNCHBunchDefinitions.h
 * 
 * Библиотека собрана в версиях Debug и Release для запуска на iOS устройствах или на симуляторе. Библиотеки лежат в четырех папках.
 * 
 * Библиотека для запуска на iOS-симуляторах лежит в папках:
 *
 *      Debug-iphonesimulator
 *      Release-iphonesimulator
 * Библиотека для запуска на iOS-устройствах лежит в папках:
 *
 *      Debug-iphoneos
 *      Release-iphoneos
 *
 * \section install_sec Порядок установки
 *
 * \subsection step1 Шаг 1. Добавление в проект библиотеки
 *
 * Необходимая версия библиотеки добавляется в проект. Для этого в Xcode надо выбрать соответствующий Target в разделе TARGETS далее перейти на закладку General и выбрать раздел Linked Frameworks and Libraries. Перетаскивание библиотеки в этот раздел добавляет ее в проект.
 *
 * \subsection step2 Шаг 2. Добавление в проект заголовочных файлов
 *
 * В разрабатываемый проект включаются перечисленные выше заголовочные файлы либо напрямую, либо путь к ним добавляется в соответствующем разделе Build Settings.
 *
 * \section guide_sec Самый простой способ заставить SDK работать
 *
 * Для того, чтобы запустить SDK сделайте следующие простые шаги:
 *
 * 1.	Cоздайте объект BNCHBunchManager
 * 
 *          BNCHBunchManager _bunchManager = [[BNCHBunchManager alloc]init];
 *
 * 2.	Установите правильный delegate:
 *
 *          [_bunchManager setDelegate:self];
 *
 * 3.	Инициализируйте регион, который вы ходите отслеживать:
 *
 *          BNCHBunchRegion *region = [[BNCHBunchRegion alloc]initRegionWithIdentifier:@"BunchSampleApp"];
 *          region.notifyEntryStateOnDisplay = YES;
 *          region.notifyOnEntry = YES;
 *          region.notifyOnExit = YES;
 *
 * 4.	Начните либо мониторить заданный регион, либо ранжировать Банчи, находящиеся в нем . Стандартный способ выглядит следующим образом: вы начинаете мониторить регион, т.е. отслеживаете события входа или выхода пользователя в/из региона. Если пользователь заходит в регион, то надо начать ранжирование Банчей в данном регионе (если это необходимо) для определения какой именно Банч находится ближе к пользователю. Когда приложение активно, мониторинг иногда работает с запаздываниями, что вызвано особенностями работы iOS с BLE-стеком, поэтому в активном состоянии рекомендуется наряду с мониторингом вызывать метод startRangingBunchesInRegion: сразу.
 *
 *          [_bunchManager startMonitoringForRegion:region];
 *          [_bunchManager startRangingBunchesInRegion:region];
 *
 * 5.	После выполнения указанных шагов будут вызываться delegate-методы:
 * 
 *          bunchManager:didDetermineState:forRegion:
 *          bunchManager:didEnterRegion:
 *          bunchManager:didExitRegion:
 *
 *      в зависимости от произошедшего события
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BNCHBunchDefinitions.h"

////////////////////////////////////////////////////////////////////
// Определение интерфейсов

/**
 
 Объект класса BNCHBunch представляет собой Bunch, который был найден рядом с мобильным устройством пользователя. Вы не можете создать объект BNCHBunch напрямую. Объект класса BNCHBunchManager передает найденные им объекты класса BNCHBunch, в соответствующий метод delegate-протокола. Вы можете использовать информацию в объектах класса BNCHBunch для идентификации конкретного Bunch, который был найден.
 
 
 Класс BNCHBunch повторяет функциональность стандартного класса CLBeacon из CoreLocation Framework и расширяет его дополнительной функциональностью, которая недоступна через CLBeacon. Дополнительная функциональность доступна через объекты класса BNCHMutableBunch. Расширенная функциональность позволяет устанавливать соединение с Bunch для чтения и записи его основных характеристик.
 
 */

@interface BNCHBunch : NSObject

    
/// @name Общедоступные-свойства

/**
 *
 *  Неуникальное имя Bunch, создаваемое на основании major и minor
 *
 */
@property (nonatomic, strong, readonly)     NSString*               name;


/**
 *
 *  Proximity-идентификатор Bunch.
 *
 */
@property (nonatomic, strong, readonly)     CBUUID*                 proximityUUID;

/**
 *
 *  Cтаршее значение, ассоциированное с Bunch. Если старшее значение не указано, то его значение - nil.
 *
 */
@property (nonatomic, strong, readonly)     NSNumber*               major;

/**
 *
 *  Младшее значение, ассоциированное с Bunch. Если младшее значение не указано, то его значение - nil.
 *
 */
@property (nonatomic, strong, readonly)     NSNumber*               minor;


/**
 *
 *  Параметр показывает относительное расстояние до Bunch
 *
 *  Значение этого свойства дает общее представление об относительном расстоянии до Bunch. Это совойство можно использовать для идентификации тех Bunch-ей, которые ближе к пользователю, чем другие.
 */
@property (nonatomic, readonly)             CLProximity             proximity;

/**
 *
 *  Точность параметра proximity, измеряется в метрах.
 *
 *  Используйте это значение, чтобы отличать одни Bunch-и от других с одинаковыми значениями proximity. Не используйте это значение для точного определения местоположения Bunch. Точность может меняться в зависимости от помех в радио эфире. Отрицательное значение этого свойства говорит о том, что оно не может быть опередлено.
 */
@property (readonly, nonatomic, readonly)   CLLocationAccuracy       accuracy;


/**
 *
 *  Получаемая от конкретного Bunch сила сигнала в dB.
 *  Значение представляет собой среднее значение RSSI, собранных с момента последнего отчета Bunch.
 *
 */
@property (nonatomic, readonly)             NSInteger                rssi;

/**
 *
 *  Тип Bunch (обычный iBeacon или защищенный iBeacon)
 *  BNCHBunchTypeSimple - это обычный Bunch
 *  BNCHBunchTypeSecured - это защищенный Bunch
 *
 */
@property (nonatomic, strong, readonly)     NSNumber*                bunchType;



@end


