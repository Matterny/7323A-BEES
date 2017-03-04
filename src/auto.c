/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost,  the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous() {
  //startTask(power);
	ESTOP();

	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		lcdPrint(UART2, 0, option_1);
		lcdPrint(UART2, 1, "is running!");
		wait1Msec(200);                        // Robot waits for 2000 milliseconds
		startTask(SimpleAutonomous);
		wait1Msec(15000);
		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		lcdPrint(UART2, 0, option_2);
		lcdPrint(UART2, 1, "is running!");
		wait1Msec(200);                        // Robot waits for 2000 milliseconds
		startTask(reverseSimple);
		wait1Msec(15000);
		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3
		lcdPrint(UART2, 0, option_3);
		lcdPrint(UART2, 1, "is running!");
		wait1Msec(200);                        // Robot waits for 2000 milliseconds
		startTask(CubeAutonomous);
		wait1Msec(15000);
		break;
	case 3:
		//If count = 3, run the code correspoinding with choice 4
		lcdPrint(UART2, 0, option_4);
		lcdPrint(UART2, 1, "is running!");
		wait1Msec(200);                        // Robot waits for 2000 milliseconds
		startTask(SkillsAuton);
		wait1Msec(15000);
		break;
	default:
		lcdPrint(UART2, 0, "Line ~487")
		lcdPrint(UART2, 1, "option_not_found");
		break;
	}
}
