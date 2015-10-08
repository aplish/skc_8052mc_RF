//(Receiver )
#include <regx51.h>
#include <lcd.h>
#include <serial.h>
#include <stdio.h>
sbit ps2_data = P2^0;
sbit ps2_clk = P2^1;
void delayms(unsigned int);
unsigned int x,y;
void delayms(unsigned int ms)
{
for(x=0;x<ms;x++)
{
for(y=0;y<1275;y++);
}
}
main()
{
P2=0xff; //make output port
SerialInput();
InitLCD();
EA=1;
ES=1;
while(1)
{
ClearLCDScreen();
delayms(100)
}
}
37void major_ISR(void) interrupt 4
(
char msg;
while(RI==0); //ready to receive
msg=sbuf;
decrypt_msg=msg-3;
WriteDataToLCD(decrypt_msg);
Ri=0;
return
}
