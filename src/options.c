#include "main.h"
#include "voids.h"
#include "tasks.h"
#include "options.h"
#include "gyros.h"
void SkillsAuton()
{}
void delayStop(int duration)//Stops all motors after the specified duration.
{	delay(duration);
	stopAllMotors();}


void SimpleAutonomous()//Is old and reliable, few points
{
	closeClaw();
	delay(1500);
	stopAllMotors();
	LiftUp();
	drive(127,0,0);  //Moves the robot forward
	delayStop(2500);
	openClaw();
	delayStop(700);
	delay(10);
	closeClaw();
	delay(700);
	userclaw(0,0,1);
	LiftUp();
	drive(-127,0,0);
	delayStop(1000);
	LiftPOS(1550);
	openClaw();
	delayStop(700);
	drive(127,0,0);
	delay(1000);
	drive(-127,0,0);
	delayStop(1000);
	LiftDown();
	delayStop(600);
	drive(127,0,0);
	delayStop(1500);
	drive(-127,0,0);
	delayStop(800);
}

void reverseSimple()
{
}


void CubeAutonomous()
{
	openClaw();
	delayStop(750);//claw open, origin, forward
	forward(900);
	angleSet(90);//claw open, (0,900), in
	forward(500);
	closeClaw();//claw closed, (500,900), in
	delayStop(500);
  delay(500);
}

void autonTest(int run)
{if(run) CubeAutonomous();
}

void wallAuton()
{
}
