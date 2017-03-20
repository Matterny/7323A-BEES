#include "main.h"    // includes API.h and other headers
#include "tasks.h" // redundant, but ensures that the corresponding header file (tasks.h) is included
#include "voids.h"
#include "GlobalVars.h"

void power()
{
    lcdSetBacklight(uart2, true);
    lcdPrint(uart2,2,"%1.1f   %1.1f   %1.1f", (double)powerLevelMain()/1000, (double)powerLevelBackup()/1000, (double)analogRead(status)/280);
}

void ESTOP(){

    int LiftAngle  = 2;
		//int pot = analogRead(LiftAngle);
		if (joystickGetDigital(1,7,JOY_RIGHT)+joystickGetDigital(2,7,JOY_RIGHT) == 0)
    {
			if (Min_Height <= analogRead(LiftAngle))
			{
				Limit = -1;
				//lcdPrint(uart2, 0, "Lift Limited");
				lcdPrint(uart2, 1, "Lift too low");
				lcdSetBacklight(uart2, true);
			}
			else if (Max_Height >= analogRead(LiftAngle))
			{
				Limit = 1;
				//lcdPrint(uart2, 0, "Lift Limited");
				lcdPrint(uart2, 1, "Lift too High");
				lcdSetBacklight(uart2,true);
			}
			else
			{
        Limit = 0;
				lcdPrint(uart2, 1, "Lift is safe");
				power();
				lcdSetBacklight(uart2, false);
			}
			while(joystickGetDigital(1,7,JOY_LEFT)==1)
			{
				stopAllMotors();
				delay(1);
				lcdSetBacklight(uart2,true);
			}

		}//end of E-Enable
}//end of while and end of task.

void Lift(int direction)//Lifts the claw
{ESTOP();
  int Limiting = Limit;
  if (Limiting == 0){
		motorSet(topLift,-127*direction);
		motorSet(bottomLift,-127*direction);
	}
	else if (abs(Limiting)>4){
		motorSet(topLift,0);
		motorSet(bottomLift,0);
	}
	else if (Limiting > 0){
		motorSet(topLift,127*(abs(direction)-direction)/2);
		motorSet(bottomLift,127*(abs(direction)-direction)/2);}
	else if (Limiting < 0){
		motorSet(topLift,-127*(abs(direction)+direction)/2);
		motorSet(bottomLift,-127*(abs(direction)+direction)/2);
	}
}

void LiftPOS(int value){
  while(value <= analogRead(LiftAngle))
  {
    motorSet(topLift,-127);
    motorSet(bottomLift,-127);
  }
  while(value >= analogRead(LiftAngle))
  {
    motorSet(topLift,127);
    motorSet(bottomLift,127);
  }
  while(value <= analogRead(LiftAngle))
  {
    motorSet(topLift,-50);
    motorSet(bottomLift,-50);
  }
  Lift(0);
}

void LiftDown()
{while(Min_Height >= analogRead(LiftAngle))
	{
		motorSet(topLift,127);
		motorSet(bottomLift,-127);
	}
	Lift(0);
}

void LiftUp()
{
  while(Max_Height <= analogRead(LiftAngle))
	{
		motorSet(topLift,-127);
		motorSet(bottomLift,127);
	}
	Lift(0);
}
