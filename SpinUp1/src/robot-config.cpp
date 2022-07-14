#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
inertial Gyro = inertial(PORT1);
motor RBD = motor(PORT2, ratio6_1, false);
motor RFD = motor(PORT3, ratio6_1, false);
motor RTD = motor(PORT4, ratio6_1, false);
motor LFD = motor(PORT5, ratio6_1, false);
motor LTD = motor(PORT6, ratio6_1, false);
motor LBD = motor(PORT7, ratio6_1, false);
motor Flywheel = motor(PORT8, ratio6_1, false);
motor Intake = motor(PORT9, ratio6_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}