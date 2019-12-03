#include<reg52.h>
typedef unsigned char tbyte;
typedef unsigned int tword;

sbit W3=P0^7;
sbit W2=P0^6;
sbit W1=P0^5;
sbit W0=P0^4;

nostepsclk=100; //steps=totaldeg/1.8
nostepsanticlk=100;
void delayms(tword);
main()
{
	while(1)
	{
		W3=1;W2=0;W1=0;W0=0;delayms(5);if(--nostepsclk==0)break;
		W3=0;W2=1;W1=0;W0=0;delayms(5);if(--nostepsclk==0)break;
		W3=0;W2=0;W1=1;W0=0;delayms(5);if(--nostepsclk==0)break;
		W3=0;W2=0;W1=0;W0=1;delayms(5);if(--nostepsclk==0)break;
	}
	while(1)
	{
		W3=0;W2=0;W1=0;W0=1;delayms(5);if(--nostepsanticlk==0)break;
		W3=0;W2=0;W1=1;W0=0;delayms(5);if(--nostepsanticlk==0)break;
		W3=0;W2=1;W1=0;W0=0;delayms(5);if(--nostepsanticlk==0)break;
		W3=1;W2=0;W1=0;W0=0;delayms(5);if(--nostepsanticlk==0)break;
	}
	while(1);
}
void delayms(tword x)
{
	tword i;
	while(x--)
		for(i=0;i<300;i++);
}