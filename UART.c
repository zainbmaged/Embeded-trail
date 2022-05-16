
// intialize UART Protocol
void UART_init (unsigned char num)
{
	switch(num) 
	{
		case '0':
		SET_BIT(SYSCTL_RCGCUART_R, SYSCTL_RCGCUART_R0);
		UART0_CTL_R &= ~ UART_CTL_UARTEN;
		UART0_IBRD_R = 104;  
		UART0_FBRD_R = 11;
		UART0_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART0_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		break;
		
		case '1':
		SET_BIT(SYSCTL_RCGCUART_R, SYSCTL_RCGCUART_R1);
		UART1_CTL_R &= ~ UART_CTL_UARTEN;
		UART1_IBRD_R = 104;  
		UART1_FBRD_R = 11;
		UART1_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART1_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		break;
		
		case '2':
		SET_BIT(SYSCTL_RCGCUART_R, SYSCTL_RCGCUART_R2);
		UART2_CTL_R &= ~ UART_CTL_UARTEN;
		UART2_IBRD_R = 104;  
		UART2_FBRD_R = 11;
		UART2_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART2_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		
		break;
		
		case '3':
		SET_BIT(SYSCTL_RCGCUART_R, SYSCTL_RCGCUART_R3);
		UART3_CTL_R &= ~ UART_CTL_UARTEN;
		UART3_IBRD_R = 104;  
		UART3_FBRD_R = 11;
		UART3_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART3_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		
		break;
		
		case '4':
		SET_BIT(SYSCTL_RCGCUART_R, SYSCTL_RCGCUART_R4);
		UART4_CTL_R &= ~ UART_CTL_UARTEN;
		UART4_IBRD_R = 104;  
		UART4_FBRD_R = 11;
		UART4_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART4_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		
		break;
		
		case '5':
		SET_BIT(SYSCTL_RCGCUART_R, SYSCTL_RCGCUART_R5);
		UART5_CTL_R &= ~ UART_CTL_UARTEN;
		UART5_IBRD_R = 104;  
		UART5_FBRD_R = 11;
		UART5_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART5_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		
		break;
	}
}

// check fifo availability for read or write 
unsigned char UART_fifo_check (unsigned char num)
{
	switch(num) 
	{
		case '0':
		return ((UART0_FR_R &UART_FR_RXFE)==UART_FR_RXFE)? 0:1;

		break;
				
		case '1':
		return ((UART1_FR_R &UART_FR_RXFE)==UART_FR_RXFE)? 0:1;
		
		break;		

		case '2':
		return ((UART2_FR_R &UART_FR_RXFE)==UART_FR_RXFE)? 0:1;
		
		break;
		
		case '3':
		return ((UART3_FR_R &UART_FR_RXFE)==UART_FR_RXFE)? 0:1;
		
		break;
		
		case '4':
		return ((UART4_FR_R &UART_FR_RXFE)==UART_FR_RXFE)? 0:1;
		
		break;
		
		case '5':
		return ((UART5_FR_R &UART_FR_RXFE)==UART_FR_RXFE)? 0:1;
		
		
		break;
	}
}


// Read Data from UART(num) port 
char UART_read (unsigned char num)
{
	switch(num) 
	{
		case '0':
		while(UART_fifo_check(num) !=1){};
		return (char) (UART0_DR_R & 0xFF);
		
		break;
		
		case '1':
		while(UART_fifo_check(num) !=1){};
		return (char) (UART1_DR_R & 0xFF);
		
		break;		

		case '2':
		while(UART_fifo_check(num) !=1){};
		return (char) (UART2_DR_R & 0xFF);
		
		break;
		
		case '3':
		while(UART_fifo_check(num) !=1){};
		return (char) (UART3_DR_R & 0xFF);
		
		break;
		
		case '4':
		while(UART_fifo_check(num) !=1){};
		return (char) (UART4_DR_R & 0xFF);
		
		break;
		
		case '5':
		while(UART_fifo_check(num) !=1){};
		return (char) (UART5_DR_R & 0xFF);
		
		
		break;
	}
}

// write data in UART(num) port
void UART_write (unsigned char num, unsigned char data)
{
	switch(num) 
	{
		case '0':
		while((UART0_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
		UART0_DR_R = data;

		break;
		
		case '1':
		while((UART1_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
		UART1_DR_R = data;
		
		break;		

		case '2':
		while((UART2_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
		UART2_DR_R = data;
		
		break;
		
		case '3':
		while((UART3_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
		UART3_DR_R = data;
		
		break;
		
		case '4':
		while((UART4_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
		UART4_DR_R = data;
		
		break;
		
		case '5':
		while((UART5_FR_R & UART_FR_TXFF)==UART_FR_TXFF){};
		UART5_DR_R = data;
		
		
		break;
	}
}


//recieve data and write(echo) it in UART(num) port 
void getCommand(char *str, uint8_t maxLen, unsigned char num ){
 		char c;
		int8_t i;
		for(i =0;i<maxLen;i++)
		{
			c = UART_read(num);
    		if(c=='\n' || c=='\r')
		{
		 	break;
  		}
    		else str[i]=c;
    		UART_write(c, num);
		}

//function that prints any onscreen message
void printstr(char *str, unsigned char num)
		{
  		while(*str){
    		UART_write(num, *str);
    		str++;
  		}
}
