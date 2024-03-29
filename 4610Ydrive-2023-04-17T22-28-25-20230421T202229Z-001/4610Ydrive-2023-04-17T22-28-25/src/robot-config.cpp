#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Flywheel = motor(PORT1, ratio6_1, false);
motor Intake = motor(PORT18, ratio18_1, false);
motor Indexer = motor(PORT12, ratio18_1, false);
motor fr = motor(PORT20, ratio18_1, false);
motor br = motor(PORT13, ratio18_1, false);
motor bl = motor(PORT11, ratio18_1, true);
motor fl = motor(PORT4, ratio18_1, true);
motor accel = motor(PORT19, ratio6_1, true);
digital_out String1 = digital_out(Brain.ThreeWirePort.G);
digital_out String2 = digital_out(Brain.ThreeWirePort.H);
digital_out Angle = digital_out(Brain.ThreeWirePort.F);
inertial Inertial = inertial(PORT3);

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