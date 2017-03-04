
#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */


 int count = 0;//Which autonomous to do by default
 const unsigned int leftButton = 1;//Pre-Auton Variables
 const unsigned int centerButton = 2;
 const unsigned int rightButton = 4;
 char option_1[] = "Simple Auton";//Replaced all strings with char arrays
 char option_2[] = "Left Cube";
 char option_3[] = "Right Cube";
 char option_4[] = "Skills Auton";
 char Mode[] = "Usercontrol";

 void waitForPress()
 {
 	while(lcdReadButtons(uart2) == 0){}
 	delay(5);
 }

 void waitForRelease()
 {
 	while(lcdReadButtons(uart2) != 0){}
 	delay(5);
 }



void initializeIO()
{
	//------------- Beginning of User Interface Code ---------------
	//Loop while center button is not pressed
	while((lcdReadButtons(uart2) != centerButton)-(isEnabled()))
	{ lcdSetBacklight(uart2,true);
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			lcdPrint(uart2, 0, option_1);
			lcdPrint(uart2, 1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(lcdReadButtons(uart2) == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(lcdReadButtons(uart2) == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			lcdPrint(uart2, 0, option_2);
			lcdPrint(uart2, 1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(lcdReadButtons(uart2) == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(lcdReadButtons(uart2) == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			lcdPrint(uart2, 0, option_3);
			lcdPrint(uart2, 1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(lcdReadButtons(uart2) == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(lcdReadButtons(uart2) == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			lcdPrint(uart2, 0, option_4);
			lcdPrint(uart2, 1, "<         Enter        >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(lcdReadButtons(uart2) == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(lcdReadButtons(uart2) == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
	while(!isEnabled())
	{	lcdPrint(uart2, 0, "Option"  );
		lcdPrint(uart2, 1, "Selected");
		delay(100);
	}
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() {
lcdInit(uart2);
lcdClear(uart2);
lcdPrint(uart2,0,"starting up");

}
