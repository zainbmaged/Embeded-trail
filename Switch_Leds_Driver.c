#define SW3_Port 'A'
#define SW3_pin 2
#define Buzzer_port 'A'
#define Buzzer_pin 3
#include "drivers_headers.h"


//initialize switches 
void Switch_Init(){							
	DIO_vpin_dir ('F', 0, 0); 		//SW2
	DIO_vpin_dir ('F', 4, 0);		//SW1
	DIO_vpin_dir (SW3_Port, SW3_pin, 0); 	//SW3
}

unsigned char readSW1(){
	return DIO_u8READ_PIN('F' ,0);
}

unsigned char readSW2(){
	return DIO_u8READ_PIN('F' ,4);
}

unsigned char readSW3(){
	return DIO_u8READ_PIN(SW3_Port, SW3_pin);
}


void Switch_Init_Pullup(){
	DIO_vpin_dir ('F', 0, 0);
	DIO_vpin_dir ('F', 4, 0);
	DIO_vpin_dir (SW3_Port, SW3_pin, 0);

	DIO_enablePullUp ('F', 0);
	DIO_enablePullUp ('F', 4);
	DIO_enablePullUp (SW3_Port, SW3_pin);
}

void Buzzer_vInit(void){
	DIO_vpin_dir (Buzzer_port, Buzzer_pin, 1);
}

void Buzzer_On(){

	DIO_vwrite_PIN (Buzzer_port, 1 ,Buzzer_pin);

}

void Buzzer_Off(void){
	DIO_vwrite_PIN (Buzzer_pin, 0, Buzzer_pin);

}

void Buzzer_Toggle(){
	DIO_vtoggle_PIN (Buzzer_port,Buzzer_pin );
}


void Led_Array_vInit(void){
	DIO_vpin_dir ('F', 1, 1);
	DIO_vpin_dir ('F', 2, 1);
	DIO_vpin_dir ('F', 3, 1);
}

void Led_Array_On(){
	DIO_vwrite_PIN ('F', 1 ,1);
	DIO_vwrite_PIN ('F', 1 ,2);
	DIO_vwrite_PIN ('F', 1 ,3);
}

void Led_Array_Off(void){
	DIO_vwrite_PIN ('F', 0, 1);
	DIO_vwrite_PIN ('F', 0, 2);
	DIO_vwrite_PIN ('F', 0, 3);
}

void Led_Array_Toggle(){
	DIO_vtoggle_PIN ('F', 1);
	DIO_vtoggle_PIN ('F', 2);
	DIO_vtoggle_PIN ('F', 3);
}
void Blink (unsigned char blinks){
	int counter;
	for(counter = 0 ; counter < blinks*2 ; counter++ ){
	Led_Array_Toggle();
	generic_Delay(500);
	}
}
