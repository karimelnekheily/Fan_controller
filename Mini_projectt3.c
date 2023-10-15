/*
 * Mini_projectt3.c
 *
 *  Created on: Oct 10, 2023
 *      Author: karim
 */

#include"LM35_sensor.h"
#include"ADC.h"
#include"DCmotor.h"
#include"COMMON_MACROS.h"
#include"PWM_DRIVER.h"
#include "LCD.h"





int main(void){
    ADC_ConfigType ADC_configuration={AREF_VOLTAGE,F_CPU_8};
uint8 temp=0;
    ADC_init(&ADC_configuration);
    LCD_init();
    DcMOTOR_Init();

    LCD_moveCursor(0,3);
    LCD_displayString("FAN is  ");
    LCD_moveCursor(1,0);
    LCD_displayString("Temp =    C");
    while(1){
     temp=LM35_GetTemperature();

     if(temp>=0 &&temp<30){

    	 LCD_moveCursor(0,10);
    	 LCD_displayString("OFF");
    	 LCD_moveCursor(1,7);
    	 LCD_intgerToString(temp);
    	 LCD_displayCharacter(' ');
    	 DcMotor_Rotate(MOTOR_STOP,0);
     }else if(temp>=30&&temp<60){
    	 LCD_moveCursor(0,10);
    	 LCD_displayString("ON");
    	 LCD_displayCharacter(' ');
    	 LCD_moveCursor(1,7);
    	 LCD_intgerToString(temp);
    	 LCD_displayCharacter(' ');
    	 DcMotor_Rotate(MOTOR_CW,25);
     }
      else if(temp>=60 && temp<90){
    	  LCD_moveCursor(0,10);
    	  LCD_displayString("ON");
    	  LCD_moveCursor(1,7);
    	  LCD_intgerToString(temp);
    	  //LCD_displayCharacter(' ');
    	  DcMotor_Rotate(MOTOR_CW,50);

      }
      else if(temp>=90 && temp<120){
    	  LCD_moveCursor(0,10);
    	  LCD_displayString("ON");
    	  LCD_moveCursor(1,7);
    	  if(temp>=100){
    		  LCD_intgerToString(temp);
    	  }
    	  else{
    		  LCD_intgerToString(temp);
    		  LCD_displayCharacter(' ');
    	  }
    	  //LCD_intgerToString(temp);
    	  //LCD_displayCharacter(' ');
    	  DcMotor_Rotate(MOTOR_CW,75);
      }
      else{ //if(temp>=120 && temp<150){
    	  LCD_moveCursor(0,10);
    	  LCD_displayString("ON");
    	  LCD_moveCursor(1,7);
    	  LCD_intgerToString(temp);
    	  //LCD_displayCharacter(' ');
    	  DcMotor_Rotate(MOTOR_CW,100);
     }




	}
}
