#include "DIO_Header.h"
#include "LCD_config.h"
#include "delays.h"

enum ctrl{E, Rs, Rw};


static void Send_Pulse(void){	//pulse sent to enable
	DIO_vwrite_PIN(CTRL_PORT,E ,1);
	genericDelay(2);
	DIO_vwrite_PIN(CTRL_PORT,E ,0);
	genericDelay(2);
}
void LCD_Vsend_CMD(char cmd){	
	DIO_writePort(Data_PORT, cmd);
	DIO_vwrite_PIN(CTRL_PORT, Rs ,0);
	Send_Pulse();
	genericDelay(1);
}

void LCD_Vsend_charac(char charac){
	DIO_writePort(Data_PORT, charac);
	DIO_vwrite_PIN(CTRL_PORT, Rs ,1);
	Send_Pulse();
	genericDelay(1);
}

void LCD_Vsend_String(char *data){
	while((*data)!= ('\0')){
		LCD_Vsend_charac((*data));
		data++;
	}
}

void LCD_CLR_Screen(){
	LCD_Vsend_CMD(CLR_Screen);
	genericDelay(10);
}

void LCD_Move_Cursor(char row, char col){	//command to move cursor to a certain position
	char pos = 0;
	if (row == 1)
		pos = (0x80) +col-1;
	else if (row ==2)
		pos = (0xC0) +col-1;
	else
		pos = 0x80;
	
	LCD_Vsend_CMD(pos);
	genericDelay(1);	
}

void LCD_vInit(void){
	DIO_setPortDir (Data_PORT, 0xFF);
	DIO_vport_dir (CTRL_PORT, E, 1);
	DIO_vport_dir (CTRL_PORT, Rs, 1);
	DIO_vport_dir (CTRL_PORT, Rw, 1);
	DIO_vwrite_PIN(CTRL_PORT, Rw,0);
	
	LCD_Vsend_CMD(Eight_Bit);
	genericDelay(1);
	
	LCD_Vsend_CMD(Turn_On);
	genericDelay(1);
	
	LCD_Vsend_CMD(CLR_Screen);
	genericDelay(10);
	
	LCD_Vsend_CMD(Entry_Mode);
	genericDelay(1);
}
