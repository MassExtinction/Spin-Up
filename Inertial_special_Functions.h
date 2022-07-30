#pragma once

double Gyro_Position();
void Gyro_Tear();
void Gyro_Relog ();
void Gyro_Calibrate();
bool Gyro_Stable (double dps);
double TearPos ();
void setGyroRotation(int degrees,vex::rotationUnits rotationUnit );