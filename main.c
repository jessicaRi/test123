#include "../h/main.h"

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
	while (1) {
		hello_world();
		int Helligkeit;
		/* 500msec wait */
		systick_wait_ms(500);


		//nxt_motor_set_speed(NXT_PORT_B, 100, 0);
		/* Helligkeit */
		ecrobot_set_light_sensor_active(NXT_PORT_S3);
		Helligkeit = ecrobot_get_light_sensor(NXT_PORT_S3);

		/*Erkennen Hindernis*/


		/* Drive along line if black */
		if(Helligkeit > 500){
			nxt_motor_set_speed(NXT_PORT_B, 70, 0);
			nxt_motor_set_speed(NXT_PORT_C, 70, 0);
		}/*Stop if white*/ else{

			nxt_motor_set_speed(NXT_PORT_B, 60, 0);
			nxt_motor_set_speed(NXT_PORT_C, -60, 0);
			}
		}
	}


