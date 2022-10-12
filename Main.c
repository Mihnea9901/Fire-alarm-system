Main.c
#include <avr/io.h>
#define F_CPU 1000000
#define BAUD 4800
#define MYUBRR FOSC/16/BAUD-1
#define rs PB5
#define rw PB4
#define en PB3
#include "adc.h"
#include <util/delay.h>
#include <stdlib.h> //pt dtostrf
#include "dht.h"
#include "lcd.h"
#include "mq5.h"
#include "wifi.h"
#include "uart.h"
int main(void){
UART_Init (12);
char data[5];
char temp;
DDRB = 0xFF; // 1 este pentru output
DDRD = 0xFA; // 0 este pentru input
DDRC = 0x00; //
WiFi_Init();
TCCR1A |=(1<<WGM11)|(1<<COM1A1);
TCCR1B |=(1<<WGM12)|(1<<WGM13)|(1<<CS11);//CS11 PRESCALAR 8
ICR1 =2499;
init();
while(1){
PORTB=0x00;
displaychar("GAS:",2,1);
temp=(adcread(1)*10000)/1023;
dtostrf(temp, 7, 1, data);
displaychar(data,2,5);
displaychar("PPM",2,12);
float status=(adcread(3)*4.88)/10;
dtostrf(status, 7, 3, stat);
displaychar("TEMP:",1,1);
displaychar(stat,1,6);
UART_Send_String("AT+CIPSEND=0,12\r\n");
_delay_ms(50);
UART_Send_String(stat);
UART_Send_String(data);
if (!(PIND & 0x04)){
PORTB|=0x04;
displaychar("FIRE DETECTED ",2,1);
UART_Send_String("AT+CIPSEND=0,13\r\n");
_delay_ms(50);
UART_Send_String("FIRE DETECTED");
_delay_ms(999999999999999999999999999999999999999999999999999);
} if (temp>200)
{
PORTB|=0x04;
displaychar("GAS DETECTED ",2,1);
UART_Send_String("AT+CIPSEND=0,12\r\n");
_delay_ms(50);
UART_Send_String("GAS DETECTED");
}
OCR1A = 50;//la fiecare 500ms=>servo la 180
_delay_ms(500);
OCR1A = 300; // la fiecare 500ms=>servo la 0
_delay_ms(450);
}}
