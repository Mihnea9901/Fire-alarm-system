ADC.C
#include "adc.h"
void adcinit(){
DDRC=0x00; //portc input
ADMUX = 0x40;
ADCSRA |=(1<<ADEN)|(1<<ADPS2);
}
int adcread(char channel)
{
ADMUX = 0x40 | (channel & 0x0f); // 0100 0000 | (channel & 0000 0100)
ADCSRA |= (1<<ADSC); //start conversie
while (!(ADCSRA & (1<<ADIF))); //asteapta pana se termina conversia
ADCSRA |= (1<<ADIF); // interrupt flag pe 0
return ADCW; // returneaza cuvant
}
