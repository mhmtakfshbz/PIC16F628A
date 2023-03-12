#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>
#include "Hc_595.h"


unsigned char dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x07F,0x06F};

void main(void) 
{
    unsigned char i,j;
    
    HC595_Initialize();
    
    while(1)
    {   for(j=0;j<10;j++){
            for (i=0; i<10; i++)
            {
             HC595_PutByte( dizi[i] );
             HC595_PutByte( dizi[j] );
             HC595_Load();
            __delay_ms(200);
            }
        }
    }
}
