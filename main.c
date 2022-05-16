// this is our project main file
#include "tm4c123gh6pm.h"
#include "driver.c"

#define IDLE0
#define StandBy_Weight1
#define StandBy_Time2
#define Cooking3
#define PauseCooking4
#define StopCooking5
#define CompleteCooking6

void Microwave_Control(){
int state = IDLE;// variable state to select next state intialized to start at IDLE
  while(1){
  switch (state){
  
  IDLE:
   // IDLE case code    
   
      
    break;  
   StandBy_Weight:  
   // StandBy_Weight case code 
   
      
     break; 
    StandBy_Time:  
   //StandBy_Time case code 
      
      
      break;
    Cooking:
     //Cooking case  code
      
      
      break;
   PauseCooking:
    //PauseCooking case code
      
      
      break;
   StopCooking:
   //StopCooking case code
      
      
      break;
   CompleteCooking:
     //CompleteCooking case code 
      
      
      break;

       }
  }
}
