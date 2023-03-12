#ifndef Lcd_lib
#define	Lcd_lib

#define LCD_4BITMODE           0x28 //0010 1000
#define LCD_8BITMODE           0x38 //0011 1000

#define LCD_CLEAR              0x01 //0000 0001
#define LCD_RETURNHOME         0x02 //0000 0010

#define LCD_LINE1              0x80 //1000 0000
#define LCD_LINE2              0xC0 //1100 0000

#define LCD_CURSOR_BLINK       0x0F //0000 1111
#define LCD_TersYazdir         0x04 //0000 0100
#define LCD_KayarakYazdir      0x05 //0000 0101

#define LCD_ENTRYMODE          0x06 //0000 0110

void pulseEnable(void);
void LCD_Initialize(void);
void LCD_Gonder(unsigned char);
void LCD_KomutGonder(char);
void LCD_VeriGonder(char);
void LCD_Print(char, char, char*);
void LCD_GotoXY(char, char);

#endif 