/*
 * Copyright (c) 2024 Jason A. F. Mitchell
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// Hardware Macros required by AVR Libc
/// Baud rate of USART
#define BAUD 9600
/// Frequency of CPU in Hz
#define F_CPU 16000000

#include <usart.h>
#include <util/delay.h>

int main(void)
{
    USART0_INIT();
    USART0_PRINT("Hello world!\r\n", 14);

    while (1) {
        _delay_ms(1);
    }
}
