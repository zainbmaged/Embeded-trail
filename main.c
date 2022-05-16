//this is our project main file
#include "tm4c123gh6pm.h"
#include "driver.c"
#include "drivers_headers.h"
char time[5] = {0,0, ':',0,0};
enum states { IDLE, StandBy_Weight, StandBy_Time, Cooking, CompleteCooking};

// dont forget to intialize variables at each state for example in IDLE most if not all variables should be intialized with 0
void Microwave_Control(){
Switch_Init();
Buzzer_vInit();
Led_Array_vInit();
port_init ('F');	
	
int state = IDLE;// variable state to select next state intialized to start at IDLE
unsigned char cooking_status = 0; 
  while(1){
  switch (state){
  
		case IDLE:
		time[0] = 0;
		time[1] = 0;
		time[3] = 0;
		time[4] = 0;
		LCD_CLR_Screen();
		Led_Array_Off();
		Buzzer_Off();
   
      
    break;  
   case StandBy_Weight:  
   // StandBy_Weight case code 
   if 
      
     break; 
    case StandBy_Time:  
   //StandBy_Time case code 
      
      
      break;
    case Cooking:
     			cooking_status  = Cooking_Countdown (time);
			if (sw ==1){
				PauseCooking(){
				if (sw1==1){
				state = CompleteCooking;
				}
			       else  (sw2==1)
				state = CompleteCooking;
			       
				}
				
				state = CompleteCooking;
      
      
      break;
  
  
   case CompleteCooking:
	Led_Array_Off();
			Buzzer_On();
			Blink (3);
			LCD_CLR_Screen();
		  state = IDLE;	 
     	
			
      break;

       }
  }
}
