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
void fsm_simple_buttons_run ( void ) {

switch (status){
case START:
	// If counter =0 or Second orThird button on Click then status switch to Waiting State
	if((button_flag[1]==1)|(button_flag[2]==1)|(counter==0)){
		status = WAITING;
		button_flag[1]=0;
		button_flag[2]=0;
		time_waiting=0;
		setTimer1(TIME_1S);

	}
	//IN START state we DISPLAY 7SEG and Decre counter by 1 second
	display7SEG(counter);
	if(timer1_flag==1){
		setTimer1(TIME_1S);
		counter--;
	}
	//RESET counter to Zero when click First Button
	if(button_flag[0]==1){
		button_flag[0]=1;
		counter=0;
	}
	break;
case WAITING:
	// Count time_waiting by 1 second
	if(timer1_flag==1){
		time_waiting++;
		setTimer1(TIME_1S);
		display7SEG(counter);
	}
	//When in Waiting state, we need to waiting 10s to change START state
	if(time_waiting==Time_Out_waiting){
		setTimer1(TIME_1S);
		status=START; // Change to START state
	}
	// When Incre counter Check If timer > 9s set TO 0s ;
	if(counter>=MAX) counter = 0;
	// When Decre counter Check If timer < 0s set TO 9s ;
	if(counter<MIN) counter = 9;
	display7SEG(counter);
	// First button to set Display7SEG counter into Zero
	if(button_flag[0]==1){
		time_waiting=0;
		counter=0;
		button_flag[0]=0;
	}
	//Second button to Incre counter by 1 value;
	if(button_flag[1]==1){
		time_waiting=0;
		counter++;
		button_flag[1]=0;
		}
	//Third button to Decre counter by 1 value
	if(button_flag[2]==1){
		time_waiting=0;
		counter--;
		button_flag[2]=0;
			}

	break;

}

}
