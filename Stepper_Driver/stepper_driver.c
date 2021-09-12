/*
  Stepper Motor driver application level functions
*/

#include "stepper_driver.h"

#include "low_timer.h"

/**
  * @brief  Stepper motor initialization of low level peripherals
  *
  * @param  None
  *
  * @retval None
  */
void stepper_driver_init(void)
{
  ll_timer_tickrate_config();
}

/**
  * @brief  Stepper motor peripheral run enable
  *
  * @param  None
  *
  * @retval None
  */
void stepper_driver_run(void)
{
  TIM2->CR1 |= (1 << 0);
}

/**
  * @brief  Stepper motor parameter and variables initialization
  *
  * @param  struct Stepper joint *, pointer to  structure
  *         which is used for working with stepper motor
  * @param  uint32_t maxSpeed, maximum speed allowed for stepper motor
  * @param  uint32_t minSpeed, minimum speed allowed for stepper motor
  *
  * @retval None
  */
void stepper_motor_config(struct Stepper * joint, uint32_t maxSpeed, uint32_t minSpeed);
