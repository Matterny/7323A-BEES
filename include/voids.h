#ifndef _voids_H_
#define _voids_H_

// Sets the speeds of the left and right wheels of the chassis
void drive(int straight, int strafe, int turning);
void closeClaw();
void openClaw();
void userclaw(bool open, bool close, int hold);
void stopAllMotors();
void wait1Msec(int duration);
extern int backRight;
extern int topLift;
extern int frontRight;//reverse
extern int rightClaw;//reverse
extern int midRight;//reverse
extern int midLeft;
extern int leftClaw;
extern int frontLeft;
extern int backLeft;
extern int bottomLift;//reverse
extern int clawtime;
#endif // _CHASSIS_H_
