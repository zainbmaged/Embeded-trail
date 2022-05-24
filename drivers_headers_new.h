#include "stdint.h"

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

//lcd drivers
//Functions Declaration
void delayUs(int);   														   //Delay in Micro Seconds
void delayMs(int);   														   //Delay in Milli Seconds
void LCD4bits_Init(void);													 //Initialization of LCD Dispaly
void LCD_Write4bits(unsigned char, unsigned char); //Write data as (4 bits) on LCD
void LCD_Vsend_String(unsigned char*);											 //Write a string on LCD 
void LCD4bits_Cmd(unsigned char);									 //Write command 
void LCD4bits_Data(unsigned char);								 //Write a character
void LCD_CLR_Screen(void);

//keypad drivers
void keypad_Init(void);
unsigned char keypad_kbhit(void);
void keypad_init(void);
unsigned char KEYPAD_u8Read(void);

// switches and Leds drivers
//switches
void Switch_Init(void);
unsigned char readSW1(void);
unsigned char readSW2(void);
unsigned char readSW3(void);
void Switch_Init_Pullup(void);
//Buzzer
void Buzzer_vInit(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Toggle(void);
//Leds
void Led_Array_vInit(void);
void Led_Array_On(void);
void Led_Array_Off(void);
void Led_Array_Toggle(void);
void Blink (unsigned char blinks);

//delay 

unsigned char Cooking_Countdown ( unsigned char *cooking_Time);

//Checkers
unsigned char Is_Valid	(unsigned char min, unsigned char max, unsigned char number); //false =0 true 1
void convert_to_array(unsigned int t, unsigned char* Atime);
void print_Err(void);
uint16_t time_sum (unsigned char *t);
void shift_arr(unsigned char *t);
unsigned char pauseCooking(void);
