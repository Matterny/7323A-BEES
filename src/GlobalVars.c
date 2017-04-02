#include "main.h"
#include "GlobalVars.h"
#define GYRO_PORT 3

int count =0;                    //Which autonomous to do by default
const unsigned int leftButton = 1;//Pre-Auton Variables
const unsigned int centerButton = 2;
const unsigned int rightButton = 4;
char option_1[] = "Simple Auton";//Replaced all strings with char arrays
char option_2[] = "Left Cube";
char option_3[] = "Right Cube";
char option_4[] = "Skills Auton";
char Mode[] = "Usercontrol";

int clawtime = 900;
int clawsign = 1;							//Needs to be either 1 or -1
int clawEnable = 1;						//Needs to be either 0 or 1
int clawFuzz = 1;							//How far does the claw move in ESTOP_RATE ms
int clawStartTime = 100;
int ESTOP_RATE = 10;
int driveSign = 1;
//int Limit = 0;
int holdSet;


int backRight  = 1;
int topLift    = 2;
int frontRight = 3;//reverse
int rightClaw  = 4;//reverse
int midRight   = 5;//reverse
int midLeft    = 6;
int leftClaw   = 7;
int frontLeft  = 8;
int bottomLift = 9;     //reverse
int backLeft   =10;


int Bat1;
int Bat2;
int Bat3;
int status = 1;
int Max_Height = 1200;		//The value of the maximum desired height of the lift - 0800
int Min_Height = 3400;
int LiftAngle  = 2;
int Limit = 0;

Gyro lgyro;
Gyro rgyro;
