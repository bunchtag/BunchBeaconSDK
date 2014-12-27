//
//  BNCHBunchManager.h
//  BunchSDK
//
//  Version : 1.1.0
//  Created by Igor Parfenov on 01/01/14.
//  Copyright (c) 2014 Bunch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BNCHBunchRegion.h"
#import "BNCHMutableBunch.h"

@class BNCHBunchManager;



/**
 
 BNCHBunchManagerDelegate определяет delegate-протокол для обработки событий, отправляемых по радио-соединению объекту BNCHMutableBunch. Установленное соединение может разорваться по внешним причинам, поэтому метод didDisconnectBunch: может быть вызван без какой-либо предварительной команды.

 */

@protocol BNCHBunchManagerDelegate <NSObject>

@optional

/**
 * Delegate-метод, который вызывается во время поиска Bunch-ей с заданными характеристиками.
 * Метод позволяет получить NSArray всех найденных Bunch-ей, представленный объектами класса BNCHBunch.
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param bunches все найденные вокруг телефона Bunch, представленные объектами класса BNCHBunch
 * @param region Bunch-регион
 *
 * @return void
 */
- (void)bunchManager:(BNCHBunchManager *)manager didRangeBunches:(NSArray *)bunches inRegion:(BNCHBunchRegion *)region;


/**
 * Delegate-метод, который вызывается во время возникновения ошибки при поиске Bunch-ей с заданными характеристиками.
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param region Bunch-регион
 * @param error информация о возникшей ошибке
 *
 * @return void
 */
-(void)bunchManager:(BNCHBunchManager *)manager rangingBunchesDidFailForRegion:(BNCHBunchRegion *)region withError:(NSError *)error;


/**
 * Delegate-метод, который вызывается в момент, когда телефон зашел в заданный регион во время его мониторинга
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)bunchManager:(BNCHBunchManager *)manager didEnterRegion:(BNCHBunchRegion *)region;

/**
 * Delegate-метод, который вызывается в момент, когда телефон вышел из заданного региона во время мониторинга
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)bunchManager:(BNCHBunchManager *)manager didExitRegion:(BNCHBunchRegion *)region;

/**
 * Delegate-метод, который вызывается во время возникновения ошибки при мониторинге определенного района.
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param region Bunch-регион
 * @param error информация о возникшей ошибке
 *
 * @return void
 */
-(void)bunchManager:(BNCHBunchManager *)manager monitoringDidFailForRegion:(BNCHBunchRegion *)region withError:(NSError *)error;

/**
 * Delegate-метод, который вызывается во время определения состояния телефона относительно региона, переданного в requestStateForRegion:
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param state состояние Bunch-региона
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)bunchManager:(BNCHBunchManager *)manager didDetermineState:(CLRegionState)state
             forRegion:(BNCHBunchRegion *)region;


/**
 * Delegate-метод вызывается, когда был найден Bunch рядом с устройством пользователя с возможностью установки соединения с ним
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param bunch ссылка на объект BNCHMutableBunch с которым можно установить соединение
 * @param region Bunch-регион
 *
 * @return void
 */
- (void)bunchManager:(BNCHBunchManager *)manager didMaintainBunch:(BNCHMutableBunch *)bunch inRegion:(BNCHBunchRegion *)region;

/**
 * Delegate-метод вызывается при успешном соединении с объектом BNCHMutableBunch.
 
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param bunch ссылка на объект BNCHMutableBunch с которым было установлено соединение
 *
 * @return void
 */
- (void)bunchManager:(BNCHBunchManager *)manager didConnectBunch:(BNCHMutableBunch *)bunch;

/**
 * Delegate-метод вызывается при возникновении ошибки при соединении с объектом BNCHMutableBunch.
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param bunch ссылка на объект BNCHMutableBunch, соединение с которым не было установлено
 * @param error описание ошибки
 *
 * @return void
 */
- (void)bunchManager:(BNCHBunchManager *)manager didFailToConnectBunch:(BNCHMutableBunch *)bunch error:(NSError *)error;

/**
 * Delegate-метод вызывается при обрыве соединения с объектом BNCHBunch.
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param bunch ссылка на объект BNCHMutableBunch соединение с которым было разорвано
 * @param error описание ошибки
 *
 * @return void
 */
- (void)bunchManager:(BNCHBunchManager *)manager didDisconnectBunch:(BNCHMutableBunch *)bunch error:(NSError *)error;

/**
 * Delegate-метод вызывается в ответ на вызов метода requestContentForRegion: в момент когда получены ссылки на контент, привязанный к Bunch
 *
 * @param manager ссылка на объект BNCHBunchManager - менеджер соединений, от которого пришло сообщение
 * @param data ссылка на контент, привязанный к Bunch
 * @param region Bunch-регион
 * @param error описание ошибки. Если команда выполнена успешно, то nil
 *
 * @return void
 */
- (void)bunchManager:(BNCHBunchManager *)manager didReceiveContent:(NSData *)data forRegion:(BNCHBunchRegion*)region withError:(NSError*)error;


@end



/**
 
 Класс BNCHBunchManager определяет интерфейс для управления Bunch. Объект этого класса надо использовать для поиска Bunch вокруг и для определения регионов мониторинг за которыми необходимо установить.
 
 */

@interface BNCHBunchManager : NSObject

/// @name Delegate

@property (nonatomic, weak) id <BNCHBunchManagerDelegate> delegate;

/**
 список регионов, в которых мониторим Bunch
 */
@property(readonly, nonatomic) NSSet *monitoredRegions;

/**
 список регионов, в которых ранжируем Bunch
 */
@property(readonly, nonatomic) NSSet *rangedRegions;

/**
 Позволяет избавиться от добавления в результаты поиска Bunch с неопределенным состоянием (proximity == 0). Значение по умолчанию - NO.
 */
@property (nonatomic) BOOL avoidUnknownStateBunches;


/// @name Методы мониторинга региона и поиска Bunch-ей, основанные на CoreLocation

/**
 * Поиск всех Bunch-ей, которые находятся вокруг телефона пользователя.
 * Используется delegate-метод bunchManager:didRangeBunches:inRegion: чтобы получить найденные Bunch.
 * Возвращаемый массив NSArray содержит объекты класса BNCHBunch
 *
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)startRangingBunchesInRegion:(BNCHBunchRegion*)region;

/**
 * Прекращение поиска Bunch-ей.
 *
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)stopRangingBunchesInRegion:(BNCHBunchRegion*)region;


/**
 * Начало мониторинга определенного региона.
 * Вы должны вызывать этот метод для каждого региона, который хотите отслеживать. Регион, который вы зададите через этот метод разделяется между всеми Bunch-менеджерами в вашем приложении.
 * Каждый раз когда вы заходите или выходите из региона вызывается delegate-метод bunchManager:didEnterRegtion: или bunchManager:didExitRegion:
 * При возникновении ошибки вызывается delegate-метод bunchManager:monitoringDidFailForRegion:error
 * Приложение может зарегистрировать до 20 регионов в одно и тоже время.
 *
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)startMonitoringForRegion:(BNCHBunchRegion*)region;


/**
 * Прекращение мониторинга определенного региона.
 *
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)stopMonitoringForRegion:(BNCHBunchRegion *)region;

/**
 * Метод позволяет узнать состояние (положение телефона пользователя)относительно для указанного региона
 *
 * @param region Bunch-регион
 *
 * @return void
 */
-(void)requestStateForRegion:(BNCHBunchRegion *)region;

/// @name Методы, основанные на CoreBlueTooth

/**
 * Метод вызывается для получения всех Bunch вокруг телефона пользователя для последующей их настройки (установления соединения с Bunch)
 * Ищутся те Bunch, которые находятся в регионе BNCHBunchRegion
 * Установка соединения необходима для того, чтобы прочитать параметры с Bunch или для того, чтобы поменять такие параметры
 * как: major, minor, measuredPower, txPower, advInterval и т.п.
 *
 * @param region Bunch-регион в котором ищутся Bunch для настройки
 *
 * @return void
 */
-(void)startMaintainingBunchesInRegion:(BNCHBunchRegion *)region;

/**
 * Метод вызывается для остановки поиска Bunch для конкретного региона
 *
 * @param region Bunch-регион в котором надо прекратить поиск Bunch для настройки
 *
 * @return void
 */
-(void)stopMaintainingBunchesInRegion:(BNCHBunchRegion *)region;

/**
 * Установка соединения с Bunch, представленным объектом класса BNCHMutableBunch, по Bluetooth.
 * Установка соединения необходима для того, чтобы поменять такие параметры как: major, minor, measuredPower, txPower и advInterval.
 *
 * @param bunch объект класса BNCHMutableBunch с которым необходимо установить соединение
 *
 * @return void
 */
- (void)connectBunch:(BNCHMutableBunch *)bunch;

/**
 * Отключение от конкретного Bunch.
 *
 * @param bunch объект класса BNCHMutableBunch с которым необходимо разорвать соединение
 *
 * @return void
 */
- (void)cancelBunchConnection:(BNCHMutableBunch *)bunch;


/**
 * Получение контента, привязанного к региону в облаке Bunch. В ответ асинхронно вызывается bunchManager:didReceiveContent:forRegion:withError:
 *
 * @param region Bunch-регион
 *
 * @return void
 */
- (void)requestContentForRegion:(BNCHBunchRegion *)region;


@end

