/*
 * ADC.h
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

#define ADC_MAX_VALUE 		1023
#define ADC_REF_VOLT_VALUE 	2.56
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{

	AREF_VOLTAGE,AVCC,RESERVED,INTERNAL_VOLTAGE
}VOLTAGE_REFERENCE_SELECTION;
typedef enum{
	F_CPU_21,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_DIVISION_FACTOR;

typedef struct{
	VOLTAGE_REFERENCE_SELECTION voltage;
	ADC_DIVISION_FACTOR  DIVISON_FACTOR;

}ADC_ConfigType;

/*
 Function Protypes
*/
/*Function to itialize the ADC driver:
*set the required voltage
*set teh required frequency CPU
*Enable conversion */
void ADC_init(const ADC_ConfigType *Config_Ptr );
/*Function to read the required where it is connected to the pin*/
uint16 ADC_readChannel(uint8 Channel_num);



#endif /* ADC_H_ */
