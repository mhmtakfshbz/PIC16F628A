#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
TRISB0=0;
TRISA0=1;
    while(1)
    {
        if(RA0==1)
        {
            RB0=1;
        }
        else
        RB0=0;              
    }
}