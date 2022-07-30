#pragma once
#ifndef Gaurd
#define Gaurd

// your declarations (and certain types of definitions) here



void driveControl();
// void translate(float Inches,int tolerance = 1,float kp = .9,float kd = .2);
extern double Pi;
void translate(float Inches,int speed = 100,int tolerance = 2,bool correctTurn = false,float kp = .9,float kd = .2,float t_kp = .5);
void Turn(int degrees,int angleError = 3,float kp = .67,float kd = 3.56);
void setDrive(int left, int right);
void Turn_cap(int degrees,int speedCap, int angleError = 3,float kp = .67,float kd = 3.56);
void setDriveStopping(vex::brakeType type);
void move(float target,float tolerance,float kp,float ki,float kd);

#endif