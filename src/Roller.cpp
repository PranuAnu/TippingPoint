#include "main.h"

//set roller lower motor goal flag
bool AtDistanceRollerGoal(int threshold) {
  return (abs((int)(RollerMotor.get_position()-RollerMotor.get_target_position())) < threshold);
}

//set roller lower target, but does not wait for them to reach their target
void Roller(double distance, int speed){
    RollerMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    RollerMotor.move_relative(distance, speed);
}

//set roller lower target, and wait for them to reach their target
void RollerTarget(double distance, int speed){
    Roller(distance, speed);
    do {
      pros::delay(20);
    } while (!AtDistanceRollerGoal(5));
    pros::delay(20);
}

//thread for all roller lower controls
void Roller_fn(void* param) {

  RollerMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {

    if (master.get_digital(DIGITAL_L1)) {
      //max 12000
      RollerMotor.move_voltage(5000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_L2)) {
      //max -12000
      RollerMotor.move_voltage(-5000);
      //pros::delay(20);
    }
    else {
      RollerMotor.move_voltage(0);
      //pros::delay(20);
    }

  }

}
