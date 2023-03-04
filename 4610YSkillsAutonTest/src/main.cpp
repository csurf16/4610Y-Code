/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\conno                                            */
/*    Created:      Sat Mar 04 2023                                           */
/*    Description:  V5 project                                                */
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

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Drivetrain.drive(forward);  
  Conveyor.spinFor(forward, 250, degrees);
  Drivetrain.driveFor(reverse, 24, inches);
  Drivetrain.turn(right);
  wait(1, sec);
  Drivetrain.driveFor(forward, 24, inches);
  wait(0.1, sec);
  Drivetrain.setDriveVelocity(12, pct);
  Drivetrain.drive(forward);
  wait(0.1, sec);

  Conveyor.spinFor(forward, 275, degrees);
  
  Drivetrain.driveFor(reverse, 2, inches);
  Conveyor.spin(reverse);
  Drivetrain.driveFor(reverse, 8, inches);
  Conveyor.stop();

  /*Drivetrain.turn(left);
  wait(1, sec);
  Drivetrain.stop();
  Flywheel.spin(forward, 75, pct);
  for(int i = 0; i < 2; i++)
  {
    Indexer.setVelocity(100, pct);
    Indexer.spinFor(forward, 1, sec);
    Indexer.setVelocity(20, pct);
    Indexer.spinFor(reverse, 2, sec);
  }
  Flywheel.stop(coast);*/

  Drivetrain.turn(right);
  wait(1.5, sec);
  Drivetrain.stop();

  StringShooter.setVelocity(100, pct);
  for(int i  = 0; i < 10; i++) {
    StringShooter.spinFor(reverse, 0.5, sec);
    StringShooter.spinFor(forward, 1, sec);
  }
}
