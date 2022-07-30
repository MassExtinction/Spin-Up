#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RBD = motor(PORT7, ratio6_1, false);
motor RTD = motor(PORT1, ratio6_1, false);
motor RFD = motor(PORT5, ratio6_1, false);
motor LBD = motor(PORT10, ratio6_1, true);
motor LTD = motor(PORT11, ratio6_1, true);
motor LFD = motor(PORT9, ratio6_1, true);
motor Fourbar = motor(PORT3, ratio36_1, false);
motor Conveyor = motor(PORT20, ratio6_1, false);
distance FourbarDistance = distance(PORT2);
led Tilter = led(Brain.ThreeWirePort.G);
led TilterJaw = led(Brain.ThreeWirePort.H);
led FourbarJaw = led(Brain.ThreeWirePort.F);
controller Controller1 = controller(primary);
inertial Gyro = inertial(PORT6);

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