#include "main.h"

/*
  temporrary inclusion
*/
#include "low_timer.h"
int main()
{
  System_Clock_Config();
  stepper_driver_init();
  stepper_driver_run();
  
  while(1)
  {
    /*do nothing*/
  }
  
}

