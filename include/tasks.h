#ifndef _tasks_H_
#define _tasks_H_

// Sets the speeds of the left and right wheels of the chassis
void power();
void ESTOP();
void Lift(int used);
void LiftPOS(int value);
void LiftDown();
void	LiftUp();
extern int Max_Height;
extern int Mix_Height;
#endif // _CHASSIS_H_
