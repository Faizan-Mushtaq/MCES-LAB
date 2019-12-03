#include<reg52.h>
typedef unsigned char tbyte;
typedef unsigned int tword;
sbit SEL=P1^4;
void delayms(tword);
tbyte readinput(void);
tbyte countOnes(tbyte);

int main(void)
{
	tbyte temp,count;
	while(1)
	{
		temp=readinput();
		count=countOnes(temp);
		if(count%2 ==0)
			P0=0xFF;
		else
			P0=0x00;
		delayms(1000);
		P0=count;
		delayms(1000);
	}
}
tbyte countOnes(tbyte x)
{
	tbyte i,count=0;
	for(i=0;i<8;i++)
	{
		if(x & (0x01<<i))
			count++;
	}
	return count;
}
tbyte readinput(void)
{
	tbyte temp=0;
	SEL=0;        //lower nibble
	temp=P1& 0x0F; 
	SEL =1;       //upper nibble
	temp=(P1 &0x0F)<<4 |temp;
	return temp;
}
void delayms(tword x)
{
	tword i;
	while(x--)
		for(i=0;i<120;i++);
}