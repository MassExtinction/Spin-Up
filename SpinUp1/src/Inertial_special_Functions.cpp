#include "vex.h"
/*-------------------------*/
double GyroTearPos = 0;
/*-------------------------*/
double Gyro_Position() { return Gyro.rotation(degrees) - GyroTearPos; }
void Gyro_Tear() { GyroTearPos = Gyro.rotation(degrees); }
void Gyro_Relog() { GyroTearPos = 0; }
double Gyro_TearPos() { return GyroTearPos; }
void Gyro_Calibrate() {
  Gyro.calibrate();
  while (Gyro.isCalibrating())
    wait(20, msec);
}
bool Gyro_Stable(double dps) {
  double Gyro_prev = Gyro.rotation();
  wait(500, msec);
  double Gyro_aft = Gyro.rotation();
  if ((fabs(Gyro_aft) - fabs(Gyro_prev)) < dps)
    return true;
  else
    return false;
}
void setGyroRotation(int degrees,rotationUnits rotationUnit ){
  Gyro.setRotation(degrees,rotationUnit);
}