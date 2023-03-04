#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontLeft = motor(PORT16, ratio18_1, false);
motor BackLeft = motor(PORT15, ratio18_1, false);
motor FrontRight = motor(PORT20, ratio18_1, true);
motor BackRight = motor(PORT19, ratio18_1, true);
motor Conveyor = motor(PORT12, ratio18_1, true);
motor Flywheel = motor(PORT17, ratio6_1, true);
motor Indexer = motor(PORT18, ratio18_1, false);
motor StringShooter = motor(PORT13, ratio18_1, false);
inertial Inertial = inertial(PORT11);

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