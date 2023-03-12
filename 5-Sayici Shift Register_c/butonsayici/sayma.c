#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>
#include "Hc_595.h"

signed char J = 0;      
unsigned char dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x07F,0x06F};

void main(void){
    TRISB0=1;
    TRISB1=1;
    HC595_Initialize();

    PORTB=0;
    PORTA=0;

    
    while(1)
    {
        if(RB0==0)
        {
            J++; 
            if(J>99) J=0;   
        }
        if(RB1==0)
        {
            J--;
            if(J<0) J=99;
        }
        HC595_PutByte( dizi[J%10] );
        HC595_PutByte( dizi[J/10] );
        HC595_Load();
            __delay_ms(200);

    }
}