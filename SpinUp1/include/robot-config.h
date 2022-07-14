using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern inertial Gyro;
extern motor RBD;
extern motor RFD;
extern motor RTD;
extern motor LFD;
extern motor LTD;
extern motor LBD;
extern motor Flywheel;
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );