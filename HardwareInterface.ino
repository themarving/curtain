// include arduino stepper library
#include <Stepper.h>

// steps it takes to make a full revolution
const int STEPS_PER_REVOLUTION = 2048;

// push/pull length of opening/closing the curtain
const int PUSH_PULL_LENGTH = 1500;

// creating motor control unit
Stepper motorControl = Stepper(STEPS_PER_REVOLUTION, 8, 9, 10, 11);

void setup() {
  // setting motor RPM
  motorControl.setSpeed(5);

  // DEMO OPENING AND CLOSING CURTAIN //
  openCurtain(PUSH_PULL_LENGTH);
  delay(1000);
  closeCurtain(PUSH_PULL_LENGTH);
  delay(1000);
}

void loop() {

}

// opening the curtain
void openCurtain(int steps) {
  // making the motor run continuous (COUNTERCLOCKWISE)
  motorControl.step(steps);
}

// closing the curtain
void closeCurtain(int steps) {
  // making the motor run continuous (CLOCKWISE)
  motorControl.step(-steps);
}
