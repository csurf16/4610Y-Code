/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    16, 15, 20, 19, 11
// Conveyor             motor         12              
// Flywheel             motor         17              
// Indexer              motor         18              
// StringShooter        motor         13              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  StringShooter.setVelocity(100, pct);

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  Conveyor.spinFor(forward, 160, degrees);
  Drivetrain.driveFor(reverse, 10, inches);
  Conveyor.spin(forward);
  Drivetrain.turnFor(right, 100, degrees);
  Drivetrain.driveFor(forward, 16, inches);
  Conveyor.stop();
  Drivetrain.driveFor(forward, 8, inches);

  Conveyor.spinFor(forward, 145, degrees);
  
  Drivetrain.driveFor(reverse, 2, inches);
  Conveyor.spin(reverse);
  Drivetrain.driveFor(reverse, 10, inches);
  Conveyor.stop();

  Drivetrain.driveFor(reverse, 24, inches);
  Drivetrain.turnFor(right, 150, degrees);

  // Opposite rollers
  /*
  Drivetrain.drive(forward, 60 inches);
  Drivetrain.turnFor(left, 45, degrees);
  
  
  */
  // StringShooter.spinFor(reverse, 45, degrees);
  // StringShooter.spinFor(forward, 90, degrees);
  // StringShooter.spinFor(reverse, 135, degrees);
  // StringShooter.spinFor(forward, 180, degrees);
  // StringShooter.spinFor(reverse, 270, degrees);
  // StringShooter.spinFor(forward, 360, degrees);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}