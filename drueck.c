/*
 * drueck.c
 *
 *  Created on: 04.03.2015
 *      Author: Jessica
 */

#include "../h/main.h"
#include "../h/movement.h"


void drueck(){

		//Hinderniserkennung
		ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
		stop();
		ecrobot_sound_tone(220,100,50);
		systick_wait_ms(10000);

		return;
}
