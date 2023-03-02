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
// Controller1          controller                    
// FrontLeft            motor         16              
// BackLeft             motor         15              
// FrontRight           motor         20              
// BackRight            motor         19              
// Conveyor             motor         12              
// Flywheel             motor         17              
// Indexer              motor         18              
// StringShooter        motor         13              
// Inertial             inertial      11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath> //std::abs
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
  FrontLeft.setStopping(brake);
  BackLeft.setStopping(brake);
  FrontRight.setStopping(brake);
  BackRight.setStopping(brake);
  Indexer.setVelocity(100, pct);


  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

double kP = 0.07;
double kI = 0.0;
double kD = 0.11;

double turnkP = 0.001;
double turnkI = 0.001;
double turnkD = 0.001;

double flywheelkP = 0.001;
double flywheelkI = 0.001;
double flywheelkD = 0.001;

int desiredValue = 0;
int desiredTurnValue = 0;
int desiredFlywheelValue = 0;

int error;
int prevError = 0;
int derivative;
int totalError = 0;

int turnError;
int turnPrevError = 0;
int turnDerivative;
int turnTotalError = 0;

int flywheelError;
int flywheelPrevError = 0;
int flywheelDerivative;
int flywheelTotalError = 0;

bool resetDriveSensors = false;
bool resetFlywheelSensors = false;
bool enableDrivePID = true;
bool enableFlywheelPID = true;

int drivePID() {
  while(enableDrivePID) {
    if (resetDriveSensors) {
      resetDriveSensors = false;
      FrontLeft.setPosition(0, degrees);
      FrontRight.setPosition(0, degrees);
    }

    int leftMotorPosition = FrontLeft.position(degrees);
    int rightMotorPosition = FrontRight.position(degrees);
    int turnPosition = Inertial.heading(degrees);


    // Lateral PID
    int averagePosition = leftMotorPosition + rightMotorPosition / 2;

    error = averagePosition - desiredValue;
    derivative = error - prevError;
    totalError += error;

    double lateralMotorPower = error * kP + totalError * kI;

    // Turning PID
    turnError = desiredTurnValue - turnPosition;
    turnDerivative = turnError - turnPrevError;
    turnTotalError += turnError;

    double turnMotorPower = turnError * turnkP + turnTotalError * turnkI;

    FrontLeft.spin(forward, lateralMotorPower + turnMotorPower, volt);
    BackLeft.spin(forward, lateralMotorPower + turnMotorPower, volt);
    FrontRight.spin(forward, lateralMotorPower - turnMotorPower, volt);
    BackRight.spin(forward, lateralMotorPower - turnMotorPower, volt);

    prevError = error;
    turnPrevError = turnError;
    vex::task::sleep(20); 
  }
  return 1;
}

int flywheelPID() {
  while(enableFlywheelPID) {
    if (resetFlywheelSensors) {
      resetFlywheelSensors = false;
      Flywheel.setVelocity(0, rpm);
    }

    // Flywheel PID

    int flywheelVelocity = Flywheel.velocity(rpm);

    flywheelError = desiredFlywheelValue - flywheelVelocity;
    flywheelDerivative = flywheelError - flywheelPrevError;
    flywheelTotalError += flywheelError;

    double flywheelMotorPower = flywheelError * flywheelkP + flywheelDerivative * flywheelkD + flywheelTotalError * flywheelkI;
    if(desiredFlywheelValue == 0)
    {
      flywheelMotorPower = 0;
    }

    Flywheel.spin(forward, flywheelMotorPower, rpm);

    flywheelPrevError = flywheelError;
    vex::task::sleep(20); 
  }
  return 1;
}

void ConveyorStartForward() {
  Conveyor.spin(forward, 50, pct);
}

void ConveyorStartReverse() {
  Conveyor.spin(reverse, 50, pct);
}

void ConveyorStop() {
  Conveyor.stop();
}

void FlywheelStart() {
  Flywheel.spin(forward, 60, pct);
}

void FlywheelStop() {
  Flywheel.stop();
}

void IndexerStartStop() {
  Indexer.spinFor(forward, 30, degrees);
  wait(0.25, seconds);
  Indexer.spinFor(reverse, 30, degrees);
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

  Conveyor.spinFor(reverse, 69, degrees);

  vex::task autonPID(drivePID);
  vex::task autonFlywheelPID(flywheelPID);

  resetDriveSensors = true;
  desiredValue = 0;
  desiredTurnValue = 0;

  vex::task::sleep(1000);

  resetDriveSensors = true;
  desiredValue = 0;
  desiredTurnValue = 0;
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

  vex::task driverFlywheelPID(flywheelPID);

  enableDrivePID = false;
  enableFlywheelPID = true;
  resetFlywheelSensors = true;

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    if(abs(Controller1.Axis3.position(percent)) > 5 || abs(Controller1.Axis1.position(percent)) > 5) {
      FrontLeft.spin(forward, Controller1.Axis3.position() +  Controller1.Axis1.position(), pct);
      BackLeft.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(), pct);
      FrontRight.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), pct);
      BackRight.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), pct);
    }
    else {
      FrontLeft.stop();
      BackLeft.stop();
      FrontRight.stop();
      BackRight.stop();
    }

    if (Controller1.ButtonL1.pressing()) {
      Conveyor.spin(forward, 75, pct);
    }
    else if (Controller1.ButtonL2.pressing()) {
      Conveyor.spin(reverse, 75, pct);
    }
    else {
      Conveyor.stop(hold);
    }

    if (Controller1.ButtonR1.pressing()) {
      desiredFlywheelValue = 400;
    }
    else {
      desiredFlywheelValue = 0;
    }

    Controller1.ButtonUp.pressed(IndexerStartStop);

    if (Controller1.ButtonX.pressing()) {
      StringShooter.spin(forward, 100, pct);
    }
    else if (Controller1.ButtonB.pressing()) {
      StringShooter.spin(reverse, 100, pct);
    }

    Brain.Screen.print(Flywheel.velocity(rpm));

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