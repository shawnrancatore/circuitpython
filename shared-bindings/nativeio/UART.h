/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Scott Shawcroft for Adafruit Industries
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

#ifndef __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_UART_H__
#define __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_UART_H__

#include "common-hal/microcontroller/types.h"
#include "common-hal/nativeio/types.h"

extern const mp_obj_type_t nativeio_uart_type;

typedef enum {
    PARITY_NONE,
    PARITY_EVEN,
    PARITY_ODD
} uart_parity_t;

// Construct an underlying UART object.
extern void common_hal_nativeio_uart_construct(nativeio_uart_obj_t *self,
    const mcu_pin_obj_t * tx, const mcu_pin_obj_t * rx, uint32_t baudrate,
    uint8_t bits, uart_parity_t parity, uint8_t stop, uint32_t timeout,
    uint8_t receiver_buffer_size);

extern void common_hal_nativeio_uart_deinit(nativeio_uart_obj_t *self);

// Read characters. len is in characters NOT bytes!
extern size_t common_hal_nativeio_uart_read(nativeio_uart_obj_t *self,
    uint8_t *data, size_t len, int *errcode);

// Write characters. len is in characters NOT bytes!
extern size_t common_hal_nativeio_uart_write(nativeio_uart_obj_t *self,
                              const uint8_t *data, size_t len, int *errcode);

extern uint32_t common_hal_nativeio_uart_rx_characters_available(nativeio_uart_obj_t *self);
extern bool common_hal_nativeio_uart_ready_to_tx(nativeio_uart_obj_t *self);

#endif  // __MICROPY_INCLUDED_SHARED_BINDINGS_NATIVEIO_UART_H__
