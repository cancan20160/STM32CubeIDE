/*
 * state_machine.h
 *
 *  Created on: Feb 6, 2025
 *      Author: leagu
 */

#ifndef INC_STATE_MACHINE_H_
#define INC_STATE_MACHINE_H_

#include "main.h"
#include "usbd_cdc_if.h"

typedef enum {
	STATE_INIT = 0, STATE_LED1, STATE_LED2, STATE_LED3, STATE_LED4,
} state_Type;

void state_machine_init(void);
void state_LED1_function(void);
void state_LED2_function(void);
void state_LED3_function(void);
void state_LED4_function(void);

#endif /* INC_STATE_MACHINE_H_ */
