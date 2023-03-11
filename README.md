# 8_bit_Microcontroller_Interface

 Interfacing with 8 bit microcontroller as a part of embedded systems learning path
 
 This project is to learn how to interface with 8 bit microcontrollers, for example in this project I interface with PIC18F4620 microcontroller.
 
 Project divided into 3 layers" HAL layer - ECU Layer - Application layer "to abstract the project.
 
 Application layer : 
			- the main application layer" the top layer "with it you can access the ecu layer.
			
 ECU layer :
			- the intermediate layer can be accessed by application layer and it can access the Hal layer.
 HAL layer :
			- the bottom layer that talk to the hardware itself and can be accessed by ecu layer.
			
			
			
 Device Drivers Done by now : 
		- Hal : 
			- GPIO Device Driver
		- ECU :
			- LED
			- PUSH BUTTON
			- RELAY
			- DC MOTOR
			- 7 Segments
			- MATRIX KEYPAD