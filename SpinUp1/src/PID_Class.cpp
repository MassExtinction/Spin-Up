#include "PID_Class.h"

PidControl::PidControl(double targetPosition,double _currentPosition,double _kp,double _ki,double _kd)
          :kp(_kp),ki(_ki),kd(_kd),target(targetPosition),currentPosition(_currentPosition),output(0),prevError(0),error(targetPosition-currentPosition),derivative(0),integral(0),integralMax(0),integralErrorZero(0)
          {

          }
void PidControl::setUpIntegral(double KI, int integralMaxValue, int integralErrorZeroValue){
  ki = KI;
  integralMax = integralMaxValue;
  integralErrorZero = integralErrorZeroValue;
}
void PidControl::updatePosition(double currentPos){
  currentPosition = currentPos;
}
void PidControl::setTarget(double targetPos){
  target = targetPos;
}
double PidControl::calculate(double _currentPos){
  currentPosition = _currentPos;
  error = target - currentPosition;
  if (integral > integralErrorZero)
    integral = 0;
  else if(error > integralMax)
    integral = integralMax;
  else
    integral += error;
  derivative = error - prevError;
  prevError = error;
  output = (error * kp) + (integral * ki) + (derivative * kd);
  return output;
}
double PidControl::Output(){
  return output;
}
double PidControl::getTarget(){
  return target;
}
double PidControl::getP(double _currentPos){
  return target-_currentPos;
}
void PidControl::calculateIndependent(){
  if (integral > integralErrorZero)
    integral = 0;
  else if(error > integralMax)
    integral = integralMax;
  else
    integral += error;
  derivative = error - prevError;
  prevError = error;
  output = (error * kp) + (integral * ki) + (derivative * kd);
}
double PidControl::SetError(double _error){
  error = _error;
  // PidControl::calculateIndependent();
  if (integral > integralErrorZero)
    integral = 0;
  else if(error > integralMax)
    integral = integralMax;
  else
    integral += error;
  derivative = error - prevError;
  prevError = error;
  output = (error * kp) + (integral * ki) + (derivative * kd);
  return output;
}
double PidControl::getError(){
  return error;
}
