#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins
#define motorPin1  8     // IN1 on the ULN2003 driver 2
#define motorPin2  9     // IN2 on the ULN2003 driver 2
#define motorPin3  10    // IN3 on the ULN2003 driver 2
#define motorPin4  11    // IN4 on the ULN2003 driver 2

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);


// variables
int turnSteps = 2100; // number of steps for a 90 degree turn
int lineSteps = -6600; //number of steps to drive straight
int stepperSpeed = 1000; //speed of the stepper (steps per second)
int steps = 0; // keep track of the step count for motor 1


boolean turn = false; //keep track if we are turning or going straight next


void setup() {
  delay(3000); //sime time to put the robot down after swithing it on

  stepper.setMaxSpeed(2000.0);
  stepper.move(1);  // I found this necessary
  stepper.setSpeed(stepperSpeed);

 

}
void loop() {

  if (steps == 0) {
    int target = 0;
    if (turn == true) {
      target = turnSteps;
    }

    else {
      target = lineSteps;
    }

    stepper.move(target);
    stepper.setSpeed(stepperSpeed);
    turn = !turn;
  }



  steps = stepper.distanceToGo();
  

  stepper.runSpeedToPosition();

}
