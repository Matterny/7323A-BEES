#include "main.h"
#include "voids.h"
#include "tasks.h"
#include "autoncmds.h"
#include "options.h"

void SkillsAuton()
{}



void SimpleAutonomous()
{
	closeClaw();
	delay(1500);
	stopClaw();
	LiftUp();
	drive(127,0,0);  //Moves the robot forward
	delay(2500);
	stopAllMotors();
	openClaw();
	delay(700);
	stopClaw();
	delay(10);
	closeClaw();
	delay(700);
	userclaw(0,0,1);
	LiftUp();
	drive(-127,0,0);
	delay(1000);
	stopAllMotors();
	LiftPOS(1550);
	openClaw();
	delay(700);
	stopClaw();
	stopAllMotors();
	drive(127,0,0);
	delay(1000);
	drive(-127,0,0);
	delay(1000);
	stopAllMotors();
	LiftDown();
	delay(600);
	stopAllMotors();
	drive(127,0,0);
	delay(1500);
	stopAllMotors();
	drive(-127,0,0);
	delay(800);
	stopAllMotors();
}

void reverseSimple()
{
	drive(127,0,0);
	delay(1000);
	stopAllMotors();
	closeClaw();
	delay(clawtime*2);
	userclaw(0,0,1);
	stopAllMotors();
	userclaw(0,0,1);
	LiftUp();
	drive(0,0,-127);
	delay(450);
	drive(127,0,0);
	delay(1500);
	drive(0,0,0);
	userclaw(1,0,0);
	delay(20);
	stopClaw();
	openClaw();
	delay(500);
	stopClaw();
}


void CubeAutonomous()
{
	drive(127,0,0);
	delay(1000);
	stopAllMotors();
	closeClaw();
	delay(clawtime*2);
	userclaw(0,0,1);
	stopAllMotors();
	userclaw(0,0,1);
	LiftUp();
	drive(0,0,127);
	delay(450);
	drive(127,0,0);
	delay(1500);
	drive(0,0,0);
	userclaw(1,0,0);
	delay(20);
	stopClaw();
	openClaw();
	delay(500);
	stopClaw();
}
