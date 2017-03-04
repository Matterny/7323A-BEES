#include "main.h"    // includes API.h and other headers
#include "voids.h" // redundant, but ensures that the corresponding header file (voids.h) is included




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



void drive(int straight, int strafe, int turning) //Moves the robot a disired amount
{int X2 = 0, Y1 = 0, X1 = 0, threshold = 30;
	//Create "deadzone" for Y1/Ch3
	if(abs(straight) > threshold)
		Y1 = straight*driveSign;
	else
		Y1 = 0;
	//Create "deadzone" for X1/Ch4
	if(abs(strafe) > threshold)
		X1 = strafe*driveSign;
	else
		X1 = 0;
	//Create "deadzone" for X2/Ch1
	if(abs(turning) > threshold)
		X2 = turning*driveSign;
	else
		X2 = 0;
	//Remote Control Commands
	motorSet(frontRight, -(Y1 - X2));
	motorSet(backRight,-(Y1 - X2 + X1));
	motorSet(midRight,-(Y1 - X2));
	motorSet(frontLeft,Y1 + X2);
	motorSet(backLeft, -(Y1 + X2 - X1));
	motorSet(midLeft,Y1 + X2);
}

void closeClaw() //Starts closing the claw
{
	motorSet(leftClaw, -100);
	motorSet(rightClaw,-100);
}

void openClaw() //Starts opening the claw
{
	motorSet(leftClaw, 100);
	motorSet(rightClaw, 100);
}
void stopClaw() //Stops the claw from moving
{
	motorStop(leftClaw);
	motorStop(rightClaw);
}

  void userclaw(bool open, bool close, int hold)
{		if (open){ //Starts closing the claw when the user presses 8D
		motorSet(rightClaw,-100*clawEnable);
    motorSet(leftClaw, 100*clawEnable);
		holdSet=0;
  }
	else if (close){ //Starts opening the claw when the user presses 8D
		motorSet(rightClaw,100*clawEnable);
    motorSet(leftClaw,-100*clawEnable);
		holdSet=0;
  }
	else{
		motorSet(rightClaw, 50*holdSet*clawEnable);
		motorSet(leftClaw,-50*holdSet*clawEnable);
	}
	if(hold){
		holdSet = 1;
	}
}


	void stopAllMotors()
	{
	motorSet(1, 0);
	motorSet(2, 0);
	motorSet(3, 0);
	motorSet(4, 0);
	motorSet(5, 0);
	motorSet(6, 0);
	motorSet(7, 0);
	motorSet(8, 0);
	motorSet(9, 0);
	motorSet(10, 0);
	}
	void wait1Msec(int duration)
	{
		delay(duration);

	}
