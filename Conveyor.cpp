#include "vex.h"
#include "Conveyor.h"
int sT = 2;
bool toggll = true;

void ConveyorControl(){
  // if(Controller1.ButtonR2.pressing()){
  //   Conveyor.spin(fwd,100,pct);
  // }else if(Controller1.ButtonR1.pressing()){
  //   Conveyor.spin(fwd,-100,pct);
  // }
  // else Conveyor.stop();

if(Controller1.ButtonR1.pressing()and toggll){
  if (sT==1){
    // Conveyor.spin(fwd,-100,pct);
    sT=2;
  }
  else if (sT==2){
    // Conveyor.stop();
    sT=1;
  }
    toggll=false;
  }
  else if (!Controller1.ButtonR1.pressing()){
    toggll=true;
  }

if(Controller1.ButtonR2.pressing()){
    Conveyor.spin(fwd,85,pct);
  }
  else if (sT==1){
    Conveyor.spin(fwd,-100,pct);
  }
  
  else if (sT==2){
    Conveyor.stop();
  }
  
}