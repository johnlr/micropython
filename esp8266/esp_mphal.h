/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _INCLUDED_MPHAL_H_
#define _INCLUDED_MPHAL_H_

#include "py/ringbuf.h"

struct _mp_print_t;
// Structure for UART-only output via mp_printf()
extern const struct _mp_print_t mp_debug_print;

extern ringbuf_t input_buf;
// Call this after putting data to input_buf
void mp_hal_signal_input(void);
// Call this when data is available in dupterm object
void mp_hal_signal_dupterm_input(void);

void mp_hal_init(void);
void mp_hal_rtc_init(void);
void mp_hal_feed_watchdog(void);

uint32_t mp_hal_ticks_us(void);
void mp_hal_delay_us(uint32_t);
void mp_hal_set_interrupt_char(int c);
uint32_t mp_hal_get_cpu_freq(void);

#define UART_TASK_ID 0
#define DUPTERM_TASK_ID 1
void uart_task_init();
void dupterm_task_init();

void ets_event_poll(void);
#define ETS_POLL_WHILE(cond) { while (cond) ets_event_poll(); }

#endif // _INCLUDED_MPHAL_H_
