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


#define LPS33HW
//#define LPS22HH
//#define BMP390


//======================================================================================================
float Sensor_read();
void Sensor_Init(void);
int32_t Sensor_Data(void);

void I2C_scan(void);
//static int32_t test_read();
void I2C_id(void);
//======================================================================================================





#ifdef LPS33HW
static const uint8_t addr_write = 0x5D << 1;
static const uint8_t addr_read = (0x5D << 1)+1;	// address LPS33HW with read bit
int32_t platform_write(void *handle, uint8_t Reg, const uint8_t *Bufp, uint16_t len);
int32_t platform_read(void *handle, uint8_t Reg, uint8_t *Bufp, uint16_t len);
//static void platform_init(void);
void I2C_software_reset(void);



/* Private macro -------------------------------------------------------------*/
#define TX_BUF_DIM          1000
/* Private variables ---------------------------------------------------------*/
static uint32_t data_raw_pressure;
static int16_t data_raw_temperature;
static float pressure_hPa;
static float temperature_degC;
static uint8_t whoamI, rst;
static uint8_t tx_buffer[TX_BUF_DIM];

#endif



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

//===============================================

#ifdef BMP390
#define SENSOR_BUS hi2c2
#define HAL_I2C_MODULE_ENABLED
//I2C_HandleTypeDef hi2c2;
#endif

