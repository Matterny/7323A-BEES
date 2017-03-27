#include "main.h"    // includes API.h and other headers
#include "tasks.h" // redundant, but ensures that the corresponding header file (tasks.h) is included
#include "voids.h"
#include "GlobalVars.h"

int avgRot()
{
  return (gyroGet(lgyro)+gyroGet(rgyro))/2;
}
