/*
 * LM35_sensor.c
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */

#include "LM35_sensor.h"
#include"ADC.h"

uint8 LM35_GetTemperature(void){

	uint8 temp_value = 0;

	uint16 adc_value = 0;
/*	read ADC channel from where temperature sensor is connected*/
	adc_value=ADC_readChannel(SENSOR_CHANNEL_ID);
   /* calculate the temperature from ADC*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAX_VALUE*SENSOR_MAX_VOLT));

	return temp_value;
}
