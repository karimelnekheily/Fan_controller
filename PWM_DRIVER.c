/*
 * PWM_DRIVER.c
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */

#include "PWM_DRIVER.h"
#include "GPIO.h"
#include<avr/io.h>
#include"std_types.h"

void PWM_Timer0_Start(uint8 duty_cycle){

	TCNT0=0; /*initialize the counter to 0*/

	OCR0=(uint8)((uint32)(duty_cycle*255)/100); /*SET the compare value*/
	GPIO_setupPinDirection(PORTB,OCO_PIN_ID,PIN_OUTPUT);
	DDRB = DDRB | (1<<PB3); // Configure PB3/OC0 Pin as output pin
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);

}



