#include "main.h"

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

