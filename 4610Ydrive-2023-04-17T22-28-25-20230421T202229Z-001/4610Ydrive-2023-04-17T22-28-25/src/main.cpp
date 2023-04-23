/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Apr 05 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Flywheel             motor         1               
// Intake               motor         18              
// Indexer              motor         12              
// fr                   motor         20              
// br                   motor         13              
// bl                   motor         11              
// fl                   motor         4               
// accel                motor         19              
// String1              digital_out   G               
// String2              digital_out   H               
// Angle                digital_out   F               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;

void pre_auton(void)
{
  vexcodeInit();
  fl.setStopping(brake);
  fr.setStopping(brake);
  br.setStopping(brake);
  bl.setStopping(brake);
  fl.setVelocity(100, pct);
  fr.setVelocity(100, pct);
  br.setVelocity(100, pct);
  bl.setVelocity(100, pct);
  Intake.setVelocity(100, pct);
  Indexer.setVelocity(100, pct);
}
void flywheelStart() {
  
  Flywheel.spin(forward, 65, pct);
  accel.spin(forward, 100, pct);
}

void flywheelStop() {
  
  Flywheel.stop();
  accel.stop();
}
void flywheelRev()
{
  Flywheel.spin(reverse, 100, pct);
  accel.spin(reverse, 100, pct);
}
void autonomous(void)
{

}

void usercontrol(void) {
Flywheel.spin(forward, 87, pct);
accel.spin(forward, 100, pct);
fl.spin(reverse);
fr.spin(reverse);
bl.spin(reverse);
br.spin(reverse);
vex::task::sleep(650);
fl.stop();
fr.stop();
bl.stop();
br.stop();
vex::task::sleep(1000);
fl.spin(forward);
fr.spin(reverse);
bl.spin(forward);
br.spin(reverse);
vex::task::sleep(400);
fl.stop();
fr.stop();
bl.stop();
br.stop();
vex::task::sleep(300);
fl.spin(reverse);
fr.spin(reverse);
bl.spin(reverse);
br.spin(reverse);
vex::task::sleep(300);
fl.stop();
fr.stop();
bl.stop();
br.stop();
Intake.spinFor(forward, 180, degrees);
vex::task::sleep(2000);
Indexer.spinFor(reverse, 600, degrees);
wait(1, seconds);
Indexer.spin(reverse, 100, pct);
  /*Flywheel.spin(forward, 65, pct);
  accel.spin(forward, 100, pct);
  while (true)
  {
      if(abs(Controller1.Axis3.position(percent)) > 5 || abs(Controller1.Axis1.position(percent)) > 5) {
      fl.spin(forward, Controller1.Axis3.position() +  Controller1.Axis1.position(), pct);
      bl.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(), pct);
      fr.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), pct);
      br.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), pct);
      }
      else 
      {
      fl.stop();
      fr.stop();
      bl.stop();
      br.stop();
      }
      if(Controller1.ButtonUp.pressing())
      {
        Indexer.spin(reverse, 100, pct);
        Intake.spin(forward, 100, pct);
      }
      else if(Controller1.ButtonL1.pressing()) 
      {
        Intake.spin(forward, 100, pct);
      }
      else if(Controller1.ButtonL2.pressing())
      {
        Intake.spin(reverse, 100, pct);
      }
      else
      {
        Intake.stop();
        Indexer.stop();
      }
      if(Controller1.ButtonLeft.pressing())
      {
        Angle.set(true);
      }
      if(Controller1.ButtonRight.pressing())
      {
        Angle.set(false);
      }
      if(Controller1.ButtonX.pressing())
      {
        String1.set(true);
        String2.set(true);
      }
      
      Controller1.ButtonR1.pressed(flywheelStart);
      Controller1.ButtonDown.pressed(flywheelStop);
      Controller1.ButtonR2.pressed(flywheelRev);
    
  }*/
  
}
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