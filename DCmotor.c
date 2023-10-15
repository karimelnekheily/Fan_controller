/*
 * DCmotor.c
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */

#include "DCmotor.h"
#include"GPIO.h"
#include"PWM_DRIVER.h"
#include"COMMON_MACROS.h"


void DcMOTOR_Init(void){
	/*Set the motor pins as outputs*/
	GPIO_setupPinDirection(PORTB_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);
	/* Stop the motor at the beginning*/
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
}
void DcMotor_Rotate(DcMOTOR_STATE state,uint8 speed){

switch (state){
case MOTOR_CW:
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN1_ID,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
	break;
case MOTOR_A_CW:
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN2_ID,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
	break;
case MOTOR_STOP:
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
	break;
}
PWM_Timer0_Start(speed);

}
