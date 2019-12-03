#include<reg52.h>
typedef unsigned char tbyte;
typedef unsigned int tword;

sbit DAT=P0^0;
sbit CLK=P0^1;
void delayms(tword);
void writeseg(tbyte);
int main(void)
{
	int i=0;
	tbyte help[4]={0x89,0x86,0xC7,0x8C};
	tbyte fire[4]={0x8E,0xCF,0xAF,0x86};
	P0=0x00;
	while(1)
	{
		for(i=0;i,4;i++)
			writeseg(help[i]);
		delayms(1000);
		for(i=0;i<4;i++)
			writeseg(fire[i]);
		delayms(1000);
	}
}
void writeseg(tbyte x)
{
	tbyte i;
	for(i=0;i<8;i++)
	{
		if(x &( 0x80 >>i))  //extracting from msb to lsb and sending
			DAT=1;
		else
			DAT=0;
		CLK=0;
		CLK=1;
	}
}
void delayms(tword x)
{
	tword i;
	while(x--)
		for(i=0;i<75;i++);
}