#include "vex.h"
#include "Intake.h"
int sT = 2;
bool toggll = true;

void IntakeControl(){
  
if(Controller1.ButtonL1.pressing()and toggll){
  if (sT==1){
    sT=2;
  }
  else if (sT==2){
    sT=1;
  }
    toggll=false;
  }
  else if (!Controller1.ButtonL1.pressing()){
    toggll=true;
  }

if(Controller1.ButtonL2.pressing()){
    Intake.spin(fwd,100,pct);
  }
  else if (sT==1){
    Intake.spin(fwd,-100,pct);
  }
  
  else if (sT==2){
    Intake.stop();
  }
  
}