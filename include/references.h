//define all motor ports constant variables here
/*drivetrain motor ports*/
#define FLMotorPort 1
#define FRMotorPort 10
#define BLMotorPort 19
#define BRMotorPort 16
/*claw motor ports*/
#define ClawMotorPort 8
/*roller motor ports*/
#define RollerMotorPort 4



//define all sensor ports constant variables here
//define ADIGyroPort

 //declare global motor object variables here
 /*drivetrain motor variables*/
extern pros::Motor FLMotor;
extern pros::Motor FRMotor;
extern pros::Motor BLMotor;
extern pros::Motor BRMotor;
 /*claw motor variables*/
extern pros::Motor ClawMotor;
/*roller motor variables*/
extern pros::Motor RollerMotor;

 //declare global controller object variable here
extern pros::Controller master;
extern pros::Controller partner;

//declare global sensor object variables here
//extern pros::ADIGyro gyro;


//declare global variables that map controller joysticks for drivetrain variables
extern int LeftControl;
extern int RightControl;
extern int power;
extern int turn;

//declare drive train function prototype
/*drive train task thread function prototype*/
void DriveTrain_fn(void* param);
/*drive train functions*/
void Drive(double, int);
void DriveTarget(double, int);

void Rotate(double, int);
void RotateTarget(double, int);

bool AtDistanceDriveGoal(int);


//declare roller lower task thread function prototype
void Roller_fn(void* param);
/*roller lower functions*/
void Roller(double, int);
void RollerTarget(double, int);

bool AtDistanceRollerGoal(int);

//declare claw task thread function prototype
void Claw_fn(void* param);
/*claw functions*/
void Claw(double, int);
void ClawTarget(double, int);

bool AtDistanceClawGoal(int);


//declare functions for antonomous.cpp
void RedLeft();
/* function for basic auton*/
void RedRight();
/* function for blue alliance side close to goal zone*/
void RedBoth();

void BlueLeft();
/* function for red alliance side close to goal zone*/
void BlueRight();

void BlueBoth();
/* function for skill autonomous*/
void SkillsAuton();

/* variables and functions for auton selector */
extern int autonselector;
extern const char *titles[7];
extern void (*scripts[7])();

void LCDScriptExecute();
