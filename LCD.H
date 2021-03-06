#ifndef __LCD_H
#define __LCD_H
//*******************
//Pin description
/*
P2.4 to P2.7 is data bus
P2.2 is RS
P2.3 is E
*/
//********************
// Defines Pins
sbit RS = P2^2;
sbit E = P2^3;
// Constants
#define E_Delay
250
void __delay_us(unsigned int d)
{
unsigned int i, limit;
limit = d/15;
for(i=0;i<limit;i++);
}
30void ToggleEpinOfLCD(void)
{
E = 1;
// Give a pulse on E pin
__delay_us(E_Delay); // so that LCD can latch the
E = 0;
// data from data bus
__delay_us(E_Delay);
}
void WriteDataToLCD(char t)
{
RS = 1;
// This is data
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= (t&0xF0); // Write Upper nibble of data
ToggleEpinOfLCD(); // Toggle E pin to send data
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= ((t<<4)&0xF0);// Write Lower nibble of data
ToggleEpinOfLCD(); // Toggle E pin to send data
}
void WriteIntToLCD(int v)
{RS=1;
P2&=0X0F;
P2|=(v&0XF0);
ToggleEpinOfLCD();
P2&=0X0F;
P2 |= ((v<<4)&0xF0);
ToggleEpinOfLCD();
}
void WriteCommandToLCD(int z)
{
RS = 0;
// This is command
31P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= (z&0xF0); // Write Upper nibble of data
ToggleEpinOfLCD(); // Toggle E pin to send data
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= ((z<<4)&0xF0);// Write Lower nibble of data
ToggleEpinOfLCD(); // Toggle E pin to send data
}
void InitLCD(void)
{
RS = 0;
E = 0;
// Make pin zero
// Make Pin zero
///////////// Reset process from datasheet /////////
__delay_us(15000);
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= 0x30;
// Write 0x3
ToggleEpinOfLCD(); // Toggle E pin to send data
__delay_us(4500);
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= 0x30;
// Write 0x3
ToggleEpinOfLCD(); // Toggle E pin to send data
__delay_us(300);
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= 0x30;
// Write 0x3
ToggleEpinOfLCD(); // Togg le E pin to send data
__delay_us(650);
P2 &= 0x0F;
// Make P2.4 to P2.7 zero
P2 |= 0x20;
// Write 0x2
ToggleEpinOfLCD(); // Toggle E pin to send data
32__delay_us(650);
/////////////////////////////////////////////////////
WriteCommandToLCD(0x28); //function set
WriteCommandToLCD(0x0c); //display on,cursor off,blink off
WriteCommandToLCD(0x01); //clear display
WriteCommandToLCD(0x06); //entry mode, set increment
}
void ClearLCDScreen(void)
// Clear the Screen and return cursor to zero position
{
WriteCommandToLCD(0x01); // Clear the screen
__delay_us(2000);
// Delay for cursor to return at zero position
}
void WriteStringToLCD(const char *s)
{
while(*s)
WriteDataToLCD(*s++);
}
// Function Declarations
void InitLCD(void);
void WriteCommandToLCD(int);
void WriteDataToLCD(char);
void ClearLCDScreen(void);
void WriteStringToLCD(const char*);
void DisplayTimeToLCD(unsigned char*) ;
void DisplayDateOnLCD( unsigned char*);
void WriteIntToLCD(int);
#endif
