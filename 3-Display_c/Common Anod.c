#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
TRISB=0;
TRISA0=1;
PORTB=1;
unsigned char i,dizi[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
PORTB=0xFF;
    while(1)
    {
        if(RA0==0)
        {   
            i++; 
            if(i==10) i=0;               
        } 
        PORTB=dizi[i];
            __delay_ms(300);
                               
    }
}