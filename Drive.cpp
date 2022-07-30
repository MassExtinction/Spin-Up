#include "vex.h"
#include "Drive.h"
#include "PID_Class.h"
#include "Inertial_special_Functions.h"

void setDrive(int left, int right){
  RBD.spin(forward,right,volt);
  RFD.spin(forward,right,volt);
  RTD.spin(forward,right,volt);
  LBD.spin(forward,left,volt);
  LFD.spin(forward,left,volt);
  LTD.spin(forward,left,volt); 
}

bool within(double num,double min,double max){
  bool greatMin = num > min;
  bool lessMax = num < max;
  return greatMin and lessMax;
}

void setDriveStopping(brakeType type){
    RFD.setBrake(type);
    RBD.setBrake(type);
    LFD.setBrake(type);
    LBD.setBrake(type);
    LTD.setBrake(type);
    RTD.setBrake(type);
  }
void driveControl(){
  setDriveStopping(coast);
  double turnImportance = .1;
    double forwardVal = Controller1.Axis3.value(),
           turnVal = Controller1.Axis4.value(), 
           turnVolts = turnVal * .12,
           forwardVolts = forwardVal * .12 * (1-fabs(turnVolts)/12 * turnImportance);

           setDrive(forwardVolts+turnVolts, forwardVolts-turnVolts);
}

void move (float target,float tolerance,float kp,float ki,float kd){
  double prevError = 0;
  double integral = 0;
  double derivative = 0;
  while(true){
    double currentPos = (RBD.position(rotationUnits::deg) + RFD.position(rotationUnits::deg) + LBD.position(rotationUnits::deg) + LFD.position(rotationUnits::deg) + LTD.position(rotationUnits::deg) + RTD.position(rotationUnits::deg))/6;
    double error = target - currentPos;
    if(error < 50)
      integral = 0;
    else if(integral > 30)
      integral = 30;
    else
    integral += error;
    derivative = error - prevError;
    prevError = error;
    double output = (error * kp) + (integral * ki) + (derivative * kd);
    setDrive(output,output);
    if(within(error,-tolerance,tolerance))
      break;
    wait(20,msec);
  }
  setDrive(0,0);
}
double Pi = 3.1415;
double getDistance(double deg,double radius){
  double ratio = (deg/360.00);
  return 2*Pi*ratio*radius;
}
void translate(float Inches,int speed,int tolerance,bool correctTurn,float kp,float kd,float t_kp){
  LBD.setPosition(0,degrees);
  LFD.setPosition(0,degrees);
  LTD.setPosition(0,degrees);
  RTD.setPosition(0,degrees);
  RFD.setPosition(0,degrees);
  RBD.setPosition(0,degrees);
  double avgVal = ((LBD.position(degrees) + LFD.position(degrees) + RBD.position(degrees) + RFD.position(degrees) + LTD.position(degrees) + RTD.position(degrees))/6) * .42857143;
  PidControl translatePID = PidControl(Inches,avgVal,kp,0,kd);
  double startAngle = Gyro_Position();
  while(true){
    double deltaTheta = Gyro_Position() - startAngle;
    if(!correctTurn)
      deltaTheta = 0;
    avgVal = ((LBD.position(degrees) + LFD.position(degrees) + LTD.position(degrees) + RTD.position(degrees) + RBD.position(degrees) + RFD.position(degrees))/6) * .42857143;
    translatePID.calculate(getDistance(avgVal,2));
    
    setDrive(translatePID.Output() > speed? speed:translatePID.Output() -(deltaTheta * t_kp),translatePID.Output() > speed? speed:translatePID.Output() +(deltaTheta * t_kp));
    if(within(translatePID.getError(),-tolerance,tolerance))
      break;
  }
  setDrive(0,0);
  }
  float reducingAngleMinus180to180 (float angleDeg ) {
  while( ! (angleDeg >= -180 && angleDeg < 180)) {
      if( angleDeg < 180 ) { angleDeg += 360; }
      if( angleDeg >= 180 ) { angleDeg -= 360; }
  }
  return (angleDeg) ;
}

float reducingAngle0to360(float angleDeg){
  while(!(angleDeg >= 0 && angleDeg < 360)) {
    if(angleDeg < 0 ) { angleDeg += 360; }
    if(angleDeg >= 360) { angleDeg -= 360; }
  }
  return(angleDeg);
}
#include <iostream>


  void Turn(int degrees,int angleError,float kp,float kd){
      // Gyro_Tear();
      PidControl turnPid = PidControl(degrees,Gyro_Position(),kp,0,kd);//kU = .95
      turnPid.setUpIntegral(.02,20,15);
      while(true){
        double error = reducingAngleMinus180to180( degrees-reducingAngle0to360(Gyro_Position()));
       double val =  turnPid.SetError(error);
      //  std::cout<<error<<std::endl;
        setDrive(val,-val);
        if(within(error,-angleError,angleError))
          break;
        wait(20,msec);
      }
      setDrive(0,0);
  }
    void Turn_cap(int degrees,int speedCap, int angleError,float kp,float kd){
      // Gyro_Tear();
      PidControl turnPid = PidControl(degrees,Gyro_Position(),kp,0,kd);//kU = .95
      turnPid.setUpIntegral(.02,20,15);
      while(true){
        
        double error = reducingAngleMinus180to180( degrees-reducingAngle0to360(Gyro_Position()));
       int dir = fabs(error) / error;
       double val =  turnPid.SetError(error);
       if(fabs(val) > speedCap)
        val = speedCap * dir;
      //  std::cout<<error<<std::endl;
        setDrive(val,-val);
        if(within(error,-angleError,angleError))
          break;
        wait(20,msec);
      }
      setDrive(0,0);
  }
