#include "main.h"

//set claw motor goal flag
bool AtDistanceClawGoal(int threshold) {
  return (abs((int)(ClawMotor.get_position()-ClawMotor.get_target_position())) < threshold);
}


//set claw target, but does not wait for them to reach their target
void Claw(double distance, int speed){
    ClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    ClawMotor.move_relative(distance, speed);

}

//set claw target, and wait for them to reach their target
void ClawTarget(double distance, int speed){
    Claw(distance, speed);
    do {
      pros::delay(20);
    } while (!AtDistanceClawGoal(5));
    pros::delay(20);
}

//thread for all claw controls
void Claw_fn(void* param) {

  ClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while (true) {

    if (master.get_digital(DIGITAL_UP)) {
      //max 12000
      ClawMotor.move_voltage(10000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_DOWN)) {
      //max -12000
      ClawMotor.move_voltage(-10000);
      //pros::delay(20);
    }
    else {
      ClawMotor.move_voltage(0);
      //pros::delay(20);
    }

  }
}
