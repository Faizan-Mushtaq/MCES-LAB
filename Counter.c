#include<reg52.h>
typedef unsigned char tbyte;
typedef unsigned int tword;
void delayms(tword);
sbit key1=P3^2;
sbit key2=P3^3;
sbit key3=P3^4;
int main(void)
{
	tbyte count=0,i;
	tword del=1000;
	P0=0x00;
	while(1)
	{
		if(key1==0)
		{
				for(count=0;count<=99;count++)
			{
				P0=(count/10)<<4|count %10;
				delayms(1000);
			}
			P0=0x00;
		}
		if(key2==0)
		{
				for(count=99;count>=0;count--)
			{
				P0=(count/10)<<4|count %10;
				delayms(1000);
			}
			P0=0x00;
		}
		if(key3==0)
		{
			while(1)
			{
				for(i=0;i<8;i++)
				{
					P0=0x01<<i;
					delayms(1000);
				}
			}
		}
	}
}
void delayms(tword x)
{
	tword i;
	while(x--)
		for(i=0;i<120;i++);
}