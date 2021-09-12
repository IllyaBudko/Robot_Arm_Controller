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
    TIM2 setup to update CNT register at 100uS interval
  */
  TIM2->ARR = 0xFFFFFFFFUL;
  TIM2->PSC = 16;
  
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
  /*Enable GPIOA clock if not already on*/
  if(!(RCC->AHB1ENR & RCC_AHB1ENR_GPIOAEN))
  {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  }

  GPIOA->MODER  |= (0x01 << 0) | (0x01 << 2) | (0x01 << 4) | (0x01 << 6);
  
  /*Set all channels as output*/
  TIM2->CCMR1 &= ~(0x03 << 0);
  TIM2->CCMR1 &= ~(0x03 << 8);
  TIM2->CCMR2 &= ~(0x03 << 0);
  TIM2->CCMR2 &= ~(0x03 << 8);
  
  /*Set output compare mode, set channel to frozen*/
  TIM2->CCMR1 &= ~(0x07 << 4);
  TIM2->CCMR1 &= ~(0x07 << 12);
  TIM2->CCMR2 &= ~(0x07 << 4);
  TIM2->CCMR2 &= ~(0x07 << 12);
  
  /*Set initial output compare register to 100*/
  TIM2->CCR1 = 15000;
  TIM2->CCR2 = 5000;
  TIM2->CCR3 = 5000;
  TIM2->CCR4 = 10000;
  
  /*Enable interrupts*/
  TIM2->DIER |= (0x01 << 1);
  TIM2->DIER |= (0x01 << 2);
  TIM2->DIER |= (0x01 << 3);
  TIM2->DIER |= (0x01 << 4);
  
  NVIC_EnableIRQ(TIM2_IRQn);
}

/**
  * TIM2 Interrupt handler
  */

void TIM2_IRQHandler(void)
{
  
  TIM2->CR1 &= ~(1 << 0);
  do
  {
    if(TIM2->SR & TIM_SR_CC1IF)
    {
      TIM2->SR &= ~TIM_SR_CC1IF;
      
      static uint32_t counter = 0;
      uint32_t temp = TIM2->CCR1;
      uint32_t tmp = temp;
      
      GPIOA->ODR |= (0x01 << 0);
      GPIOA->ODR &= ~(0x01 << 0);
      tmp = ((2 * temp) / (4 * counter + 1));
      if(tmp < 10000)
      {
        tmp = 10000;
      }
      tmp = temp + tmp;
      TIM2->CCR1 = tmp;
      counter++;
    }
    else if(TIM2->SR & TIM_SR_CC2IF)
    {
      TIM2->SR &= ~TIM_SR_CC2IF;
      
      static uint32_t counter = 0;
      uint32_t temp = TIM2->CCR2;
      uint32_t tmp = temp;
      
      GPIOA->ODR |= (0x01 << 1);
      GPIOA->ODR &= ~(0x01 << 1);
      tmp = temp + ((2 * temp) / (4 * counter + 1));
      TIM2->CCR2 = tmp;
      counter++;
    }
    else if(TIM2->SR & TIM_SR_CC3IF)
    {
      TIM2->SR &= ~TIM_SR_CC3IF;
      
      static uint32_t counter = 0;
      uint32_t temp = TIM2->CCR3;
      uint32_t tmp = temp;
      
      GPIOA->ODR |= (0x01 << 2);
      GPIOA->ODR &= ~(0x01 << 2);
      tmp = temp + ((2 * temp) / (4 * counter + 1));
      TIM2->CCR3 = tmp;
      counter++;
    }
    else if(TIM2->SR & TIM_SR_CC4IF)
    {
      TIM2->SR &= ~TIM_SR_CC4IF;
      
      static uint32_t counter = 0;
      uint32_t temp = TIM2->CCR4;
      uint32_t tmp = temp;
      
      GPIOA->ODR |= (0x01 << 3);
      GPIOA->ODR &= ~(0x01 << 3);
      tmp = temp + ((2 * temp) / (4 * counter + 1));
      TIM2->CCR4 = tmp;
      counter++;
    }
  }
  while(TIM2->SR & TIM_SR_CC1IF || TIM2->SR & TIM_SR_CC2IF || TIM2->SR & TIM_SR_CC3IF || TIM2->SR & TIM_SR_CC4IF);
  NVIC_ClearPendingIRQ(TIM2_IRQn);
  TIM2->CR1 |= (1 << 0);
}





