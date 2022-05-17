//this is our project main file
#include "tm4c123gh6pm.h"
#include "driver.c"
#include "drivers_headers.h"
unsigned char time[5] = {0,0, ':',0,0};
enum states { IDLE, StandBy_Weight, StandBy_Time, Cooking, PauseCooking, StopCooking, CompleteCooking};

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
       if (readSW3()==1){
		time[0] = 0;
		time[1] = 0;
		time[3] = 0;
		time[4] = 0;
		LCD_CLR_Screen();
		Led_Array_Off();
		Buzzer_Off();
          }
      
    break;  
   case StandBy_Weight:  
   // StandBy_Weight case code 
    
      
     break; 
    case StandBy_Time:  
   //StandBy_Time case code 
      
      
      break;
    case Cooking:
     			cooking_status  = Cooking_Countdown (time);
			if (cooking_status ==1)
				state = CompleteCooking;
		        
	                if (readSW1()==0)

			{ 
				void pauseCooking(void); //go to pauseCooking if switch 1 is pressed
			}
	

      
      
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
