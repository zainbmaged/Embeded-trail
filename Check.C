#include "stdint.h"
#include "drivers_headers.h"


unsigned char Is_Valid	(unsigned int min, unsigned int max, unsigned int number){ //false =0 true 1
	if(number<=min)
		return 0;
	else if(number>= max)
		return 0;
	else
		return 1;
}

void convert_to_array(unsigned int t, unsigned char* Atime){  //send time and array time
	unsigned int remainder;

	
	
	(*Atime) = ((unsigned int)t/600 + 48); //set Min_Tens
	 remainder = t-((unsigned int)(*Atime)-48)*600;
	
	(*(Atime+1)) = ((unsigned int)(remainder)/60) + 48;
	remainder = remainder+ (unsigned int)((*(Atime+1))-48)*60;
	
	*(Atime+3) = ((unsigned int)(remainder)/10) + 48;
	remainder = remainder+ (unsigned int)((*(Atime+3))-48)*10;
	
	*(Atime+4) = ((unsigned int)(remainder)) + 48;
}

// function to shift the time array by one time slot to the left
void shift_arr(char *t)
{
	*t = *(t+1);
	*(t+1) = *(t+3);
	*(t+3)= *(t+4);
}

//function to sum time array
uint16_t time_sum (char *t)
{
	uint16_t sum = 0;
	sum = (*(t) - 48)*600 + (*(t+1) - 48)*60 + (*(t+3) - 48)*10 + (*(t+4) - 48);
	return sum;
}

//function to print "Err" onscreen for 3 secs the clears screen
void print_Err()
{
		unsigned char msg[] = "Err";
		unsigned char *m;
	
	LCD_CLR_Screen();
	m = msg;
	LCD_Vsend_String(m);
	generic_Delay(3000);
	LCD_CLR_Screen();
}




