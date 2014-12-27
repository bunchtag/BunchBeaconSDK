//
//  BNCHMutableBunch.h
//  BunchBeaconSDK
//
//  Version : 1.1.0
//  Created by Igor Parfenov on 01/01/14.
//  Copyright (c) 2014 Bunch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BNCHBunchDefinitions.h"
#import "BNCHBunch.h"


@class BNCHMutableBunch;
////////////////////////////////////////////////////////////////////
// Bunch delegate-протокол


/**
 
 BNCHBunchDelegate определяет delegate-протокол для обработки асинхронных команд чтения и записи значений параметров, передаваемых по радио-интерфейсу.
 
 */
@protocol BNCHMutableBunchDelegate <NSObject>

/**
 * Delegate-метод вызывается при получении по радио-интерфейсу уведомления от объекта BNCHMutableBunch со значением параметра parameter.
 *
 * @param bunch ссылка на объект BNCHMutableBunch от которого были получены параметры
 * @param parameter параметр, который был изменен и значение которого можно получить, прочитав соответствующее свойство BNCHMutableBunch
 * @param error описание ошибки
 *
 * @return void
 *
 * Описание
 * Метод вызывается асинхронно через какое-то время после вызова команды readParameterFromBunch: в тот момент, когда система получает
 * уведомление по радио-интерфейсу от BNCHMutableBunch со значением параметра, которое мы хотели прочитать.
 * Значение параметра, при этом, можно получить, прочитав значение соответствующего свойства объекта BNCHMutableBunch.
 * Метод вызывается через какое-то время после установления соединения с BNCHMutableBunch. Это связано с тем, что после установления
 * соединения с BNCHMutableBunch запрашиваются значения всех свойств BNCHMutableBunch, которые передаются по радио-интерфейсу.
 *
 */
- (void)bunch:(BNCHMutableBunch *)bunch didUpdateValueForParameter:(BNCHParameterType)parameter error:(NSError *)error;

/**
 * Delegate-метод вызывается при получении уведомления от объекта BNCHMutableBunch о том, что значение было записано по радио-интерфейсу на BNCHMutableBunch.
 *
 * @param bunch ссылка на объект BNCHMutableBunch на который был записан параметр
 * @param parameter параметр, который был записан
 * @param error описание ошибки
 *
 * @return void
 *
 * Описание
 * Метод вызывается асинхронно через какое-то время после вызова какой-либо команды записи на BNCHMutableBunch.
 * Параметр parameter говорит о том, какое конкретно свойство было записано на BNCHMutableBunch. Само значение свойства в объекте
 * BNCHMutableBunch не изменяется и остается старым до тех пор, пока не будет вызвана соответствующая команда readParameterFromBunch:
 *
 */
- (void)bunch:(BNCHMutableBunch *)bunch didWriteValueForParameter:(BNCHParameterType)parameter error:(NSError *)error;


@end

/**
 
 Объект класса BNCHMutableBunch представляет собой Bunch, который был найден рядом с мобильным устройством пользователя. Вы не можете создать объект BNCHMutableBunch напрямую. Объект класса BNCHBunchManager передает найденные им объекты класса BNCHMutableBunch, в соответствующий метод delegate-протокола. Вы можете использовать информацию в объектах класса BNCHMutableBunch для настройки параметров работы конкретного Bunch, который был найден.
 
 */

@interface BNCHMutableBunch : BNCHBunch

/// @name Delegate

@property (nonatomic)           id <BNCHMutableBunchDelegate>  delegate;

/// @name Cвойства, доступные сразу после получения объекта BNCHMutableBunch

/**
 *
 *  Ссылка на CBPeripheral - объект, представляющий низкоуровневый доступ к Bunch по Bluetooth-интерфейсу
 *
 */
@property (nonatomic, strong, readonly)   CBPeripheral* peripheral;

/**
 *    Флаг, показывающий статус соединения
 */
@property (nonatomic, readonly)   BOOL                  isConnected;


/// @name Cвойства, обновляемые после установления соединения с Bunch

/**
 *
 *  MAC-адрес, прошитый в Bunch.
 *
 *  У каждого устройства свой уникальный MAC-адрес, вне зависимости от того, какой major или minor ему присвоены. Т.е. у двух устройств обладающих одинаковыми major и minor MAC-адреса будут отличаться.
 *  Значение доступно после устновки соединения с Bunch.
 *
 */
@property (nonatomic, strong, readonly)   NSString*     macAddress;

/**
 *
 * Значение RSSI, полученное на расстоянии 1 метра от Bunch. Это значение используется для калибровки.
 * Значение доступно после устновки соединения с Bunch.
 *
 */
@property (nonatomic, strong, readonly)   NSNumber*     measuredPower;

/**
 *    Мощность передающего устройства, установленного на Bunch. Значение доступно после устновки соединения с Bunch. Доступные значения представлены в BNCHBunchPower.
 */
@property (nonatomic, strong, readonly)   NSNumber*     txPower;

/**
 *    Период с которым Bunch отправляет Advertising-сообщения. Измеряется в миллисекундах. Чем чаще Bunch отправляет Advertising-сообщения тем быстрее реагирует на них телефон пользователя, чем реже, тем, соответсвенно, медленнее. Это значение обратнопропорционально потреблению батарейки Bunch-ем. Чем чаще Bunch отправляет Advertising-сообщения тем сильнее тратится батарейка. Оптимальное значение находится в диапазоне 1000-2000 миллисекунды. Значение доступно после устновки соединения с Bunch.
 */
@property (nonatomic, strong, readonly)   NSNumber*     advInterval;

/**
 *  Уровень заряда батареи в процентах.
 *
 *  Значение меняется от 100 до 0 процентов. Значение доступно после устновки соединения с Bunch.
 *
 */
@property (nonatomic, strong, readonly)   NSNumber*     batteryLevel;

/**
 *    Версия аппаратного обеспечения Bunch. Значение доступно после устновки соединения с Bunch.
 */
@property (nonatomic, strong, readonly)   NSString*     hardwareVersion;

/**
 *    Версия программного обеспечения Bunch. Значение доступно после устновки соединения с Bunch.
 */
@property (nonatomic, strong, readonly)   NSString*     firmwareVersion;

/// @name Методы для считывания конфигурации Bunch

/**
 * Чтение параметров
 *
 * @param parameter параметр, который надо прочитать
 *
 * @return void
 *
 * Описание
 * Последовательность действий для чтения параметра следующая:
 * - вызывается метод readParameterFromBunch: в который передается имя параметра для считывания
 * - после считывания параметра по радио-интерфейсу асинхронно вызывается delegate-метод didUpdateValueForParameter:
 * - значение параметра можно получить в соответствующем свойстве BNCHMutableBunch
 *
 */
- (void)readParameterFromBunch:(BNCHParameterType)parameter;


/// @name Методы для записи конфигурации Bunch

/**
 * Запись старшего значения. Требуется предварительное установление соединения с Bunch.
 *
 * @param major старшее значение
 *
 * @return void
 *
 * Описание
 * После записи параметра вызывается delegate-метод didWriteValueForParameter:
 *
 */
- (void)writeMajor:(unsigned short)major;

/**
 * Запись младшего значения. Требуется предварительное установление соединения с Bunch.
 *
 * @param minor младшее значение
 *
 * @return void
 *
 * Описание
 * После записи параметра вызывается delegate-метод didWriteValueForParameter:
 *
 */
- (void)writeMinor:(unsigned short)minor;


/**
 * Запись "эталонной" мощности конкретного Bunch. Это значение, показывает мощность сигнала
 * на расстоянии один метр от Bunch.
 *
 * @param power значение "эталонной" мощности
 *
 * @return void
 *
 * Описание
 * Значение параметра используется для определения расстояния до Bunch. Зная значение "эталонной"
 * мощности сигнала для Bunch на расстоянии один метр, система проводит расчет расстояния до Bunch
 * на основании оригинального текущео значения сигнала, передаваемого в параметре txPower.
 * Требуется предварительное установление соединения с Bunch.
 * После записи параметра вызывается delegate-метод didWriteValueForParameter:
 *
 *
 *
 */
- (void)writeMeasuredPower:(char)power;

/**
 * Запись advInterval (период с которым Bunch отправляет Advertising-сообщения). Требуется предварительное установление соединения с Bunch.
 *
 * @param interval значение интервала
 *
 * @return void
 *
 * Описание
 * После записи параметра вызывается delegate-метод didWriteValueForParameter:
 *
 */
- (void)writeAdvInterval:(unsigned short)interval;


/**
 * Запись мощности передатчика. Требуется предварительное установление соединения с Bunch.
 *
 * @param power значение мощности
 *
 * @return void
 *
 * Описание
 * После записи параметра вызывается delegate-метод didWriteValueForParameter:
 *
 */
- (void)writePower:(BNCHBunchPower)power;

/**
 * Запись типа Bunch (обычный iBeacon или защищенный iBeacon)
 *
 * @param type BNCHBunchType:     BNCHBunchTypeSimple или BNCHBunchTypeSecured
 *
 * @return void
 *
 * Описание
 * После записи параметра вызывается delegate-метод didWriteValueForParameter:
 *
 */
- (void)writeBunchType:(BNCHBunchType)type;


@end

