/*
 * input_processing.h
 *
 *  Created on: Oct 26, 2022
 *      Author: Tam Thanh Tin
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

extern int red_duration;
extern int yellow_duration;
extern int green_duration;
extern int Light_state_G;
extern int Light_state_H;
void sum(int x, int y, int z, int t);
void fsm_simple_buttons_run ( void );

#endif /* INC_INPUT_PROCESSING_H_ */
