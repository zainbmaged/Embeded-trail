//this file is our C projet code 
//the driver code

//the macros used please use same names
#define SET_BIT(reg,bit)     (reg|= (1<<bit))
#define CLR_BIT(reg,bit)     (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)      (reg^=(1<<bit))
#define READ_BIT(reg,bit)     (reg&(1<<bit)>>bit)

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

