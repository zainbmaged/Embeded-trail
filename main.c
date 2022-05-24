
#include "tm4c123gh6pm.h"
#include "drivers_headers.h"
#include "stdint.h"
#include "Io.h"

#define Popcorn 'A'
#define Beef 'B'
#define Chicken 'C'
#define StandBy_Time 'D'

unsigned char time[5] = {'0','0', ':','0','0'};
enum state {IDLE, Cooking, PauseCooking, CompleteCooking};


//variable
int state = IDLE;		// variable state to select next state intialized to start at IDLE
unsigned char cooking_status = 0; 
unsigned char weight=0;
unsigned int  weight_time;
 unsigned char msg_Beef[] = "Beef weight?";
unsigned  char msg_Chicken[] = "Chicken weight?";
unsigned char new_input = 0;
uint16_t sum = 0;
 unsigned char msg[] = "Cooking time?";
 unsigned char *m;
unsigned char *t;
unsigned char i;
unsigned char input;
unsigned char  pop [] = {"popcorn"};
unsigned int remainder ;	 
//the main code
int main(){
	
// ports intializations
port_init ('A');
port_init ('B');
port_init ('E');
port_init ('F');

Switch_Init();
Switch_Init_Pullup();
Buzzer_vInit();
Led_Array_vInit();
keypad_Init();
LCD4bits_Init();


 keypad_Init(); //Initialize keypad and TM4C123 GPIO pins
 LCD4bits_Init(); // initialize 16x2 LCD
 LCD_CLR_Screen(); // Clear LCD screen
//________________________________________________________________//
	
while(1){
  switch (state){
  
     case IDLE:
     
		time[0] = '0';
		time[1] = '0';
		time[3] = '0';
		time[4] = '0';
		LCD_CLR_Screen();
  	//Led_Array_Off();
 		Buzzer_Off();
		 
	 	 
     
			 
		 while (1){
	   	 input = KEYPAD_u8Read();  
       delayMs(500);
		  
			 if(input == 'A'){
		   LCD_Vsend_String(pop);
			 delayMs(1000); 
			 LCD_CLR_Screen();
			 time[1] = '1'; 
    	 state = Cooking;
			 
			 break;
			 }
			  if(input == 'B'){
		  
    	 state = Beef;
			 
			 break;
			 }
				if(input == 'C'){
		  
    	 state = Chicken;
			 
			 break;
			 }
				if(input == 'D'){
		  
    	 state = StandBy_Time;
			 
			 break;
			 }
		 }

		break;
	
 		 
	case Beef:  
		  LCD_CLR_Screen();
		  LCD_Vsend_String(msg_Beef);
	    while(1){
				
		  weight = KEYPAD_u8Read();
	    delayMs(500);
				if(weight !=0){
				break;
				}
			
			}
		  
			if(!(weight >'9' || weight<'1')){
				weight_time = (weight-48)*30;
			  convert_to_array(weight_time, time);
			  state = Cooking;
			  LCD_CLR_Screen();}
			  
		  else{
			  print_Err();
			  state = Beef;
		  }
		
	break; 
			
			
	case Chicken:  
		  LCD_CLR_Screen();
		  LCD_Vsend_String(msg_Chicken);
	
	  while(1){
		  weight = KEYPAD_u8Read();
	    delayMs(500);
		   if(weight != 0){
				break;
     	}
		}
		  if(!(weight >'9' || weight<'1')){
			  weight_time = (weight-48)*12;
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
  	time[0] = '0';
		time[1] = '0';
		time[3] = '0';
		time[4] = '0';
	t = time;
	LCD_Vsend_String(msg);
	delayMs(3000);
	LCD_CLR_Screen();
	LCD_Vsend_String(time);
	for(i=0 ;i<4 ;i++)
	{  

		while(1){
	new_input=KEYPAD_u8Read();
		  delayMs(500);
		if(new_input !=0){
		break;
		}
		}
//	if(readSW2() == 0){ 
//	state = Cooking;
//	break;}
	shift_arr(t);
	*(t+4) = new_input;
		LCD_CLR_Screen();
	LCD_Vsend_String(time);
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
		
	if(readSW3() == 0){ // need to be changed to sw2
	while(1){
	//print current time
		
		LCD4bits_Cmd(0x01); // clear display
		Led_Array_On();
		
		LCD_Vsend_String(time);

		//subtract time and check if finished
		if(time[4] != '0'){
			time[4]--;
		}
		else
		{
			time[4]='9';
			if(time[3] !='0')
			{
				time[3]--;
			}
			else
			{
				time[3] = '5';
				if(time[1] != '0')
				{
					time[1]--;
				}
				else
				{
					time[1] = '9';
					if(time[0] != '0')
					{
						time[0]--;
					}
					else{
						state = CompleteCooking;
						break;
						
					}
				}
			}
		}
		delayMs(1000);
    if (readSW1() ==0 || readSW3() == 0) //if sw1 is clicked or the door is open goe to pauseCooking  
	  { 
	   if( pauseCooking () ==0)
     {state = Cooking; }
	   else
     state = IDLE;
	 } 
		
	}
}
	  
     
      break;
 
  case CompleteCooking:
	Led_Array_Off();
	Buzzer_On();
	delayMs(500);
  // blink leds
   Blink(3);
	LCD_CLR_Screen();
	state = IDLE;	 
     	
			
      break;
  

       }
  }
		
 }


