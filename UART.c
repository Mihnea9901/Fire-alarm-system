UART.C
#include "uart.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h> //header to enable delay function in program
#include <stdlib.h> //pt dtostrf
void UART_Init( unsigned int ubrr)
{
UBRRH = (unsigned char)(ubrr>>8); // pt baud rate
UBRRL = (unsigned char)ubrr; // pt baud rate
UCSRB = (1<<RXEN)|(1<<TXEN); // activeaza rx tx
UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0); //8 biti de date 1 bit stop
}
void UART_Transmit( unsigned char data )
{
while ( !( UCSRA & (1<<UDRE)) ); // asteapta pana bufferul e gol
UDR = data; //pune datele in buffer
}
unsigned char UART_Receive( void )
{
while ( !(UCSRA & (1<<RXC)) ); // asteapta ca datele sa fie primite
return UDR; // returneaza datele din buffer
}
void UART_Send_String (unsigned char string[])
{
unsigned char i=0;
do
{
USART_Transmit(string[i]); // trimite cate un octet pana stringul este gol
i++;
} while(string[i]!=0);
}
