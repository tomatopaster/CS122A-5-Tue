/************* t.c file of C2.5 **************/
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // data array
int sum;

#include <string.h>  // contains strlen(), strcmp(), etc.

#include "uart.h"  // UART driver code file

int tomato() {
  int i;
  sum = 10;
  char string[64];
  UART* up;
  uart_init();  // initialize UARTs
  sum = 100;
  up = &uart[0];  // test UART0
  uprints(up, "Enter lines from serial terminal 0\n\r");
  sum = 1000;

  for(i = 0; i < 4; i++){
    uprintf(up, "UART[");
    uputc(up, i + '0');
    uprintf(up, "] Baudrate: " );
    UART* currUart = &uart[i];
    int fuartclk = 7380000;
    int baudDivisor = *(currUart->base + UARTIBRD);
    // uputc(up, (fuartclk * 1) + '0');
    // unsigned char temp = *(currUart->base + UARTIBRD);
    // for (int j = 0; j < 8; j++){
    //   uprintf(up, ((temp & 0x80) == 0x80) ? "1" : "0");
    //   temp = temp << 1;
    // }
    uprintf(up, "%d", fuartclk/(16 * baudDivisor));
    uprintf(up, "\n\rUART[");
    uputc(up, i + '0');
    uprintf(up, "] Line Control Register: 0x" );
    unsigned char lcr = *(currUart->base + UARTLCR);
    uprintf(up, "%x", lcr);
    uprintf(up, "\n\r");

  }

  uprints(up, "Compute sum of array:\n\r");
  sum = 0;
  for (i = 0; i < 10; i++) sum += v[i];
  uprints(up, "sum = ");
  uputc(up, (sum / 10) + '0');
  uputc(up, (sum % 10) + '0');
  uprints(up, "\n\rEND OF RUN\n\r");
}