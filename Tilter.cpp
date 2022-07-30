#include "Tilter.h"
#include "vex.h"
#include <iostream>
int st = 1;
bool toggle = true;
int target;
bool once = true;
double convert(float pos){
  return (7/3.0)*pos;
}
void TilterControl(){

if(Controller1.ButtonL1.pressing()and toggle){
  if (st==1){
    TilterJaw.off();
    wait(150,msec);
    Tilter.on();
    st=2;
  }
  else if (st==2){
    Tilter.off();
    wait(300,msec);
    TilterJaw.on();
    st=1;
  }
    toggle=false;
  }
  else if (!Controller1.ButtonL1.pressing()){
    toggle=true;
  }
  }

// if(once){
//   if(st==1){
//     TilterJaw.off();
//     Tilter.off();
  
//   }
//   else if(st==2){
//     Tilter.on();
//     TilterJaw.on();
    
//   }
  
//   }
//   once = false;

 
//   if (Controller1.ButtonL1.pressing() and toggle){
//     std::cout<<"i got here \n";
//   if(st!=2){
//     st=2;
//   }
//   else{
//     st=1;
//   }
//   once = true;
//   toggle = false;
//   }
//   else if(!Controller1.ButtonL1.pressing()){
//     toggle = true;
//   }
 

// }

