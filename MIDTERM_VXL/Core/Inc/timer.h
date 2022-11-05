/*
 * timer.h
 *
 *  Created on: Oct 26, 2022
 *      Author: Tam Thanh Tin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;

void setTimer0 ( int duration );
void setTimer1 ( int duration );


void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim );

#endif /* INC_TIMER_H_ */
