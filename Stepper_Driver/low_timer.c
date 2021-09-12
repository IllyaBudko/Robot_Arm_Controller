/*
  Low level functions for use with timer peripherals, not for use in application code
*/

#include "low_timer.h"

/**
  * @brief  TIM2 timer base frequency configuration
  *
  * @param  None
  *
  * @retval None
  */
void ll_timer_tickrate_config(void)
{
  /*Turn on TIM2 Clock if not on*/
  if(!(RCC->APB1ENR & RCC_APB1ENR_TIM2EN))
  {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  }
  
  /*
    TIM2 setup to update CNT register at 1uS interval
  */
  TIM2->ARR = 0xFFFFFFFFUL - 1;
  TIM2->PSC = 16 - 1;
  
  /*TIM2 count direction UP*/
  TIM2->CR1 &= ~(1 << 4);
  
  /*TIM2 edge alignment*/
  TIM2->CR1 &= ~(0x03 << 5);
  
}

/**
  * @brief  TIM2 timer channel configuration
  *
  * @param  None
  *
  * @retval None
  */
void ll_timer_channel_config(void)
{
  
}

/**
  * TIM2 Interrupt handler
  */

void TIM2_IRQHandler(void)
{
  
}
