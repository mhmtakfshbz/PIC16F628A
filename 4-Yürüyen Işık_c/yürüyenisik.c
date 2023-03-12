#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
TRISB=0;
PORTB=0;

unsigned char i,led=1;
    while(1)
    {
        for(i=0;i<7;i++)
        {
        PORTB=led;
        led=led << 1;
        __delay_ms(500);
        }
        for(i=0;i<7;i++)
        {
        PORTB=led;
        led=led >> 1;
        __delay_ms(500);
        }
    }   
}