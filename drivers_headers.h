#include "stdint.h"
unsigned char pauseCooking(void);
//LCD_Driver

static void Send_Pulse(void);
void LCD_Vsend_CMD(unsigned char cmd);
void LCD_Vsend_charac(unsigned char charac);
void LCD_Vsend_String(unsigned char *data);
void LCD_CLR_Screen();
void LCD_Move_Cursor(unsigned char row, unsigned char col);
void LCD_vInit(void);

// switches and Leds drivers
//switches
void Switch_Init();
unsigned char readSW1();
unsigned char readSW2();
unsigned char readSW3();
void Switch_Init_Pullup();
//Buzzer
void Buzzer_vInit(void);
void Buzzer_On();
void Buzzer_Off(void);
void Buzzer_Toggle();
//Leds
void Led_Array_vInit(void);
void Led_Array_On();
void Led_Array_Off(void);
void Led_Array_Toggle();
void Blink (unsigned char blinks);

//delay 

void SysTic_wait(unsigned long delay);
void generic_Delay(unsigned long time); //delay in millisec
unsigned char Cooking_Countdown (unsigned char *cooking_Time);

//DIO driver
void port_init (unsigned char port);
void DIO_vpin_dir (unsigned char port, unsigned char pin, unsigned char dir);
void DIO_vwrite_PIN(unsigned char port_name, unsigned char DATA ,unsigned char pin_number);
void DIO_vtoggle_PIN(unsigned char port_name ,unsigned char pin_number);
unsigned char DIO_u8READ_PIN(unsigned char port_name ,unsigned char pin_number);
void DIO_setPortDir( unsigned char portName, unsigned char direction );
void DIO_writePort( unsigned char portName, unsigned char data);
unsigned char DIO_u8ReadPort( unsigned char portName);
void DIO_enablePullUp( unsigned char portName, unsigned char pinNo );
void DIO_u8WriteHighNibble ( unsigned char portName, unsigned char data);
void DIO_u8WriteLowNibble ( unsigned char portName, unsigned char data);

//Checkers
unsigned char Is_Valid	(unsigned int min, unsigned int max, unsigned int number); //false =0 true 1
void convert_to_array(unsigned int t, unsigned char* Atime);
void print_Err();
uint16_t time_sum (char *t);
void shift_arr(char *t);

//Keypad
unsigned char KEYPAD_u8Read();
void KeyPad_vInit();
