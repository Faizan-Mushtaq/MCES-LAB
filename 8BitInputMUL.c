#include<reg52.h>
typedef unsigned char tbyte;
typedef unsigned int tword;

void delayms(tword);
tbyte readinput(void);
sbit SEL=P1^4;
sbit key1=P3^2;
sbit key2=P3^3;
sbit key3=P3^4;
int main(void)
{
	tword a=0,b=0,c=0;
	P0=0x00;
	while(1)
	{
		if(!key1)
		{
			a=readinput();
			P0=a;
			delayms(1000);
			P0=0x00;
			delayms(1000);
		}
		if(!key2)
		{
			b=readinput();
			P0=b;
			delayms(1000);
			P0=0x00;
			delayms(1000);
		}
		if(!key3)
		{
			c=a*b;
			P0=c & 0XFF;
			delayms(1000);
			P0=c >>8;
			delayms(1000);
			P0=0x00;
		}
	}
}
tbyte readinput(void)
{
	tbyte temp=0;
	SEL=0;
	temp=P1&0x0F;
	SEL=1;
	temp=(P1&0x0F)<<4 |temp;
	return temp;
}
void delayms(tword x)
{
	tbyte i;
	while(x--)
		for(i=0;i<120;i++);
}