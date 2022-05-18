//this is our project main file
#include "tm4c123gh6pm.h"
#include "drivers_headers.h"

#define Popcorn 'A'
#define Beef 'B'
#define Chicken 'C'
#define StandBy_Time 'D'

unsigned char time[5] = {'0','0', ':','0','0'};
enum states {IDLE, Cooking, PauseCooking, CompleteCooking};


//variable
int state = IDLE;		// variable state to select next state intialized to start at IDLE
unsigned char cooking_status = 0; 
unsigned char weight;
unsigned int  weight_time;
unsigned  char msg_Beef[] = "Beef weight?";
unsigned  char msg_Chicken[] = "Chicken weight?";


// dont forget to intialize variables at each state for example in IDLE most if not all variables should be intialized with 0
int main(){
Switch_Init();
Buzzer_vInit();
Led_Array_vInit();
KeyPad_vInit();
LCD_vInit();
port_init ('A');
port_init ('B');
port_init ('C');
port_init ('E');
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
		 state = KEYPAD_u8Read();
        
      
    break;  

    
	case Popcorn:  
		  time[1] = '1'; 
		  state = Cooking;
	break; 
	case Beef:  
		  LCD_CLR_Screen();
		  LCD_Vsend_String(msg_Beef);
		  weight = KEYPAD_u8Read();
		  if(Is_Valid(49, 57, weight)){
			  weight_time = weight*30;
			  convert_to_array(weight_time, time);
			  state = Cooking;
			  LCD_CLR_Screen();
		  }
		  else{
			  print_Err();
			  state = Beef;
		  }
	break; 
	case Chicken:  
		  LCD_CLR_Screen();
		  LCD_Vsend_String(msg_Beef);
		  weight = KEYPAD_u8Read();
		  if(Is_Valid(49, 57, weight)){
			  weight_time = weight*30;
			  convert_to_array(weight_time, time);
			  state = Cooking;
			  LCD_CLR_Screen();
		  }
		  else{
			  print_Err();
			  state = Chicken;
		  }
      break; 
    case StandBy_Time:  
   //StandBy_Time case code 
	
	unsigned char new_input = 0;
	uint16_t sum = 0;
	unsigned char msg[] = {"Cooking time?"};
	unsigned char time[];
	unsigned char *m;
	unsigned char *t;
	m = msg;
	t = time;
	LCD_Vsend_String(m);
	generic_Delay(3000);
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
