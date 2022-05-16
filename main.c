#include "tm4c123gh6pm.h"
#include "driver.c"

#define IDLE 0
#define StandBy_Weight 1
#define StandBy_Time 2
#define Cooking 3
#define PauseCooking 4
#define StopCooking 5
#define CompleteCooking 6

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
