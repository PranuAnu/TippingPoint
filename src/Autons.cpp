#include "main.h"

/**auton function for taking mobile goal out of triangle & scoring (red side)**/
void RedRight(){
  //drive out a bit
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //rotate toward mobile goal
  Rotate(45.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive forward until reach mobile goal
  Drive(100.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  Claw(200.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //deposit preload from roller onto mobile goal
  Roller(150.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive back to get out of triangle zone
  Drive(-50.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}

/**auton function for scoring on goal on bridge (red side)**/
void RedLeft(){
  //drive out to hit mobile goal
  Drive(25.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}

/**auton function for doing both (red side)**/
void RedBoth(){

}







/**auton function for taking mobile goal out of triangle & scoring (blue side)**/
void BlueRight(){
  //drive out a bit
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //rotate toward mobile goal
  Rotate(45.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive forward until reach mobile goal
  Drive(100.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  Claw(200.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //deposit preload from roller onto mobile goal
  Roller(150.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive back to get out of triangle zone
  Drive(-50.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}



/*auton function for scoring on goal on bridge (blue side)*/
void BlueLeft(){
  //drive out a bit
  Drive(25.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);

}

/**auton function for doing both (blue side)**/
void BlueBoth(){

}


/**varirables and functions array for auton selector**/
int autonselector = 0;
const char *titles[] = {"RedRight", "RedLeft", "RedBoth", "BlueRight", "BlueLeft", "BlueBoth", "Skills Auton"};

void (*scripts[])() = {&RedRight, &RedLeft, &RedBoth, &BlueRight, &BlueLeft, &BlueBoth, &SkillsAuton};

void LCDScriptExecute() {scripts[autonselector]();}
