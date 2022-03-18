/*
 * sensor_app.h
 *
 *  Created on: 1 mrt. 2022
 *      Author: OSchutter
 */

#ifndef SENSOR_APP_H_
#define SENSOR_APP_H_
#endif /* APPLICATION_USER_LORAWAN_APP_SENSOR_APP_H_ */

#include <stdint.h>
#include "i2c.h"


//const char* Readout();



float Sensor_read();


void Sensor_Init(void);

int32_t Sensor_Data(void);

void I2C_scan(void);
//static int32_t test_read();
void I2C_id(void);


static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);
//static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
//                             uint16_t len);
static int32_t platform_read(void);
//static void tx_com( uint8_t *tx_buffer, uint16_t len );
//static void platform_delay(uint32_t ms);
static void platform_init(void);



//#define LPS22HH
#define BMP390



//===============================================

#ifdef LPS22HH
#define SENSOR_BUS hi2c1
#define HAL_I2C_MODULE_ENABLED

#define    BOOT_TIME        5 //ms
#define TX_BUF_DIM          1000

/* Private variables ---------------------------------------------------------*/
static uint32_t data_raw_pressure;
static int16_t data_raw_temperature;
static float pressure_hPa;
static float temperature_degC;
static uint8_t whoamI, rst;
static uint8_t tx_buffer[TX_BUF_DIM];

#endif


#ifdef BMP390
#define SENSOR_BUS hi2c2
#define HAL_I2C_MODULE_ENABLED
//I2C_HandleTypeDef hi2c2;
#endif

