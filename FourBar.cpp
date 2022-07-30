#include "vex.h"
#include "FourBar.h"
int St = 2;
bool Toggle = true;
void FourBarControl(){
  if(Controller1.ButtonL2.pressing()and Toggle){
  if (St==1){
    FourbarJaw.off();
    St=2;
  }
  else if (St==2){
    FourbarJaw.on();
    St=1;
  }
    Toggle=false;
  }
  else if (!Controller1.ButtonL2.pressing()){
    Toggle=true;
  }

  Fourbar.setStopping(hold);
  
  Fourbar.spin(forward,Controller1.Axis2.value(),pct);

  }
  