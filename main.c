//this is our project main file
#include "tm4c123gh6pm.h"
#include "drivers_headers.h"
unsigned char time[5] = {0,0, ':',0,0};
enum states { IDLE, StandBy_Weight, StandBy_Time, Cooking, PauseCooking, StopCooking, CompleteCooking};

// dont forget to intialize variables at each state for example in IDLE most if not all variables should be intialized with 0
void Microwave_Control(){
Switch_Init();
Buzzer_vInit();
Led_Array_vInit();
port_init ('F');
port_init ('D');
	
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
    
      
     break; 
    case StandBy_Time:  
   //StandBy_Time case code 
	
	KeyPad_vInit();
	unsigned char new_input = 0;
	uint16_t sum = 0;
	char msg[] = {"Cooking time?"};
	char *m;
	LCD_Vsend_String(m);
	generic_Delay(3000);
	char time[];
	char *t;
	LCD_Vsend_String(t);
	for(i=0 ;i<4 ;i++)
	{
	new_input=KEYPAD_u8Read();
	if(new_input == '*') break;
	shift_arr(t);
	*(t+4) = new_input;
	}
	sum = time_sum(t);
	if(sum > 1800)
	{
		print_Err();
		state = StandBy_Time;
	}
	else
	{
	state = Cooking;
	}
	      break;
		  
    case Cooking:
		   if (readSW3()==1){
     			cooking_status  = Cooking_Countdown (time);
			if (cooking_status ==1)
				state = CompleteCooking;
		        
	                if (readSW1()==0)

			{ 
				void pauseCooking(void); //go to pauseCooking if switch 1 is pressed
			}
	
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
