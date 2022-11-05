/*
 * input_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: Tam Thanh Tin
 */

#include "main.h"
#include"input_reading.h"
#include "display7SEG.h"
#include "EXTER_VARIABLE.h"
#include "timer.h"
int Time_Out_waiting=TIMEOUT;
int time_waiting=0;
void fsm_for_input_processing ( void ) {

switch (status){
case START:
	// If timer =0 or Second orThird button on Click then status switch to Waiting State
	if((button_flag[1]==1)|(button_flag[2]==1)|(timer==0)){
		status = WAITING;
		button_flag[1]=0;
		button_flag[2]=0;
		time_waiting=0;
		setTimer1(TIME_1S);

	}
	//IN START state we DISPLAY 7SEG and Decre timer by 1 second
	display7SEG(timer);
	if(timer1_flag==1){
		setTimer1(TIME_1S);
		timer--;
	}
	//RESET timer to Zero when click First Button
	if(button_flag[0]==1){
		button_flag[0]=1;
		timer=0;
	}
	break;
case WAITING:
	if(timer1_flag==1){
		time_waiting++;
		setTimer1(TIME_1S);
		display7SEG(timer);
	}
	//When in Waiting state, we need to waiting 10s to change START state
	if(time_waiting==Time_Out_waiting){
		setTimer1(TIME_1S);
		status=START; // Change to START state
	}
	// When Incre timer Check If timer > 9s set TO 0s ;
	if(timer>=MAX) timer = 0;
	// When Decre timer Check If timer < 0s set TO 9s ;
	if(timer<MIN) timer = 9;
	display7SEG(timer);
	// First button to set Display7SEG timer into Zero
	if(button_flag[0]==1){
		time_waiting=0;
		timer=0;
		button_flag[0]=0;

	}
	//Second button to Incre timer by 1 value;
	if(button_flag[1]==1){
		time_waiting=0;
		timer++;
		button_flag[1]=0;
		}
	//Third button to Decre timer by 1 value
	if(button_flag[2]==1){
		time_waiting=0;
		timer--;
		button_flag[2]=0;

			}

	break;

}

}
