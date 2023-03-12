#define SH_CP RB0  /*SRCLK*/
#define DS RB1     /*SER
#define ST_CP RB2  /*RCLK*/

#define SHCP_TRIS       TRISBbits.TRISB0
#define DS_TRIS       TRISBbits.TRISB1
#define STCP_TRIS       TRISBbits.TRISB2

#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>


void HC595_Initialize(void)
{
	//Clear all control pins
	PORTB=0;
	SHCP_TRIS = 0;	
	DS_TRIS = 0;
	STCP_TRIS = 0;
} // HC595_Initialize
/*******************************************/

void HC595_PutByte(unsigned char data)
{
	unsigned char i;
 for(i=0; i<8; i++)
	{
        // HC595_DS = data.7
        if( data & 0x80 )
            { DS = 1; } 
        else
            { DS = 0; }
        
        // Send the bit
        SH_CP = 1;
        __delay_us(10);      // wait for 10 Tcy
        SH_CP = 0;

        //Prepare for the next bit
        data <<= 1;
	} //for
}//HC595_PutByte

/********************************************/

void HC595_Load(void)
{
    ST_CP = 1;
    __delay_us(10);      // wait for 10 Tcy
    ST_CP = 0;

} //HC595_Load