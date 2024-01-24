/*
 * Copyright (c) 2024 Jason A. F. Mitchell
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef USART__H__
#define USART__H__

#include <avr/io.h>
#include <stdint.h>
#include <util/setbaud.h>

// UCSRnA Pin Positions
#define RXCn 7
#define TXCn 6
#define UDREn 5
#define FEn 4
#define DORn 3
#define UPEn 2
#define U2Xn 1
#define MPCMn 0

// UCSRnB Pin Positions
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define TXB8 0

// UCSRnC Pin Positions
#define UMSEL1 7
#define UMSEL0 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0

#define USART0_INIT()                            \
    {                                            \
        /* Set baud rate */                      \
        UBRR0H = UBRRH_VALUE;                    \
        UBRR0L = UBRRL_VALUE;                    \
        /* Enable receiver and transmitter */    \
        UCSR0B = (1 << RXEN) | (1 << TXEN);      \
        /* Set frame format: 8data, 2stop bit */ \
        UCSR0C = (1 << USBS) | (3 << UCSZ0);     \
    }

#define USART0_PRINT(string_value, length)           \
    {                                                \
        char string_to_print[length] = string_value; \
        for (int i = 0; i < length; i++) {           \
            while ((UCSR0A & (1 << UDREn)) == 0) {   \
                /* Wait for ready bit */             \
            }                                        \
            UDR0 = string_to_print[i];               \
        }                                            \
    }

#endif // USART__H__
