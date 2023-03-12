#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>
#include "Lcd_lib.h"

void main(void) {
     
    CMCON=0x07;
    
     LCD_Initialize();
     
     LCD_KomutGonder(LCD_4BITMODE);             //İlk olarak function set ayarlanır.
     LCD_KomutGonder(LCD_CURSOR_BLINK);         //Display on/off control ayarlanır.
     LCD_KomutGonder(LCD_ENTRYMODE);            //Entry mode ayarlanır ve bu sıranın korunması gerekir.
          
     
     LCD_Print(0,0,"MERHABA");
     LCD_Print(1,0,"Mehmet Akif");       
    
    while(1) continue;
}
