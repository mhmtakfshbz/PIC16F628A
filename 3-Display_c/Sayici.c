#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
TRISB=0;
PORTB=0;
unsigned char i,dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x07F,0x06F};
    while(1)
    {
        for(i=0;i<10;i++)
        {
            PORTB=dizi[i];
            __delay_ms(500);
        }                    
    }
}