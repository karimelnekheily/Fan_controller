# Temperature_Fan_controller
## overview
This project aims to design a temperature-controlled fan system using the ATmega32 microcontroller.
The system monitors temperature using the LM35 temperature sensor,
converts analog readings to digital values using the ADC,
and controls a fan's speed based on predefined temperature thresholds. 
The project follows a layered architecture, with separate drivers for various components.
## Requirements
A-__Microcontroller__: Utilize the ATmega32 microcontroller with a 1MHz clock frequency.<br>

B-__Temperature Sensor__: Incorporate the LM35 to provide continuous analog temperature output.<br>

C-__Analog-to-Digital Conversion (ADC)__: Convert the analog temperature output to digital values for processing.<br>

D-__Temperature Calculations__: Implement temperature calculations within the microcontroller.<br>

E-__Display__: Display the temperature on an LCD.<br>

F-__Fan Speed Control__: Control the fan speed based on temperature as follows:<br>

Below __30°C__: Turn off the fan.<br>
-__30-59°C__: Run the fan at 25% speed.<br>
-__60-89°C__: Run the fan at 50% speed.<br>
__90-119°C__: Run the fan at 75% speed.<br>
Above __120°C__: Run the fan at 100% speed.<br>
G-__Layered Architecture__: Organize the project using a layered architecture model for modularity and maintainability.<br>

# Temperature sensor requirements
A-__Temperature Sensor Driver__: Implement the temperature sensor driver as taught in the course.<br>
B-__Sensor Connection__: Connect the LM35 temperature sensor to ADC channel 0.<br>

# DC MOTOR:
A-__DC-Motor Driver__: Implement a comprehensive DC-Motor driver.
B-__Initialization__: Create an DcMotor_Init function that initializes the motor and stops it initially.<br>

C-__ControLl__: Develop a DcMotor_RotateWithControl function that rotates the motor clockwise (CW), counter-clockwise (CCW), or stops it based on the state input and speed.<br>
D-__Additional Control__: Optionally, create a DcMotor_RotateWithoutControl function that allows the motor to rotate at maximum speed or stop without specific control.<br>
# PWM_REQUIREMENTS:
__PWM Driver__: Utilize the PWM Timer0 function implemented in the course to control the DC motor's speed.<br>
__PWM Configuration__: Implement a PWM_Timer0_Start function to configure Timer0 for PWM mode. This function should set the PWM mode, prescaler, duty cycle, and pin direction for controlling the motor's speed.<br>

