#ifndef _GlobalVars_H_
#define _GlobalVars_H_

extern int count;//Which autonomous to do by default
extern const unsigned int leftButton;//Pre-Auton Variables
extern const unsigned int centerButton;
extern const unsigned int rightButton;
extern char option_1[];
extern char option_2[];
extern char option_3[];
extern char option_4[];
extern char Mode[];

extern int clawtime;
extern int clawsign;							//Needs to be either 1 or -1
extern int clawEnable;						//Needs to be either 0 or 1
extern int clawFuzz;							//How far does the claw move in ESTOP_RATE ms
extern int clawStartTime;
extern int ESTOP_RATE;
extern int driveSign;
extern int holdSet;


extern int backRight;
extern int topLift;
extern int frontRight;//reverse
extern int rightClaw;//reverse
extern int midRight;//reverse
extern int midLeft;
extern int leftClaw;
extern int frontLeft;
extern int bottomLift;     //reverse
extern int backLeft;

extern int Bat1;
extern int Bat2;
extern int Bat3;
extern int status;
extern int Max_Height;		//The value of the maximum desired height of the lift - 0800
extern int Min_Height;
extern int LiftAngle;
extern int Limit;

extern Gyro lgyro;
extern Gyro rgyro;

#endif // _CHASSIS_H_
