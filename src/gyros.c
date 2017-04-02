#include "main.h"    // includes API.h and other headers
#include "tasks.h" // redundant, but ensures that the corresponding header file (tasks.h) is included
#include "voids.h"
#include "GlobalVars.h"

int avgRot()
{
  return (gyroGet(lgyro)+gyroGet(rgyro))/2;
}

void angleSet(int degree)
{
while(degree > avgRot())//coarse ajust
  {drive(0,0,-127);}
  delay(50);
while(degree < avgRot())//coarse ajust
{drive(0,0, 127);}
delay(50);
while(degree > avgRot())//fine ajust
  {drive(0,0,-5*(degree - avgRot()));}
  delay(20);
//while(degree < avgRot())//fine ajust
//{drive(0,0, -20*(degree - avgRot()));}
}

void angleAdd(int degree){
  angleSet(avgRot()+degree);
}

void forward(int timeDist)
{
  drive(127,0,0);
  delay(timeDist);
  drive(0,0,0);
}
