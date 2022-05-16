//this is our project main file
#include "tm4c123gh6pm.h"
#include "driver.c"

enum states { IDLE, StandBy_Weight, StandBy_Time, Cooking, PauseCooking, StopCooking, CompleteCooking};

// dont forget to intialize variables at each state for example in IDLE most if not all variables should be intialized with 0
void Microwave_Control(){
int state = IDLE;// variable state to select next state intialized to start at IDLE
  while(1){
  switch (state){
  
		case IDLE:
   // IDLE case code    
   
      
    break;  
   case StandBy_Weight:  
   // StandBy_Weight case code 
   
      
     break; 
    case StandBy_Time:  
   //StandBy_Time case code 
      
      
      break;
    case Cooking:
     //Cooking case  code
      
      
      break;
   case PauseCooking:
    //PauseCooking case code
      
      
      break;
   case StopCooking:
   //StopCooking case code
      
      
      break;
   case CompleteCooking:
     //CompleteCooking case code 
      
      
      break;

       }
  }
}
