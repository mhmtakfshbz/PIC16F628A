#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
TRISB=0;
TRISA0=1;
PORTB=0;
unsigned char i,dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
PORTB=dizi[0];
    while(1)
    {
        if(RA0==1)
        {   
            i++; 
            if(i==10) i=0;               
        } 
        PORTB=dizi[i];
            __delay_ms(300);
                               
    }
}