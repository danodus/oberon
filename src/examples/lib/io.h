#ifndef _IO_H_
#define _IO_H_

#include <stddef.h>

#define BASE_IO     0xE0000000

#define LED         (BASE_IO + 4)
#define UART_DATA   (BASE_IO + 8)
#define UART_STATUS (BASE_IO + 12)

#define MEM_WRITE(_addr_, _value_) (*((volatile unsigned int *)(_addr_)) = _value_)
#define MEM_READ(_addr_) *((volatile unsigned int *)(_addr_))

void print(const char *s);

#endif