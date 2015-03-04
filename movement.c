/*
 * movement.c
 *
 *  Created on: 04.03.2015
 *      Author: Jessica
 */
#include "../h/main.h"

void rotate(){
	//Drehung
	nxt_motor_set_speed(NXT_PORT_B,60,0);
	nxt_motor_set_speed(NXT_PORT_C,-60,0);
	return;
}

void move(){
	//Fahren
	nxt_motor_set_speed(NXT_PORT_B, 70, 0);
	nxt_motor_set_speed(NXT_PORT_C, 70, 0);
	return;
}

void stop(){
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	return;
}

void search(){
	systick_wait_ms(500);
	nxt_motor_set_count(NXT_PORT_B, 90);
	nxt_motor_set_count(NXT_PORT_C, 90);
	return;
}
