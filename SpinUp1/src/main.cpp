/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Gyro                 inertial      1               
// RBD                  motor         2               
// RFD                  motor         3               
// RTD                  motor         4               
// LFD                  motor         5               
// LTD                  motor         6               
// LBD                  motor         7               
// Flywheel             motor         8               
// Intake               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
int routine = 0;
int Target;
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void BrainMessage(const char Billy[100], int Joe, int Tod, color Bob,fontType josh){
  Brain.Screen.setFont(josh);
  Brain.Screen.setCursor(Joe,Tod);
  Brain.Screen.setPenColor(Bob);
  Brain.Screen.clearScreen();
  Brain.Screen.print(Billy);
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  std::cout<<Brain.Battery.capacity()<<std::endl;
  //Gyro_Calibrate();
  // if(Gyro_Stable(5))
  Controller1.rumble("...");
  while(true){
    if(routine == 1){
      BrainMessage("Auton1",2,1,red,monoXXL);
    }else if(routine == 2){
      BrainMessage("Auton2",2,1,red,monoXL);
    }else if(routine == 3){
      BrainMessage("Prog",2,1,red,monoXXL);
    }
  else
      BrainMessage(" ",2,1,red,monoXXL);
    if(Brain.Screen.pressing()){
      routine++;
    
      if(routine > 11){
        routine = 1;
      }
      waitUntil(!Brain.Screen.pressing());
    }
    wait(30,msec);
}
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void Auton1(){

}

void Auton2(){

}

void Prog(){

}

void autonomous(void) {
  Brain.Timer.reset();
  if(routine == 1){
   Auton1();
}else if(routine ==2){
  Auton2();
}else if(routine ==3){
  Prog();
}
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print(Brain.Timer.time(seconds));
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
