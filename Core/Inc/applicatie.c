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

#ifdef LPS33HW
#include "lps33hw_reg.h"

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
//==========================================================================================
//		lps33hw_ctx_t dev_ctx; /** xxxxxxx is the used part number **/
//		dev_ctx.write_reg = platform_write;
//		dev_ctx.read_reg = platform_read;

	return;
}


int32_t Sensor_Data(void){


	APP_LOG(TS_OFF, VLEVEL_M, "Sensor_Data--------------------------\r\n");



    /* Initialize platform specific hardware */

//    platform_init();

    /* Wait sensor boot time */

//    platform_delay(BOOT_TIME);
	HAL_Delay(2000);


	//	APP_LOG(TS_OFF, VLEVEL_M, "\r\n");

	stmdev_ctx_t dev_ctx;

    /* Initialize mems driver interface */
    dev_ctx.write_reg = platform_write;
    dev_ctx.read_reg = platform_read;
    dev_ctx.handle = &hi2c2;
//
//    /* Initialize platform specific hardware */
//    platform_init();
//    HAL_Delay(5);
//    /* Check device ID */
    whoamI = 0;
    lps33hw_device_id_get(&dev_ctx, &whoamI);
	APP_LOG(TS_OFF, VLEVEL_M, "Sensor_Data -> WhoAmI: %x\r\n",whoamI);

//    APP_LOG(TS_OFF, VLEVEL_M, "Who Am I:%x\r\n",whoamI);


	lps33hw_reset_set(&dev_ctx, PROPERTY_ENABLE);
	do {
	lps33hw_reset_get(&dev_ctx, &rst);									// software reset
	} while (rst);

	/* Enable Block Data Update */
	  lps33hw_block_data_update_set(&dev_ctx, PROPERTY_ENABLE);			// BDU bit set
	  /* Set Output Data Rate */
	  lps33hw_data_rate_set(&dev_ctx, LPS33HW_POWER_DOWN);				// one-shot mode enabled

	  /* Read samples in polling mode (no int) */
	  while (1) {
		HAL_Delay(1000);
		lps33hw_low_power_set(&dev_ctx, PROPERTY_DISABLE);				// Low-current mode disabled

		lps33hw_one_shoot_trigger_set(&dev_ctx, PROPERTY_ENABLE);		// one-shot mode triggered
/*
//	     Read output only if new value is available
	    lps33hw_reg_t reg;
	    lps33hw_read_reg(&dev_ctx, LPS33HW_STATUS, (uint8_t *)&reg, 1);

	    if (reg.status.p_da) {
	      memset(&data_raw_pressure, 0x00, sizeof(int32_t));
	      lps33hw_pressure_raw_get(&dev_ctx, &data_raw_pressure);
	      pressure_hPa = lps33hw_from_lsb_to_hpa(data_raw_pressure);
//	      APP_LOG(TS_OFF, VLEVEL_M, "pressure [hPa]:%6.2f\r\n", pressure_hPa);
	      APP_LOG(TS_OFF, VLEVEL_M, "pressure [hPa]:%x\r\n", pressure_hPa);
//	      tx_com( tx_buffer, strlen( (char const *)tx_buffer ) );
	    }

	    if (reg.status.t_da) {
	      memset(&data_raw_temperature, 0x00, sizeof(int16_t));
	      lps33hw_temperature_raw_get(&dev_ctx, &data_raw_temperature);
	      temperature_degC = lps33hw_from_lsb_to_degc(data_raw_temperature);
//	      APP_LOG(TS_OFF, VLEVEL_M, "temperature [degC]:%6.2f\r\n", temperature_degC );
	      APP_LOG(TS_OFF, VLEVEL_M, "temperature [degC]:%x\r\n", temperature_degC );
//	      tx_com( tx_buffer, strlen( (char const *)tx_buffer ) );

	      */


		lps33hw_low_power_set(&dev_ctx, PROPERTY_DISABLE);			// Low-current mode enabled
	    }
	  }
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


void I2C_software_reset(void){
    HAL_StatusTypeDef ret;
    uint8_t var[1];
  	static const uint8_t CTRL_REG2 = 0x11;				// register
    var[0]=0x14;
    ret=platform_write(&hi2c2, CTRL_REG2, var, 1);
    return;
}


void I2C_id(void){

  	static const uint8_t WhoAmI = 0x0F;				// register
  	static const uint8_t CTRL_REG2 = 0x11;				// register
    HAL_StatusTypeDef ret;
    ret=8;
    uint8_t var[1];
    var[0]=0x0;

    ret=platform_write(&hi2c2, CTRL_REG2, var, 1);
    ret=platform_read(&hi2c2, WhoAmI, var, 1);

	APP_LOG(TS_OFF, VLEVEL_M, "WhoAmI ID: 0x%X\n",var[0]);

//*/

//  	static const uint8_t WhoAmI = 0x0F;				// register
//    HAL_StatusTypeDef ret;
//    uint8_t buf[3];
//
//
//    buf[0] = 0x11;
//    buf[0] = WhoAmI;
//    buf[1] = 0;

//    uint8_t arg=1;
//    buf[2] = 0;
////    uint8_t arg[2];
////	arg[0]=buf[0];
////	arg[1]=buf[1];
////	arg[2]=buf[2];
//
//	uint8_t wr;
//	wr=0x2;
//
//    ret=platform_write(&hi2c2, WhoAmI, buf,1);

    /*
    ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, buf, 2, 500); //LPS22HH_I2C_ADD_H & 0xFE

    ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, WhoAmI, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE
	ret=HAL_I2C_Master_Receive(&hi2c2, addr_read, arg, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE

	APP_LOG(TS_OFF, VLEVEL_M, "val: 0x%X\n",arg);

	*/

//	APP_LOG(TS_OFF, VLEVEL_M, "id1: %X\n",buf[0]);
//
//    ret=platform_write(&hi2c2, 0x11, wr,1);
////    ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, buf, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE
//    if ( ret != HAL_OK ) {
//  	  APP_LOG(TS_OFF, VLEVEL_M, "Transmit doet het niet\n");
//    }
//    else{
//      ret=platform_write(&hi2c2, 0x11, buf,0);
//  	  ret=HAL_I2C_Master_Receive(&hi2c2, addr_read, buf, 1, 500); //LPS22HH_I2C_ADD_H & 0xFE
//  	  if ( ret != HAL_OK ) {
//  		  APP_LOG(TS_OFF, VLEVEL_M, "Receive doet het niet\n");
//  	  }
//  	  }
//
//    /*
//    APP_LOG(TS_OFF, VLEVEL_M, "lengte van buf:%x\n",sizeof(buf[1]));
//    int z=0;
//    for (int x=0;x!=sizeof(arg);x++){
//    	if(arg[x]){
//    		z++;
//    }
//    }
//    */
//
////    APP_LOG(TS_OFF, VLEVEL_M, "lengte van buf:%x\n",z);
//	APP_LOG(TS_OFF, VLEVEL_M, "id2: %X\n",buf[0]);

	 return;
}


int32_t platform_write(void *handle, uint8_t Reg, const uint8_t *Bufp, uint16_t len){
    HAL_StatusTypeDef ret;
    uint8_t reg[1];

//	uint8_t message[len];
//
//    reg[0]=Reg;
//
//    if (len>0){
//		for (int i=0; i<len; i++){
//			message[i]=Bufp[i];
//		}
//    }


    uint8_t buffer[len+1];
    if (len>0){
		for (int i=1;i<(len+1);i++){
			buffer[i]=Bufp[i-1];
			}
		buffer[0]=Reg;
    }

//    int z=0;
//    for (int x=0;x!=sizeof(arg);x++){
//    	if(arg[x]){
//    		z++;
//    }
//    }

	ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, buffer, (len+1), 1000);

	if (ret){
		  APP_LOG(TS_OFF, VLEVEL_M, "Er ging iets mis!");
	}
	return ret;
}



int32_t platform_read(void *handle, uint8_t Reg, uint8_t *Bufp, uint16_t len){
    HAL_StatusTypeDef ret;
    uint8_t reg[1];

    reg[0]=Reg;



	ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, reg, 0, 1000);
	if(len>0 && !ret){
		ret=HAL_I2C_Master_Receive(&hi2c2, addr_read, Bufp, len, 1000);
	}
	else if(ret){
	  APP_LOG(TS_OFF, VLEVEL_M, "Kan geen verbinding maken met de sensor!\n");
	}


	return ret;
}

