#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>
#include "Lcd_lib.h"

void main(void){

    TRISA=0;
    TRISB=0;
    PORTB=0;
    PORTA=0;

LCD_Initialize();
    
    LCD_Write(1,1,"Merhaba");
    LCD_Write(1,9,"Akif");
  
    while (1){
        
    }
      
}

    

