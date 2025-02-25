#ifndef __TIMER15_DRIVER_H
#define __TIMER15_DRIVER_H

#include <stdint.h>

void timer15_init(void);

void timer15_enable(void);
void timer15_disable(void);

void timer15_capture_set_period(uint32_t ms);

#endif
