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
// RBD                  motor         7               
// RTD                  motor         1               
// RFD                  motor         5               
// LBD                  motor         10              
// LTD                  motor         11              
// LFD                  motor         9               
// Fourbar              motor         3               
// Conveyor             motor         20              
// FourbarDistance      distance      2               
// Tilter               led           G               
// TilterJaw            led           H               
// FourbarJaw           led           F               
// Controller1          controller                    
// Gyro                 inertial      6               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"


using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
int routine = 0; 
int Target;
int ST;
int stat = 1;
bool togl = true;
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
    FourbarJaw.off();
    Tilter.off();
    TilterJaw.on();
    // Stick.on();
  std::cout<<Brain.Battery.capacity()<<std::endl;
  Gyro_Calibrate();
  if(Gyro_Stable(5))
  Controller1.rumble("...");
  while(true){
    if(routine == 1){
      BrainMessage("AWP",2,1,red,monoXXL);
    }else if(routine == 2){
      BrainMessage("LeftGoalSnatch",2,1,red,monoXL);
    }else if(routine == 3){
      BrainMessage("RightGoalSnatch",2,1,red,monoXXL);
    }else if(routine == 4){
      BrainMessage("CenterGoalSnatch",2,1,red,monoXXL);
    }else if(routine == 5){
      BrainMessage("Prog",2,1,red,monoXXL);
    }else if(routine == 6){
      BrainMessage("LeftOscillate",2,1,red,monoXXL);
    }else if(routine == 7){
      BrainMessage("RightOscillate",2,1,red,monoXXL);
    }else if(routine == 8){
      BrainMessage("SafeAWP",2,1,red,monoXXL);
    }else if(routine == 9){
      BrainMessage("RightElims",2,1,red,monoXXL);
    }else if(routine == 10){
      BrainMessage("LeftElims",2,1,red,monoXXL);
    }else if(routine == 11){
      BrainMessage("CenterElims",2,1,red,monoXXL);
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
void fourbar(int delay,int speed){
  Fourbar.spin(forward,speed,percent);
  wait(delay,msec);
  Fourbar.stop(hold);
}

void tilter(int ST){
  if (ST==1){
    TilterJaw.off();
    wait(100,msec);
    Tilter.on();
  }
  else if(ST==2){
    Tilter.off();
    TilterJaw.on();
  }
 
}

void conveyor(int speed){
  Conveyor.spin(reverse,speed,pct);
}

void deploy(){
  Fourbar.startRotateFor(fwd,60,degrees);
  FourbarJaw.on();
}

void fourbarjawclamp(){
  FourbarJaw.off();
}
void stopdrive(){
  LFD.stop();
  RFD.stop();
  RBD.stop();
  LBD.stop();
  LTD.stop();
  RTD.stop();
}

void fourbarjawrelease(){
  FourbarJaw.on();
}
void startPos(int startAngle){
  Gyro.setRotation(startAngle,vex::rotationUnits::deg);
}

void RightOscillate(){
  deploy();
  TilterJaw.on();
  wait(300,msec);
  Fourbar.startRotateFor(500,degrees);
  translate(-15,1);
  wait(500,msec);
  tilter(1);
  conveyor(100);
  translate(17,4);
  translate(-17,4);
  translate(17,4);
  translate(-17,4);
  translate(17,4);
  translate(-17,4);
  translate(17,4);
  translate(-17,4);
  translate(17,4);
  translate(-17,4);
  translate(17,4);
  tilter(2);
}

void AWP(){
startPos(0);
// deploy();
FourbarJaw.on();
TilterJaw.on();
wait(100,msec);
translate(-7,100,2,false,1.2);
tilter(1);
wait(50,msec);
translate(8);
fourbar(250,100);
Turn_cap(130,5);
Fourbar.startRotateFor(forward,300,degrees);
conveyor(100);
translate(31);
Turn(180);
translate(35);
tilter(2);
wait(75,msec);
TilterJaw.on();
Turn_cap(195,5);
translate(12,5);
Conveyor.spin(reverse,-12,volt);
Turn_cap(22,4);//Turn to goal
setDrive(-8,-8);
wait(800,msec);
setDrive(0,0);
// setDrive(-6,-6);
// wait(300,msec);
// setDrive(0,0);
wait(100,msec);
tilter(1);
Conveyor.spin(reverse,12,volt);
translate(5);
Turn_cap(87,7,5);
translate(32,5);
conveyor(-50);
Turn_cap(180,5,5);
conveyor(100);
setDrive(6,6);
wait(500,msec);
setDrive(0,0);
// translate(13,5);
translate(-8);
Turn_cap(135,8);
translate(-18);
tilter(2);
}

void SafeAWP(){
  startPos(0);
  deploy();
  translate(-6,100,2,false,1.2);
  TilterJaw.off();
  wait(50,msec);
  TilterJaw.on();
  wait(50,msec);
  translate(8);
  fourbar(250,100);
  Turn_cap(310,5);
  Fourbar.startRotateFor(forward,200,degrees);
  translate(-22);
  Turn_cap(5,3);
  translate(-70);
  wait(50,msec);
  setDrive(-6,-6);
  wait(500,msec);
  setDrive(0,0);
  wait(100,msec);
  TilterJaw.off();
  wait(150,msec);
  Tilter.on();
  wait(100,msec);
  conveyor (100);
  translate(10);
  Turn_cap(22,5);
  wait(50,msec);
  translate(39,5);
  wait(250,msec);
  Turn_cap(90,5);
  wait(50,msec);
  tilter(2);
  wait(50,msec);
  translate(-6);
  fourbar(800,-100);
  wait(50,msec);
  translate(13);
  wait(50,msec);
  fourbarjawclamp();
  wait(50,msec);
  translate(-10);
  fourbar(150,100);
  Turn(215);
  translate(20);
}
void LeftElims(){
  startPos(0);
  deploy();
  LFD.spin(fwd,150,volt);
  LBD.spin(fwd,150,volt);
  LTD.spin(fwd,150,volt);
  RFD.spin(fwd,150,volt);
  RBD.spin(fwd,150,volt);
  RTD.spin(fwd,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>300);
  Fourbar.setBrake(hold);
  Fourbar.startRotateFor(-90,degrees);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>500);
  waitUntil((FourbarDistance.objectDistance(mm)<30) or (((LFD.position(degrees)+RFD.position(degrees))/2)>3000));
  fourbarjawclamp();
  wait(10,msec);
  LFD.spin(reverse,150,volt);
  LBD.spin(reverse,150,volt);
  LTD.spin(reverse,150,volt);
  RFD.spin(reverse,150,volt);
  RBD.spin(reverse,150,volt);
  RTD.spin(reverse,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2<200);
  LFD.stop(brake);
  LBD.stop(brake);
  LTD.stop(brake);
  RFD.stop(brake);
  RBD.stop(brake);
  RTD.stop(brake);
 translate(-1000);

// setDrive(-8,-8);
// wait(500,msec);
  // wait(100,msec);
  // translate(6);

  // translate(38);
  // fourbarjawclamp();
  // translate(-1000);
}
void LeftGoalSnatch(){
startPos(0);
deploy();
  LFD.spin(fwd,150,volt);
  LBD.spin(fwd,150,volt);
  LTD.spin(fwd,150,volt);
  RFD.spin(fwd,150,volt);
  RBD.spin(fwd,150,volt);
  RTD.spin(fwd,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>300);
  Fourbar.setBrake(hold);
  Fourbar.startRotateFor(-90,degrees);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>850);
  waitUntil((FourbarDistance.objectDistance(mm)<30) or (((LFD.position(degrees)+RFD.position(degrees))/2)>3000));
  fourbarjawclamp();
  wait(10,msec);
  LFD.spin(reverse,150,volt);
  LBD.spin(reverse,150,volt);
  LTD.spin(reverse,150,volt);
  RFD.spin(reverse,150,volt);
  RBD.spin(reverse,150,volt);
  RTD.spin(reverse,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2<200);
  LFD.stop(brake);
  LBD.stop(brake);
  LTD.stop(brake);
  RFD.stop(brake);
  RBD.stop(brake);
  RTD.stop(brake);
  setDrive(-6,-6);
  wait(1800,msec);
  stopdrive();
  Fourbar.startRotateFor(70,degrees);
  wait(100,msec);
  translate(5);
  wait(100,msec);
  Turn_cap(290,7);
  setDrive(-5,-5);
  wait(850,msec);
  stopdrive();
  tilter(1);
  wait(200,msec);
  translate(14);
  conveyor(100);
  Fourbar.startRotateFor(300,degrees);
  wait(100,msec);
  Turn_cap(35,7);
  wait(50,msec);
  translate(34);
  wait(100,msec);
  Turn_cap(77,5);
  wait(100,msec);
  translate(30,4);

// translate(38);
// fourbarjawclamp();
// translate(-32);
// fourbar(300,100);
// Turn_cap(-52,5);
// wait(150,msec);
// setDrive(-6,-6);
// wait(600,msec);
// setDrive(0,0);
// wait(100,msec);
// tilter(1);
// wait(50,msec);
// Fourbar.startRotateFor(forward,500,degrees);
// conveyor(100);
// translate(15);
// Turn_cap(42,4);
// conveyor(100);
// translate(37,5);
// wait(650,msec);
// Turn_cap(245,5);
// conveyor(100);
// fourbar(800,-100);
// translate(35);
// wait(250,msec);
// tilter(2);

//Snatch neutral goal
//Drive back and grab alliance goal with tilter
//load on rings 
}

void LeftOscillate(){
  startPos(0);
  deploy();
  wait(75,msec);
  translate(-8,2);
  tilter(1);
  translate(8);
  Turn(315);
  wait(300,msec);
  translate(-11);
  fourbar(650,100);
  conveyor(100);
  wait(600,msec);
  translate(14);
  translate(-11);
  wait(500,msec);
  translate(14);
  translate(-11);
  wait(500,msec);
  translate(14);
  translate(-11);
  wait(500,msec);
  translate(14);
  translate(-11);
  wait(500,msec);
  translate(14);
  tilter(3);
  translate(4);
}

void CenterGoalSnatch(){
  startPos(315);
  deploy();
  LFD.spin(fwd,150,volt);
  LBD.spin(fwd,150,volt);
  LTD.spin(fwd,150,volt);
  RFD.spin(fwd,150,volt);
  RBD.spin(fwd,150,volt);
  RTD.spin(fwd,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>300);
  Fourbar.setBrake(hold);
  Fourbar.startRotateFor(-90,degrees);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>500);
  waitUntil((FourbarDistance.objectDistance(mm)<30) or (((LFD.position(degrees)+RFD.position(degrees))/2)>4500));
  fourbarjawclamp();
  wait(10,msec);
  LFD.spin(reverse,150,volt);
  LBD.spin(reverse,150,volt);
  LTD.spin(reverse,150,volt);
  RFD.spin(reverse,150,volt);
  RBD.spin(reverse,150,volt);
  RTD.spin(reverse,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2<995);
  LFD.stop(brake);
  LBD.stop(brake);
  LTD.stop(brake);
  RFD.stop(brake);
  RBD.stop(brake);
  RTD.stop(brake);
  Fourbar.startRotateFor(60,degrees);
  Turn_cap(-90,5);
  setDrive(-7,-7);
  wait(1000,msec);
  stopdrive();
  wait(100,msec);
  // wait(75,msec);
  // translate(9);
  // Turn_cap(-119,5);
  // translate(-14,4,3);
  // wait(250,msec);

  // translate(20);
  // Turn_cap(-89,5);
  // setDrive(-6,-6);
  // wait(800,msec);
  // setDrive(0,0);
  tilter(1);
  wait(100,msec);
  Fourbar.startRotateFor(500,degrees);
  conveyor(85);
  Turn_cap(-8,5);
  wait(50,msec);
  translate(35,5);
  wait(100,msec);
  Turn_cap(80,5);
  translate(17,5);
  wait(100,msec);
  translate(-3);
  Turn_cap(35,5);
  translate(-40);
  tilter(2);

  // translate(45);
  // fourbarjawclamp();
  // translate(-42);
}

void CenterElims(){
startPos(315);
  deploy();
  LFD.spin(fwd,150,volt);
  LBD.spin(fwd,150,volt);
  LTD.spin(fwd,150,volt);
  RFD.spin(fwd,150,volt);
  RBD.spin(fwd,150,volt);
  RTD.spin(fwd,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>300);
  Fourbar.setBrake(hold);
  Fourbar.startRotateFor(-90,degrees);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>500);
  waitUntil((FourbarDistance.objectDistance(mm)<30) or (((LFD.position(degrees)+RFD.position(degrees))/2)>4500));
  fourbarjawclamp();
  wait(10,msec);
  LFD.spin(reverse,150,volt);
  LBD.spin(reverse,150,volt);
  LTD.spin(reverse,150,volt);
  RFD.spin(reverse,150,volt);
  RBD.spin(reverse,150,volt);
  RTD.spin(reverse,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2<780);
  LFD.stop(brake);
  LBD.stop(brake);
  LTD.stop(brake);
  RFD.stop(brake);
  RBD.stop(brake);
  RTD.stop(brake);
  Fourbar.startRotateFor(60,degrees);
  Turn(0);
  translate(-1000);
}

void RightElims(){
  startPos(0);
  deploy();
  LFD.spin(fwd,150,volt);
  LBD.spin(fwd,150,volt);
  LTD.spin(fwd,150,volt);
  RFD.spin(fwd,150,volt);
  RBD.spin(fwd,150,volt);
  RTD.spin(fwd,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>300);
  Fourbar.setBrake(hold);
  Fourbar.startRotateFor(-90,degrees);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>500);
  waitUntil((FourbarDistance.objectDistance(mm)<30) or (((LFD.position(degrees)+RFD.position(degrees))/2)>3000));
  fourbarjawclamp();
  wait(10,msec);
  LFD.spin(reverse,150,volt);
  LBD.spin(reverse,150,volt);
  LTD.spin(reverse,150,volt);
  RFD.spin(reverse,150,volt);
  RBD.spin(reverse,150,volt);
  RTD.spin(reverse,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2<200);
  LFD.stop(brake);
  LBD.stop(brake);
  LTD.stop(brake);
  RFD.stop(brake);
  RBD.stop(brake);
  RTD.stop(brake);
  translate(-1000);
}
void RightGoalSnatch(){
  startPos(0);
  deploy();
  LFD.spin(fwd,150,volt);
  LBD.spin(fwd,150,volt);
  LTD.spin(fwd,150,volt);
  RFD.spin(fwd,150,volt);
  RBD.spin(fwd,150,volt);
  RTD.spin(fwd,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>300);
  Fourbar.setBrake(hold);
  Fourbar.startRotateFor(-90,degrees);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2>500);
  waitUntil((FourbarDistance.objectDistance(mm)<30) or (((LFD.position(degrees)+RFD.position(degrees))/2)>3000));
  fourbarjawclamp();
  wait(10,msec);
  LFD.spin(reverse,150,volt);
  LBD.spin(reverse,150,volt);
  LTD.spin(reverse,150,volt);
  RFD.spin(reverse,150,volt);
  RBD.spin(reverse,150,volt);
  RTD.spin(reverse,150,volt);
  waitUntil((LFD.position(degrees)+RFD.position(degrees))/2<200);
  LFD.stop(brake);
  LBD.stop(brake);
  LTD.stop(brake);
  RFD.stop(brake);
  RBD.stop(brake);
  RTD.stop(brake);
  setDrive(-6,-6);
  wait(1800,msec);
  stopdrive();
  wait(75,msec);
  Fourbar.startRotateFor(30,degrees);
  translate(20);
  Turn_cap(-87,5);
  setDrive(-6,-6);
  wait(800,msec);
  setDrive(0,0);
  tilter(1);
  Fourbar.startRotateFor(500,degrees);
  conveyor(100);
  Turn_cap(0,5);
  wait(50,msec);
  translate(33,5);
  wait(100,msec);
  Turn_cap(90,5);
  translate(13,5);
  wait(100,msec);
  translate(-3);
  Turn_cap(25,5);
  translate(-40);
  tilter(2);

  // Fourbar.setBrake(hold);
  // translate(37);
  // fourbarjawclamp();
  // // translate(-1000);
  // translate(-24);
  // fourbar(220,100);
  // wait(250,msec);
  // Turn_cap(-86,4,3,1.25);
  // wait(350,msec);
  // setDrive(-6,-6);
  // wait(700,msec);
  // setDrive(0,0);
  // tilter(1);
  // fourbar(1100,100);
  // wait(200,msec);
  // conveyor(100);
  // translate(3);
  // Turn_cap(360,5);
  // wait(150,msec);
  // translate(32,8);
  // wait(200,msec);
  // Turn_cap(90,7);
  // translate(15,8);
  // wait(350,msec);
  // translate(-3);
  // Turn_cap(30,5);
  // translate(-30);
  // tilter(2);
}




void Prog(){
  startPos(270);
  deploy();
  TilterJaw.on();
  wait(200,msec);
  translate(-6,2,3);
  tilter(1);
  translate(8,6);
  Turn_cap(8,5,5);
  fourbar(450,-80);
  conveyor(100);
  translate(40,6);
  wait(300,msec);
  fourbarjawclamp(); //First Goal
  Fourbar.startRotateFor(700,degrees);
  wait(600,msec);
  Turn_cap(26,5);
  translate(48,6);
  wait(50,msec);
  fourbar(550,-100);
  Turn_cap(30,5);
  wait(100,msec);
  fourbarjawrelease();
  fourbar(60,-100);
  wait(350,msec);
  translate(-12,5);
  Turn_cap(111,5,4);
  // Fourbar.startRotateFor(-800,degrees);
  wait(300,msec);
  translate(32,6);
  wait(300,msec);
  translate(-5);
  fourbar(800,-100);
  wait(100,msec);
  translate(12);
  wait(300,msec);
  fourbarjawclamp(); //Second Goal
  Fourbar.startRotateFor(700,degrees);
  Turn_cap(201,5);
  wait(50,msec);
  translate(43,6);
  fourbar(550,-100);
  fourbarjawrelease();
  wait(750,msec);
  translate(-7,6);
  Turn_cap(108,5);
  Fourbar.startRotateFor(-800,degrees);
  wait(250,msec);
  translate(19,6);
  setDrive(100,100);
  wait(400,msec);
  setDrive(0,0);
  fourbarjawclamp(); //Third Goal
  translate(-10);
  fourbar(100,100);
  Turn_cap(333,6);
  Fourbar.startRotateFor(700,degrees);
  translate(75,6);
  fourbar(600,-100);
  wait(100,msec);
  fourbarjawrelease();
  wait(250,msec);
  translate(-5,6);
  Turn_cap(288,6);
  Fourbar.startRotateFor(-800,degrees);
  translate(48,6);
  wait(50,msec);
  setDrive(6,6);
  wait(600,msec);
  setDrive(0,0);
  wait(50,msec);
  fourbarjawclamp(); //Fourth Goal
  wait(50,msec);
  translate(-7,6);
  Turn_cap(153,6);
  Fourbar.startRotateFor(700,degrees);
  translate(75,6);
  fourbar(550,-100);
  fourbarjawrelease();
  wait(100,msec);
  fourbar(100,-100);
  wait(200,msec);
  translate(-18,6);
  Turn_cap(75,5);
  fourbar(800,-100);
  translate(21);
  fourbarjawclamp(); //tall goal
  translate(55);
  wait(200,msec);
  fourbarjawrelease();
  conveyor(0);
  wait(100,msec);
  translate(-15);
  wait(100,msec);
  tilter(2);
  wait(300,msec);
  translate(-2);
  wait(350,msec);
  translate(10);
  wait(100,msec);
  Turn_cap(265,5);
  translate(13);
  wait(100,msec);
  fourbarjawclamp(); //fifth goal
  wait(100,msec);
  fourbar(1300,100);
  Turn_cap(327,5);
  wait(100,msec);
  translate(35,5,3);
  wait(100,msec);
  fourbarjawrelease();
  wait(350,msec);
  translate(-25);
  Fourbar.startRotateFor(-900,degrees);
  wait(50,msec);
  Turn_cap(45,5);
  translate(30);
  Turn_cap(327,5);
  translate(12,5,3);
  fourbarjawclamp();
  wait(100,msec);
  translate(-5);
  Fourbar.startRotateFor(50,degrees);
  Turn_cap(7,5,4);
  translate(-110);

  // wait(50,msec);
  // translate(-90);
  // Fourbar.startRotateFor(900,degrees);
  // Turn_cap(210,5);
  // translate(7,100,3);
  // fourbarjawrelease();
  // wait(200,msec);
  // translate(-20);

  

  // fourbar(550,-100);
  // fourbarjawrelease();
  // fourbar(60,-100);
  // wait(250,msec);
  // translate(-10,6);
}

void autonomous(void) {
    Brain.Timer.reset();
  if(routine == 1){
   AWP();
}else if(routine ==2){
  LeftGoalSnatch();
}else if(routine ==3){
  RightGoalSnatch();
}else if(routine ==4){
  CenterGoalSnatch();
}else if(routine ==5){
  Prog();
}else if(routine ==6){
  LeftOscillate();
}else if(routine == 7){
  RightOscillate();
}else if(routine == 8){
  SafeAWP();
}else if(routine == 9){
  RightElims();
}else if(routine == 10){
  LeftElims();
}else if(routine == 11){
  CenterElims();
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
Fourbar.setStopping(hold);
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    TilterControl();
    ConveyorControl();
    driveControl();
    FourBarControl();
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
