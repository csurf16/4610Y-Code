using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Flywheel;
extern motor Intake;
extern motor Indexer;
extern motor fr;
extern motor br;
extern motor bl;
extern motor fl;
extern motor accel;
extern digital_out String1;
extern digital_out String2;
extern digital_out Angle;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );