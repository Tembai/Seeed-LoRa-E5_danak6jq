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

	  while(1){
	  I2C_scan();
	  HAL_Delay(5000);
	  }
//	  platform_read();

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






static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len)
{
	/*
#if defined(NUCLEO_F411RE)
  HAL_I2C_Mem_Write(handle, LPS22HH_I2C_ADD_H, reg,
                    I2C_MEMADD_SIZE_8BIT, (uint8_t*) bufp, len, 1000);
#elif defined(STEVAL_MKI109V3)
  HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(handle, &reg, 1, 1000);
  HAL_SPI_Transmit(handle, (uint8_t*) bufp, len, 1000);
  HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_SET);
#elif defined(SPC584B_DIS)
  i2c_lld_write(handle,  LPS22HH_I2C_ADD_H & 0xFE, reg, (uint8_t*) bufp, len);
#endif

*/
  return 0;
}



/*
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
//static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
static int32_t platform_read(void)
{
//
//	HAL_I2C_Master_Receive(handle, LPS22HH_I2C_ADD_H & 0xFE, reg, bufp, len);
//
//
//  HAL_I2C_Master_Receive (I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t* pData, uint16_t Size, uint32_t Timeout);
//  ret = HAL_I2C_Master_Receive(&hi2c1, TMP102_ADDR, buf, 2, HAL_MAX_DELAY);
//  reg |= 0x80;
//  HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_RESET);
//  HAL_SPI_Transmit(handle, &reg, 1, 1000);
//  HAL_SPI_Receive(handle, bufp, len, 1000);
//  HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_SET);
//#elif defined(SPC584B_DIS)
//  i2c_lld_read(handle, LPS22HH_I2C_ADD_H & 0xFE, reg, bufp, len);
//#endif

  /*##- Put I2C peripheral in reception process ############################*/
  /* Timeout is set to 10S */
  uint8_t aRxBuffer, ijker;
//  while (HAL_I2C_Master_Receive(&hi2c1, (uint16_t)LPS22HH_I2C_ADD_H, aRxBuffer, 8, 100) != HAL_OK)
//  {
//	  APP_LOG(TS_OFF, VLEVEL_M, "while1:%d\n",i++);
//	/* Error_Handler() function is called when Timeout error occurs.
//	   When Acknowledge failure occurs (Slave don't acknowledge it's address)
//	   Master restarts communication */
//	if (HAL_I2C_GetError(&hi2c1) != HAL_I2C_ERROR_AF)
//	{
//	  Error_Handler();
//	}
//	if(i>=50){break;}
//  }
//

//  	char address = "0x5D";
//	while(1){
//		HAL_I2C_Master_Receive(&hi2c1, &address, &aRxBuffer, 8, 100);
//		APP_LOG(TS_OFF, VLEVEL_M, "%X:  %u\n", &address,aRxBuffer);
//		if (address == "0x5D"){
//			address="0x7E";
//		}
//		else {
//				break;
//		}
//	}
  APP_LOG(TS_OFF, VLEVEL_M, "   buffer leeg: %u\n",aRxBuffer);

  HAL_I2C_Master_Receive(&hi2c2, 0x5D, &aRxBuffer, 8, 100); //LPS22HH_I2C_ADD_H & 0xFE

//    	  APP_LOG(TS_OFF, VLEVEL_M, itoa(aRxBuffer));
  APP_LOG(TS_OFF, VLEVEL_M, "   buffer, adres 0x5D, message: %u\n",aRxBuffer);
  	/* Error_Handler() function is called when Timeout error occurs.
  	   When Acknowledge failure occurs (Slave don't acknowledge it's address)
  	   Master restarts communication */


    HAL_I2C_Master_Receive(&hi2c2, 0x7E, &aRxBuffer, 8, 1000); //LPS22HH_I2C_ADD_L & 0xFE
    APP_LOG(TS_OFF, VLEVEL_M, "   buffer, adres 0x7E, message: %u\n", aRxBuffer);
  	/* Error_Handler() function is called when Timeout error occurs.
  	   When Acknowledge failure occurs (Slave don't acknowledge it's address)
  	   Master restarts communication */

//  	if(i>=15){break;}


//	if(aRxBuffer != ijker){APP_LOG(TS_OFF, VLEVEL_M, "er is iets gebeurd!");}
//	else{APP_LOG(TS_OFF, VLEVEL_M, aRxBuffer, "nope...\n");}

//    if(aRxBuffer != ijker){

//    APP_LOG(TS_OFF, VLEVEL_M, aRxBuffer);
//    }


  return 0;
}


static void platform_init(void)
{
//  TIM3->CCR1 = PWM_3V3;
//  TIM3->CCR2 = PWM_3V3;
//  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//  HAL_Delay(1000);
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

