#include "../h/main.h"
#include "../h/movement.h"
#include "../h/drueck.h"

/// DO NOT DELETE THIS METHOD
/// It is called every 1ms and e.g. can be used for implementing a
/// real time counter / clock.
void user_1ms_isr_type2(void) {
}

void ecrobot_device_initialize(void) {
}

void ecrobot_device_terminate(void) {
}

void hello_world() {
	ecrobot_status_monitor("Hello, World!");

}

TASK(OSEK_Main_Task) {
	while(1) {
		//Variablen
		hello_world();
		rotate();
		int Helligkeit;
		int Druck1;
		int Druck2;

		Druck1 = ecrobot_get_touch_sensor(NXT_PORT_S1);
		Druck2 = ecrobot_get_touch_sensor(NXT_PORT_S4);

		//Hinderniserkennung
		if(Druck1 && Druck2 == 1){
			drueck();
		}


		/* 500msec wait */
		systick_wait_ms(500);

		/*Helligkeit*/
		ecrobot_set_light_sensor_active(NXT_PORT_S3);
		Helligkeit = ecrobot_get_light_sensor(NXT_PORT_S3);

		/*Drive along line*/
		if(Helligkeit > 500){
			nxt_motor_set_speed(NXT_PORT_B,70,0);
			nxt_motor_set_speed(NXT_PORT_C,70,0);
		}
		/*Stop if white*/
		else {
			nxt_motor_set_speed(NXT_PORT_B,60,1);
			nxt_motor_set_speed(NXT_PORT_C,-60,1);
		}

		/* Drive along line if black */
		if(Helligkeit > 500){
		nxt_motor_set_speed(NXT_PORT_B, 70, 0);
		nxt_motor_set_speed(NXT_PORT_C, 70, 0);
		}


	}
