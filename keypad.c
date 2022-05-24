#include "TM4C123.h"  
#include "drivers_headers_new.h"

#define KEYPAD_ROW GPIOE
#define KEYPAD_COL GPIOA
 
/* this function initializes the ports connected to the keypad */
void keypad_Init(void)
{
SYSCTL->RCGCGPIO |= 0x01; /* enable clock to GPIOA */
SYSCTL->RCGCGPIO |= 0x10; /* enable clock to GPIOE */
 
KEYPAD_ROW->DIR |= 0x0F; /* set row pins 3-0 as output */
KEYPAD_ROW->DEN |= 0x0F; /* set row pins 3-0 as digital pins */
KEYPAD_ROW->ODR |= 0x0F; /* set row pins 3-0 as open drain */
 
KEYPAD_COL->DIR &= ~0xF0; /* set column pin 7-4 as input */
KEYPAD_COL->DEN |= 0xF0; /* set column pin 7-4 as digital pins */
KEYPAD_COL->PUR |= 0xF0; /* enable pull-ups for pin 7-4 */
}
 
/* This is a non-blocking function to read the keypad. */
/* If a key is pressed, it returns the key label in ASCII encoding. Otherwise, it returns a 0 (not ASCII 0). */
unsigned char KEYPAD_u8Read(void)
{
const unsigned char keymap[4][4] = {
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};
 
int row, col;
 
/* check to see any key pressed first */
KEYPAD_ROW->DATA = 0; /* enable all rows */
col = KEYPAD_COL->DATA & 0xF0; /* read all columns */
if (col == 0xF0) return 0; /* no key pressed */
 
/* If a key is pressed, it gets here to find out which key. */
/* Although it is written as an infinite loop, it will take one of the breaks or return in one pass.*/
while (1)
{
row = 0;
KEYPAD_ROW->DATA = 0x0E; /* enable row 0 */
delayUs(2); /* wait for signal to settle */
col = KEYPAD_COL->DATA & 0xF0;
if (col != 0xF0) break;
 
row = 1;
KEYPAD_ROW->DATA = 0x0D; /* enable row 1 */
delayUs(2); /* wait for signal to settle */
col = KEYPAD_COL->DATA & 0xF0;
if (col != 0xF0) break;
 
row = 2;
KEYPAD_ROW->DATA = 0x0B; /* enable row 2 */
delayUs(2); /* wait for signal to settle */
col = KEYPAD_COL->DATA & 0xF0;
if (col != 0xF0) break;
 
row = 3;
KEYPAD_ROW->DATA = 0x07; /* enable row 3 */
delayUs(2); /* wait for signal to settle */
col = KEYPAD_COL->DATA & 0xF0;
if (col != 0xF0) break;
 
return 0; /* if no key is pressed */
}
 
/* gets here when one of the rows has key pressed */
if (col == 0xE0) return keymap[row][0]; /* key in column 0 */
if (col == 0xD0) return keymap[row][1]; /* key in column 1 */
if (col == 0xB0) return keymap[row][2]; /* key in column 2 */
if (col == 0x70) return keymap[row][3]; /* key in column 3 */
return 0; /* just to be safe */
}
unsigned char keypad_kbhit(void)
{
int col;
 
/* check to see any key pressed */
KEYPAD_ROW->DATA = 0; /* enable all rows */
col = KEYPAD_COL->DATA & 0xF0; /* read all columns */
if (col == 0xF0)
return '0'; /* no key pressed */
else
return '1'; /* a key is pressed */
}

