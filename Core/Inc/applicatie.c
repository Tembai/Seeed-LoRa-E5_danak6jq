/*
 * sensor_app.c
 *
 *  Created on: 1 mrt. 2022
 *      Author: OSchutter
 */


#include "applicatie.h"
#include "sys_app.h"
#include "i2c.h"
#include "stm32wlxx_hal.h"
#include "stdint.h"
#include "stdlib.h"

#ifdef LPS22HH
#include <string.h>
#include <stdio.h>
//#include <stm32wlxx_hal_i2c.c>
#endif



//const char* Readout(){
////	char *ret="tESt";
////	return ret;
//	return "iets";
//}


//const char* Readout(){
//	return "i";
//}


float Sensor_read(){
	float pressure;
	pressure = 4.0;

	return pressure;
}



void Sensor_Init(void){


	  APP_LOG(TS_OFF, VLEVEL_M, "Sensor_Init------------------------\r\n")

		/*
	  while(1){
	  I2C_scan();
	  HAL_Delay(5000);
	  }
//	  platform_read();
 */

		lps33hw_ctx_t dev_ctx; /** xxxxxxx is the used part number **/
		dev_ctx.write_reg = platform_write;
		dev_ctx.read_reg = platform_read;

	return;
}

int32_t Sensor_Data(void){
	int data = 45;

//	I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout



//	APP_LOG(TS_OFF, VLEVEL_M, "Is sensor klaar om te communiceren?",HAL_I2C_IsDeviceReady(I2C_HandleTypeDef &hi2c1, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout));
//	APP_LOG(TS_OFF, VLEVEL_M, "Sensor_Data--------------------------\r\n");



    /* Initialize platform specific hardware */

//    platform_init();

    /* Wait sensor boot time */

//    platform_delay(BOOT_TIME);


	//	APP_LOG(TS_OFF, VLEVEL_M, "\r\n");

//	stmdev_ctx_t dev_ctx;
//    lps22hh_reg_t reg;
//
//    /* Initialize mems driver interface */
//    dev_ctx.write_reg = platform_write;
//    dev_ctx.read_reg = platform_read;
//    dev_ctx.handle = &SENSOR_BUS;
//
//    /* Initialize platform specific hardware */
//    platform_init();
//    HAL_Delay(5);
//    /* Check device ID */
//    whoamI = 0;
//    lps22hh_device_id_get(&dev_ctx, &whoamI);
//    if ( whoamI != LPS22HH_ID )
//        while (1){APP_LOG(TS_OFF, VLEVEL_M, "ID klopt niet, Who Am I:%x\r\n",whoamI);
//        } /*manage here device not found */
//    else{
//    	while (1){APP_LOG(TS_OFF, VLEVEL_M, "ID klopt!!!!!!!\r\n");};
//    }

	return data;
}











void I2C_scan(void){
	//https://deepbluembedded.com/stm32-i2c-scanner-hal-code-example/
	  uint8_t Buffer[25] = {0};
	  uint8_t Space[] = "-";
	  uint8_t StartMSG[] = "Starting I2C Scanning: \r\n";
	  uint8_t EndMSG[] = "Done! \r\n\r\n";
	  uint8_t i = 0, ret;

	  /*-[ I2C Bus Scanning ]-*/
	      APP_LOG(TS_OFF, VLEVEL_M, StartMSG);
	      for(i=1; i<128; i++)
	      {
	          ret = HAL_I2C_IsDeviceReady(&hi2c2, (uint16_t)(i<<1), 6, 25);
	          if (ret != HAL_OK) /* No ACK Received At That Address */
	          {
	              APP_LOG(TS_OFF, VLEVEL_M, Space);
	          }
	          else if(ret == HAL_OK)
	          {
	              APP_LOG(TS_OFF, VLEVEL_M, Buffer,"\n");
	          }
              APP_LOG(TS_OFF, VLEVEL_M, Buffer,"\n");
	      }
	      APP_LOG(TS_OFF, VLEVEL_M, EndMSG);
	      /*--[ Scanning Done ]--*/
}


void I2C_id(void){


  	static const uint8_t addr_write = 0x5D << 1;
  	static const uint8_t addr_read = (0x5D << 1)+1;	// address LPS33HW with read bit
  	static const uint8_t WhoAmI = 0x0F;				// register
    HAL_StatusTypeDef ret;
    uint8_t buf[3];


    buf[0] = WhoAmI;
    buf[1] = 0;
    buf[2] = 0;


    ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, buf, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE
    if ( ret != HAL_OK ) {
  	  APP_LOG(TS_OFF, VLEVEL_M, "Transmit doet het niet\n");
    }
    else{
  	  ret=HAL_I2C_Master_Receive(&hi2c2, addr_read, buf, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE
  	  if ( ret != HAL_OK ) {
  		  APP_LOG(TS_OFF, VLEVEL_M, "Receive doet het niet\n");
  	  }
  	  }

	  APP_LOG(TS_OFF, VLEVEL_M, "id: %X\n",buf[0]);

	 return 0;
}


int32_t platform_write(void *handle, uint8_t Reg, const uint8_t *Bufp, uint16_t len){

    ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, buf, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE
	return HAL_OK;
}



int32_t platform_read(void *handle, uint8_t Reg, uint8_t *Bufp, uint16_t len){

	return 0;
}

