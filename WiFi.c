#include "wifi.h"
#include <util/delay.h>
void WiFi_Init(void)
{
char
mode[]={"AT+CWMODE=1\r\n"}, // mod statie
join[]={"AT+CWJAP=\"TP-Link_05D4\",\"123456798\"\r\n"}, // conectare retea wifi
connection[]={"AT+CIPMUX=1\r\n"}, // mai multe conexiuni
server[]={"AT+CIPSERVER=1,80\r\n"}; // activare server
USART_Send_String(mode);
_delay_ms(600);
USART_Send_String(connection);
_delay_ms(600);
USART_Send_String(server);
_delay_ms(600);
USART_Send_String(join);
_delay_ms(2000);
}
