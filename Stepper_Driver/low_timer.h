/*
  Low level functions for use with timer peripherals, not for use in application code
*/

#ifndef _LOW_TIMER_H_
#define _LOW_TIMER_H_

#include <stdint.h>

void ll_timer_tickrate_config(void);
void ll_timer_channel_config(void);

#endif /*_LOW_TIMER_H_*/
