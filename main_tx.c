(Transmitter)
#include <regx51.h>
#include <lcd.h>
#include <serial.h>
#include <stdio.h>
sbit ps2_data = P2^0;
sbit ps2_clk = P2^1;
unsigned char keyval
unsigned char Scan_Data();
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
while(ps2_clk==1);
keyval=scan_data();
WriteDataToLCD(keyval);
encrypt_data=keyval+3
35SerialTransmit();
delayms(100);
}
}
void major_ISR(void) interrupt 4
(
while(TI==1)
sbuf=encrypt_val;
ti=0;
return
}
unsigned char Scan_Data()
{
unsigned char Data=0,temp;
while(PS2_CLK==0);
for(i=0;i<10;i++)
{
temp=PS2_DATA;
while(PS2_CLK==0);
}
delayms(50);
P2=0x00;
return(Data);
}

