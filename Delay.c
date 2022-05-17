#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#include "Io.h"
#include "drivers_headers.h"



void systick_wait (unsigned long delay)
{
	NVIC_ST_CTRL_R = 0x00;
	NVIC_ST_RELOAD_R = delay-1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x05;
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0)
	{}
	}
void generic_Delay (unsigned long time)
{
	int i;
	for (i=0;i<time;i++)
	{
		systick_wait(16000);
	}
	
}




unsigned char Cooking_Countdown (unsigned char *cooking_Time){  //cooking_time = {Min_tens, Min_ones, ':', Sec_tens, Sec_Ones}   returns 1 if completely finished 
	unsigned char array_Counter;
	
	while(1){
		//print current time
		
		LCD_CLR_Screen();
		Led_Array_On();
		
		LCD_Vsend_String(cooking_Time);
		
		//subtract time and check if finished
	
    if((*cooking_Time)!= '0'){ //check if Sec_Ones =0
			(*cooking_Time)--;
			cooking_Time -= 4;
		}
		else{
			(*cooking_Time)='9';
			 cooking_Time--;
					if((*cooking_Time)!= '0'){	//check if Sec_tens =0
						(*cooking_Time)--;
						 cooking_Time -= 3;
					}
					else{
						(*cooking_Time) = '5';        // sec_tens = 5
						cooking_Time-=2;						// skip ':'
						if((*cooking_Time)!= '0'){	//check if Min_Ones =0
							(*cooking_Time)--;
							cooking_Time -= 2;
						}
						else{
						(*cooking_Time) = '9';
						cooking_Time--;
						if((*cooking_Time)!= '0'){	//check if Min_tens =0
						(*cooking_Time)--;
						cooking_Time -= 1;
						}
						else{

							//complete cooking
							return 0;
						}

						}

					}
		}
		
		//optional interrupt
		
		
		generic_Delay(1000);
	}
}
