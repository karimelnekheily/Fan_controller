/*
 * DCmotor.h
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "std_types.h"

typedef enum{
	MOTOR_CW,MOTOR_A_CW,MOTOR_STOP
}DcMOTOR_STATE;

/*Function prototype*/
void DcMOTOR_Init(void);

void DcMotor_Rotate(DcMOTOR_STATE state,uint8 speed);




#endif /* DCMOTOR_H_ */
