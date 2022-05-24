#include "drivers_headers_new.h"
#include "tm4c123gh6pm.h"

// return zero means continue cooking state
// return one means stop cooking IDLE state
unsigned char pauseCooking(void)
{
	
 
	

	 while (readSW1()==0)
	 {
		 void port_init (unsigned char F);
		 GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R ^0x0E;
	   delayMs(1000);
	    
	 } //blink leds
			
	while(1)
	{
		void port_init (unsigned char F);
		 GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R ^0x0E;
	   delayMs(1000);
	   
		
   if (readSW2() == 0 && readSW3() == 1 )   //sw2 is clicked and door is closed cont cooking
		{ 
			return 0 ; 
		}
	
	
   else if (readSW1() ==0)  //clicked 2nd time stop cooking
	
		{ return 1 ;
		}
	
   
	
 }
}
