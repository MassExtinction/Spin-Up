using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RBD;
extern motor RTD;
extern motor RFD;
extern motor LBD;
extern motor LTD;
extern motor LFD;
extern motor Fourbar;
extern motor Conveyor;
extern distance FourbarDistance;
extern led Tilter;
extern led TilterJaw;
extern led FourbarJaw;
extern controller Controller1;
extern inertial Gyro;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );