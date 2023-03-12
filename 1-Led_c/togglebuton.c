#include "PIC16F628A_PRAGMA.INC" 
#define _XTAL_FREQ 4000000
#include <xc.h>


void main() {
    TRISB = 0b00000001; // PORTB.0 giriş, PORTB.1 çıkış
    PORTB = 0b00000010; // LED'i yak

    while (1) {
        if (PORTBbits.RB0 == 0) { // Toggle butonu kontrol et
            __delay_ms(200); // De-bounce için bir gecikme ekle
            if (PORTBbits.RB0 == 0) { // De-bounced!
                PORTBbits.RB1 = ~PORTBbits.RB1; // LED durumunu tersine çevir
            }
        }
    }
}