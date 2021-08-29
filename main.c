#include <stdint.h>
#include <stdlib.h>
#include "stm32f411xe.h"

#define DELAY_VALUE   500000U

int main()
{
  RCC->AHB1ENR = 0x01 << 2;
  
  uint32_t delay = DELAY_VALUE;
  GPIOC->MODER  = 0x01 << 26;
  GPIOC->OTYPER &= ~(0x01 << 13);
  GPIOC->PUPDR = 0x01 << 26;
  
  while(1)
  {
    GPIOC->ODR = 0x01 << 13;
    for(delay = DELAY_VALUE; delay > 0; delay--);
    GPIOC->ODR &= ~(0x01 << 13);
    for(delay = DELAY_VALUE; delay > 0; delay--);
  }
  
  
}


