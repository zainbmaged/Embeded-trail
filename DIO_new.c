#include "tm4c123gh6pm.h"
//the macros used please use same names
#define SET_BIT(reg,bit)     (reg|= (1<<bit))
#define CLR_BIT(reg,bit)     (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)      (reg^=(1<<bit))
#define READ_BIT(reg,bit)     ((reg&(1<<bit))>>bit)
#include "Io.h"
#include "drivers_headers_new.h"

////////////////////////////////////////////////////////////////////////////////////////////

//DIO Driver

//enum dir {input, output}; //input=0, output=1
#define input 0
#define output 1
//port initialization function
void port_init (unsigned char port)
{
	switch(port) 
	{
		case 'A':
		case 'a':
		{
		SET_BIT(SYSCTL_RCGCGPIO_R,0);
		while (READ_BIT(SYSCTL_PRGPIO_R,0) == 0);
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0xFF;
		GPIO_PORTA_DEN_R = 0xFF;
		GPIO_PORTA_AMSEL_R = 0x00;
		GPIO_PORTA_PCTL_R = 0x00000000;
		GPIO_PORTA_AFSEL_R = 0x00;
		}
		break;
		
		case 'B':
		case 'b':
		{
		SET_BIT(SYSCTL_RCGCGPIO_R,1);
		while (READ_BIT(SYSCTL_PRGPIO_R,1) == 0);
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTB_CR_R |= 0xFF;
		GPIO_PORTB_DEN_R = 0xFF;
		GPIO_PORTB_AMSEL_R = 0x00;
		GPIO_PORTB_PCTL_R = 0x00000000;
		GPIO_PORTB_AFSEL_R = 0x00;
		}
		break;
		case 'C':
		case 'c':
		{
		SET_BIT(SYSCTL_RCGCGPIO_R,2);
		while (READ_BIT(SYSCTL_PRGPIO_R,2) == 0);
		GPIO_PORTC_LOCK_R = 0x4C4F434B;
		GPIO_PORTC_CR_R |= 0xFF;
		GPIO_PORTC_DEN_R = 0xFF;
		GPIO_PORTC_AMSEL_R = 0x00;
		GPIO_PORTC_PCTL_R = 0x00000000;
		GPIO_PORTC_AFSEL_R = 0x00;
		}
		break;
		case 'D':
		case 'd':
		{
		SET_BIT(SYSCTL_RCGCGPIO_R,3);
		while (READ_BIT(SYSCTL_PRGPIO_R,3) == 0);
		GPIO_PORTD_LOCK_R = 0x4C4F434B;
		GPIO_PORTD_CR_R |= 0xFF;
		GPIO_PORTD_DEN_R = 0xFF;
		GPIO_PORTD_AMSEL_R = 0x00;
		GPIO_PORTD_PCTL_R = 0x00000000;
		GPIO_PORTD_AFSEL_R = 0x00;
		}
		break;
		
		case 'E':
		case 'e':
		{
		SET_BIT(SYSCTL_RCGCGPIO_R,4);
		while (READ_BIT(SYSCTL_PRGPIO_R,4) == 0);
		GPIO_PORTE_LOCK_R = 0x4C4F434B;
		GPIO_PORTE_CR_R |= 0xFF;
		GPIO_PORTE_DEN_R = 0xFF;
		GPIO_PORTE_AMSEL_R = 0x00;
		GPIO_PORTE_PCTL_R = 0x00000000;
		GPIO_PORTE_AFSEL_R = 0x00;
		}
		break;
		
		case 'F':
		case 'f':
		{
		SET_BIT(SYSCTL_RCGCGPIO_R,5);
		while (READ_BIT(SYSCTL_PRGPIO_R,5) == 0);
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0xFF;
		GPIO_PORTF_DEN_R = 0xFF;
		GPIO_PORTF_AMSEL_R = 0x00;
		GPIO_PORTF_PCTL_R = 0x00000000;
		GPIO_PORTF_AFSEL_R = 0x00;
		}
		break;
	}
}
 //set pin direction function
void DIO_vpin_dir (unsigned char port, unsigned char pin, unsigned char dir){
	switch (port)
		{
			case 'A':
			case 'a':
			{
				if (dir == input)
				{
					CLR_BIT(GPIO_PORTA_DIR_R, pin);
				}
				if (dir == output)
				{
					SET_BIT(GPIO_PORTA_DIR_R, pin);
				}
			}
				break;
			case 'B':
			case 'b':
			{
				if (dir == input)
				{
					CLR_BIT(GPIO_PORTB_DIR_R, pin);
				}
				if (dir == output)
				{
					SET_BIT(GPIO_PORTB_DIR_R, pin);
				}
			}
				break;
			case 'C':
			case 'c':
			{
				if (dir == input)
				{
					CLR_BIT(GPIO_PORTC_DIR_R, pin);
				}
				if (dir == output)
				{
					SET_BIT(GPIO_PORTC_DIR_R, pin);
				}
			}
				break;
			case 'D':
			case 'd':
			{
				if (dir == input)
				{
					CLR_BIT(GPIO_PORTD_DIR_R, pin);
				}
				if (dir == output)
				{
					SET_BIT(GPIO_PORTD_DIR_R, pin);
				}
			}
				break;
			case 'E':
			case 'e':
			{
				if (dir == input)
				{
					CLR_BIT(GPIO_PORTE_DIR_R, pin);
				}
				if (dir == output)
				{
					SET_BIT(GPIO_PORTE_DIR_R, pin);
				}
			}
				break;
			case 'F':
			case 'f':
			{
				if (dir == input)
				{
					CLR_BIT(GPIO_PORTF_DIR_R, pin);
				}
				if (dir == output)
				{
					SET_BIT(GPIO_PORTF_DIR_R, pin);
				}
			}
				break;
						
		}
	}

 //void fuction to write data on one pin
void DIO_vwrite_PIN(unsigned char port_name, unsigned char DATA ,unsigned char pin_number){
	 switch (port_name){
		 //for portA
		 case 'A':
		 case 'a':
		 {
                    if(DATA==1)
		     {SET_BIT(GPIO_PORTA_DATA_R,pin_number);}
		    else
		     CLR_BIT(GPIO_PORTA_DIR_R,pin_number);
			}	
			break;
		 
		  //for portB
		 case 'B':
		 case 'b':
		 {
      		    if(DATA==1)
		     {SET_BIT(GPIO_PORTB_DATA_R,pin_number);}
		     else
		      CLR_BIT(GPIO_PORTB_DIR_R,pin_number);
			 }
				 break;
		 
		  //for portC
		 case 'C':
		 case 'c':
		 {
        		if(DATA==1)
			{SET_BIT(GPIO_PORTC_DATA_R,pin_number);}
			else
			CLR_BIT(GPIO_PORTC_DIR_R,pin_number);
		}
			break;
			
		  //for portD
		 case 'D':
		 case 'd':
		 {
        		if(DATA==1)
			{SET_BIT(GPIO_PORTD_DATA_R,pin_number);}
			else
			CLR_BIT(GPIO_PORTD_DIR_R,pin_number);
		}
			break;
			
		  //for portE
		 case 'E':
		 case 'e':
		 {
        		if(DATA==1)
			{SET_BIT(GPIO_PORTE_DATA_R,pin_number);}
			else
			CLR_BIT(GPIO_PORTE_DIR_R,pin_number);
		}
			break;
			
		  //for portF
		 case 'F':
		 case 'f':
		 {
        		if(DATA==1)
			{SET_BIT(GPIO_PORTF_DATA_R,pin_number);}
			else
			CLR_BIT(GPIO_PORTF_DIR_R,pin_number);
		}
			break;
	 }
}

//void function to toggle data of one pin
void DIO_vtoggle_PIN(unsigned char port_name ,unsigned char pin_number){
	 switch (port_name){
		 //for portA
		 case 'A':
		 case 'a':
		 {
			TOG_BIT(GPIO_PORTA_DATA_R,pin_number);
		 }
			 break; 
		 
		  //for portB
		 case 'B':
		 case 'b':
		 {
     TOG_BIT(GPIO_PORTB_DATA_R,pin_number);
		 }
			 break; 
		 
		  //for portC
		 case 'C':
		 case 'c':
		 {
      TOG_BIT(GPIO_PORTC_DATA_R,pin_number);
		 }
			 break; 
		  //for portD
		 case 'D':
		 case 'd':
		 {
       			TOG_BIT(GPIO_PORTD_DATA_R,pin_number);
		 }
			 break; 
		  //for portE
		 case 'E':
		 case 'e':
		 {
       			TOG_BIT(GPIO_PORTE_DATA_R,pin_number);
		 }
			 break;
		  //for portF
		 case 'F':
		 case 'f':
		 {
       			TOG_BIT(GPIO_PORTF_DATA_R,pin_number);
		 }
			 break;
	 }
}
//DIFFERENT!!!
 //fuction to read on one pin
unsigned char DIO_u8READ_PIN(unsigned char port_name ,unsigned char pin_number){
	 switch (port_name){
		 //for portA
		 case 'A':
		 case 'a':
		 {
       			return	READ_BIT(GPIO_PORTA_DATA_R,pin_number);
		 }
		 
		  //for portB
		 case 'B':
		 case 'b':
		 {
     		  	return	READ_BIT(GPIO_PORTB_DATA_R,pin_number);
		 }
		 
		  //for portC
		 case 'C':
		 case 'c':
		 {
       			return	READ_BIT(GPIO_PORTC_DATA_R,pin_number);
		 }
		  //for portD
		 case 'D':
		 case 'd':
		 {
       			return	READ_BIT(GPIO_PORTD_DATA_R,pin_number);
		 }
		  //for portE
		 case 'E':
		 case 'e':
		 {
       			return	READ_BIT(GPIO_PORTE_DATA_R,pin_number);
		 }
		  //for portF
		 case 'F':
		 case 'f':
		 {
       			return	READ_BIT(GPIO_PORTF_DATA_R,pin_number);
		 }
	 } return 0;
}



void DIO_setPortDir( unsigned char portName, unsigned char direction ) // fn to determine direction of any port
{
	switch (portName)
	{
		case 'A':
		case 'a':
		{
		  GPIO_PORTA_DIR_R = direction;
		}
			break;
		
		case 'B':
		case 'b':
		{
		GPIO_PORTB_DIR_R = direction;
	  }
			break;  
		
		case 'C':
		case 'c':
		{		 
		GPIO_PORTC_DIR_R = direction;
		}	
			break;  
		
		case 'D':
		case 'd':
		{	
	  GPIO_PORTD_DIR_R = direction;
		}	
			break;  
		
		case 'E':
		case 'e':
		{	
	  GPIO_PORTE_DIR_R = direction;
		}	
			break;  
		
		case 'F':
		case 'f':
		{	
	  GPIO_PORTF_DIR_R = direction;
		}	
			break;  
	}
}


void DIO_writePort( unsigned char portName, unsigned char data) // to write in any port
{ 
	switch(portName)
	{
		case'A':
		case'a':
		{
		 GPIO_PORTA_DATA_R = data;
		}
		break;
		case'B':
		case'b':
		{
		 GPIO_PORTB_DATA_R = data;
		}
			break;
		case'C':
		case'c':
		{ 
		GPIO_PORTC_DATA_R = data;
		}
			break;
		case'D':
		case'd':
		{ 
		GPIO_PORTD_DATA_R = data;
		}
			break;
		case'E':
		case'e':
		{ 
		GPIO_PORTE_DATA_R = data;
		}
			break;
		case'F':
		case'f':
		{ 
		GPIO_PORTF_DATA_R = data;
		}
		break;
	}
}




unsigned char DIO_u8ReadPort( unsigned char portName) // to read from any port
{ 
	switch ( portName)
	{ 
		case'A':
		case'a':
		{
		return GPIO_PORTA_DATA_R;
		}
		
		case'B':
		case'b':
		{
		return GPIO_PORTB_DATA_R;
		}
		
		case'C':
		case'c':		
		{
		return GPIO_PORTC_DATA_R;
		}
		
		case'D':
		case'd':
		{
		return GPIO_PORTD_DATA_R;
		}
		
		case'E':
		case'e':
		{
		return GPIO_PORTE_DATA_R;
		}
		
		case'F':
		case'f':
		{
		return GPIO_PORTF_DATA_R;
		}
		
	}
	return 0;
}




void DIO_enablePullUp( unsigned char portName, unsigned char pinNo ) // to enable the pull up resistor of any pin of any port
{
	switch(portName)
	{ 
		case'A': 
		case'a':
		{
		SET_BIT ( GPIO_PORTA_PUR_R, pinNo );
		}
			break;
		case'B': 
		case'b':
		{ 
		SET_BIT ( GPIO_PORTB_PUR_R, pinNo );
		}
			break;
		case'C':
    case'c':			
		{ 
		SET_BIT ( GPIO_PORTC_PUR_R, pinNo );
		}
			break;
		case'D': 
		case'd':
		{ 
		SET_BIT ( GPIO_PORTD_PUR_R, pinNo );
		}
			break;
		case'E': 
		case'e':
		{ 
		SET_BIT ( GPIO_PORTE_PUR_R, pinNo );
		}
			break;
		case'F': 
		case'f':
		{ 
		SET_BIT ( GPIO_PORTF_PUR_R, pinNo );
		}
			break;
	}
}





void DIO_u8WriteHighNibble ( unsigned char portName, unsigned char data) // to write in the bits 4-7.
{
	data<<=4;
	switch (portName)
	{ 
		case'A':
		case'a':
		{ 
		GPIO_PORTA_DATA_R &= 0X0F;
			GPIO_PORTA_DATA_R |= data ;
	} 
		break;
		case'B':
		case'b':
		{ 
		GPIO_PORTB_DATA_R &= 0X0F;
			GPIO_PORTB_DATA_R |= data ;
	} 
		break;
		case'C':
		case'c':
		{ 
		GPIO_PORTC_DATA_R &= 0X0F;
			GPIO_PORTC_DATA_R |= data ;
	} 
		break;
		case'D':
		case'd':
		{ 
		GPIO_PORTD_DATA_R &= 0X0F;
			GPIO_PORTD_DATA_R |= data ;
	} 
		break;
		case'E':
		case'e':
		{ 
		GPIO_PORTE_DATA_R &= 0X0F;
			GPIO_PORTE_DATA_R |= data ;
	} 
		break;
		case'F':
		case'f':
		{ 
		GPIO_PORTF_DATA_R &= 0X0F;
			GPIO_PORTF_DATA_R |= data ;
	} 
		break;
	}
}



void DIO_u8WriteLowNibble ( unsigned char portName, unsigned char data) // write in the 0-3 bits
{

	switch (portName)
	{ 
		case 'A':
		case 'a':
		{	
		GPIO_PORTA_DATA_R &= 0XF0;
			GPIO_PORTA_DATA_R |= data ;
	}		
		break;
		case'B':
		case'b':
		{		
		GPIO_PORTB_DATA_R &= 0XF0;
			GPIO_PORTB_DATA_R |= data ;
	} 
		break;
		case'C':
		case'c':
		{
		 GPIO_PORTC_DATA_R &= 0XF0;
			GPIO_PORTC_DATA_R |= data ;
	} 
		break;
		case'D':
		case'd':
		{ 
		GPIO_PORTD_DATA_R &= 0XF0;
			GPIO_PORTD_DATA_R |= data ;
	} 
		break;
		case'E':
		case'e':
		{ 
		GPIO_PORTE_DATA_R &= 0XF0;
			GPIO_PORTE_DATA_R |= data ;
	} 
		break;
		case'F':
		case'f':
		{ 
		GPIO_PORTF_DATA_R &= 0XF0;
			GPIO_PORTF_DATA_R |= data ;
	} 
		break;
	}
}

