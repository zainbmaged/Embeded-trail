unsigned char Is_Valid	(int min, int max, int number){ 
	if(number<=min)
		return 0;
	else if(number>=max)
		return 0;
	else
		return 1;
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




