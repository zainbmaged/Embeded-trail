//this file is our C projet code 
//the driver code

//the macros used please use same names
#define SET_BIT(reg,bit)     (reg|= (1<<bit))
#define CLR_BIT(reg,bit)     (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)      (reg^=(1<<bit))
#define READ_BIT(reg,bit)     (reg&(1<<bit)>>bit)




enum dir {input, output}; //input=0, output=1

//port initialization
void port_init (unsigned char port)
{
	switch(port) 
	{
		case "A":
		case "a":
		SET_BIT(SYSCTL_RCGCGPIO_R,0);
		while (READ_BIT(SYSCTL_PRGPIO_R,0) == 0);
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0xFF;
		GPIO_PORTA_DEN_R = 0xFF;
		break;
		
		case "B":
		case "b":
		SET_BIT(SYSCTL_RCGCGPIO_R,1);
		while (READ_BIT(SYSCTL_PRGPIO_R,1) == 0);
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTB_CR_R |= 0xFF;
		GPIO_PORTB_DEN_R = 0xFF;
		break;
		
		case "C":
		case "c":
		SET_BIT(SYSCTL_RCGCGPIO_R,2);
		while (READ_BIT(SYSCTL_PRGPIO_R,2) == 0);
		GPIO_PORTC_LOCK_R = 0x4C4F434B;
		GPIO_PORTC_CR_R |= 0xFF;
		GPIO_PORTC_DEN_R = 0xFF;
		break;
		
		case "D":
		case "d":
		SET_BIT(SYSCTL_RCGCGPIO_R,3);
		while (READ_BIT(SYSCTL_PRGPIO_R,3) == 0);
		GPIO_PORTD_LOCK_R = 0x4C4F434B;
		GPIO_PORTD_CR_R |= 0xFF;
		GPIO_PORTD_DEN_R = 0xFF;
		break;
		
		case "E":
		case "e":
		SET_BIT(SYSCTL_RCGCGPIO_R,4);
		while (READ_BIT(SYSCTL_PRGPIO_R,4) == 0);
		GPIO_PORTE_LOCK_R = 0x4C4F434B;
		GPIO_PORTE_CR_R |= 0xFF;
		GPIO_PORTE_DEN_R = 0xFF;
		break;
		
		case "F":
		case "f":
		SET_BIT(SYSCTL_RCGCGPIO_R,5);
		while (READ_BIT(SYSCTL_PRGPIO_R,5) == 0);
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0xFF;
		GPIO_PORTF_DEN_R = 0xFF;
		break;
	}
	
//set port direction	
void DIO_vport_dir (unsigned char port, unsigned char pin, unsigned char dir)
{
	switch (port)
	{
		case "A":
		case "a":
			if (dir == input) //dir=0
			{
				CLR_BIT(GPIO_PORTA_DIR_R, pin)
			}
			if (dir == output) //dir=1
			{
				SET_BIT(GPIO_PORTA_DIR_R, pin)
			}
		break:
		case "B":
		case "b":
			if (dir == input) //dir=0
			{
				CLR_BIT(GPIO_PORTB_DIR_R, pin)
			}
			if (dir == output) //dir=1
			{
				SET_BIT(GPIO_PORTB_DIR_R, pin)
			}
			break:
		case "C":
		case "c":
			if (dir == input) //dir=0
			{
				CLR_BIT(GPIO_PORTC_DIR_R, pin)
			}
			if (dir == output) //dir=1
			{
				SET_BIT(GPIO_PORTC_DIR_R, pin)
			}
			break:
		case "D":
		case "d":
			if (dir == input) //dir=0
			{
				CLR_BIT(GPIO_PORTD_DIR_R, pin)
			}
			if (dir == output) //dir=1
			{
				SET_BIT(GPIO_PORTD_DIR_R, pin)
			}
			break:
		case "E":
		case "e":
			if (dir == input) //dir=0
			{
				CLR_BIT(GPIO_PORTE_DIR_R, pin)
			}
			if (dir == output) //dir=1
			{
				SET_BIT(GPIO_PORTE_DIR_R, pin)
			}
			break:
		case "F":
		case "f":
			if (dir == input) //dir=0
			{
				CLR_BIT(GPIO_PORTF_DIR_R, pin)
			}
			if (dir == output) //dir=1
			{
				SET_BIT(GPIO_PORTF_DIR_R, pin)
			}
			break:
								
		}
	}
}



// void fuction to read data from one pin
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
		 
		  //for portB
		 case 'B':
		 case 'b':
		 {
        if(DATA==1)
				{SET_BIT(GPIO_PORTB_DATA_R,pin_number);}
				else
					CLR_BIT(GPIO_PORTB_DIR_R,pin_number);
		 } 
		 
		  //for portC
		 case 'C':
		 case 'c':
		 {
        if(DATA==1)
				{SET_BIT(GPIO_PORTC_DATA_R,pin_number);}
				else
					CLR_BIT(GPIO_PORTC_DIR_R,pin_number);
		 } 
		  //for portD
		 case 'D':
		 case 'd':
		 {
        if(DATA==1)
				{SET_BIT(GPIO_PORTD_DATA_R,pin_number);}
				else
					CLR_BIT(GPIO_PORTD_DIR_R,pin_number);
		 } 
		  //for portE
		 case 'E':
		 case 'e':
		 {
        if(DATA==1)
				{SET_BIT(GPIO_PORTE_DATA_R,pin_number);}
				else
					CLR_BIT(GPIO_PORTE_DIR_R,pin_number);
		 } 
		  //for portF
		 case 'F':
		 case 'f':
		 {
        if(DATA==1)
				{SET_BIT(GPIO_PORTF_DATA_R,pin_number);}
				else
					CLR_BIT(GPIO_PORTF_DIR_R,pin_number);
		 } 
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
		 
		  //for portB
		 case 'B':
		 case 'b':
		  {
       
				TOG_BIT(GPIO_PORTB_DATA_R,pin_number);
				
		 } 
		 
		  //for portC
		 case 'C':
		 case 'c':
		 {
       
				TOG_BIT(GPIO_PORTC_DATA_R,pin_number);
				
		 } 
		  //for portD
		 case 'D':
		 case 'd':
		 {
       
				TOG_BIT(GPIO_PORTD_DATA_R,pin_number);
				
		 } 
		  //for portE
		 case 'E':
		 case 'e':
		  {
       
				TOG_BIT(GPIO_PORTE_DATA_R,pin_number);
				
		 } 
		  //for portF
		 case 'F':
		 case 'f':
		  {
       
				TOG_BIT(GPIO_PORTF_DATA_R,pin_number);
				
		 }  
	 }
}

// fuction to return the data written on one pin
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

