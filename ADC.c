/*
 * ADC.c
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */
#include "ADC.h"
#include"COMMON_MACROS.h"
#include<AVR/io.h>

void ADC_init(const ADC_ConfigType *Config_Ptr ){

	//ADMUX=((Config_Ptr->voltage)<<6);
	ADMUX =(1<<REFS0)|(1<<REFS1) ;

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA=(1<<ADEN);
	ADCSRA=(ADCSRA&0XF8)|(Config_Ptr->DIVISON_FACTOR);



}
uint16 ADC_readChannel(uint8 Channel_num){

	ADMUX=(Channel_num&0X07)|(ADMUX&0XE0);
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC;
}
