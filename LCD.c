#include "lcd.h"
#define rs PB5
#define rw PB4
#define en PB3
#include <string.h>
void CMD()
{
    PORTB &= ~(1 << rs); /// rs=0 pt comenzi
    PORTB &= ~(1 << rw); /// rw=0
    PORTB |= (1 << en);  /// en=1
    _delay_ms(50);
    PORTB &= ~(1 << en); // en=0
}
void init()
{
    char a[] = {0x02, 0x28, 0x0e, 0x01, 0x80, 0x06}; // valori pt initializare
    for (int i = 0; i <= 5; i++)
    {
        PORTD = (a[i] & 0xF0); // trimite primii 4 biti
        CMD();
        PORTD = ((a[i] << 4) & 0xF0); // trimite urmatorii 4 biti
        CMD();
    }
}
void display()
{
    PORTB |= (1 << rs);  /// rs=1 pt date
    PORTB &= ~(1 << rw); /// rw=0
    PORTB |= (1 << en);  /// en=1
    _delay_ms(50);
    PORTB &= ~(1 << en); /// en=0
}
void displaychar(char t[], char Line, char pos)
{
    PORTB &= ~(1 << rs); // RS=0 mod comenzi
    if (Line == 1)
    {
        PORTD = ((0x80 + (pos - 1)) & 0xF0);
        CMD();
        PORTD = (((0x80 + (pos - 1)) << 4) & 0xF0);
        CMD(); // muta cursorul pe linia 1
    }
    else
    {
        PORTD = ((0xC0 + (pos - 1)) & 0xF0);
        CMD();
        PORTD = (((0xC0 + (pos - 1)) << 4) & 0xF0);
        CMD(); // muta cursorul pe linia 2
    }
    PORTB |= (1 << rs); // RS=1 mod date
    for (int j = 0; j < strlen(t); j++)
    {
        PORTD = (t[j] & 0xF0);
        display();
        PORTD = ((t[j] << 4) & 0xF0);
        display();
    }
}
