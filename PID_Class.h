#pragma once

class PidControl
{
private:
        double kp,
               ki,
               kd,
               target,
               currentPosition,
               output,
               prevError,
               error,
               derivative,
               integral;
        int integralMax;
        int integralErrorZero;
        void calculateIndependent();
public:
       PidControl(double targetPosition,double _currentPosition,double _kp,double _ki,double _kd);
       void setUpIntegral(double KI,int integralMaxValue,int integralErrorZeroValue);
       void updatePosition(double currentPos);
       void setTarget(double targetPos);
       double calculate(double _currentPos);
       double Output();
       double getTarget();
       double getP(double _currentPos);
       double SetError(double _error);
       double getError();
};