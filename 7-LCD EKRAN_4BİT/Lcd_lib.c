
#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>

#define LCD_RS      RA0
#define LCD_E       RA1
#define LCD_DATA    PORTB

#define LCD_RS_Tris      TRISA0
#define LCD_E_Tris       TRISA1
#define LCD_DATA_Tris    TRISB

void pulseEnable() {
    LCD_E = 0;
    __delay_us(5);
    LCD_E = 1;
    __delay_us(5);
    LCD_E = 0;
    
}

void LCD_Gonder(unsigned char veri) {
   
    LCD_DATA = veri;
    pulseEnable();
    
    veri<<=4; 

    LCD_DATA = veri;    
    pulseEnable();

    __delay_us(50);
}

void LCD_KomutGonder(char komut) {
    LCD_RS = 0;
    LCD_Gonder(komut);
}


void LCD_VeriGonder(char veri) {
    LCD_RS = 1;
    LCD_Gonder(veri);
}

void LCD_GotoXY(char satir, char sutun) 
{
    if (satir == 0)     LCD_KomutGonder(0x80 + sutun);
    else                LCD_KomutGonder(0x80 + 0x40 + sutun);   
}

void LCD_Print (char str_satir, char str_sutun, char* metin) 
{
    LCD_GotoXY(str_satir, str_sutun);
    while(*metin)
    {
        LCD_VeriGonder(*metin);
        metin++;
    }        
}

void LCD_Initialize() {
    LCD_E = 0;
    LCD_RS = 0;
    LCD_DATA = 0;
    
    LCD_RS_Tris = 0;
    LCD_E_Tris = 0;
    LCD_DATA_Tris = 0;

    __delay_ms(500);
    LCD_KomutGonder(0b0011);  //function set
    __delay_ms(5);
    LCD_KomutGonder(0b0011); 
    __delay_us(500);
    LCD_KomutGonder(0b0011); 
    __delay_us(500);
    LCD_KomutGonder(0b0010);
}