#include<reg52.h>
typedef unsigned char tbyte;
typedef unsigned int tword;
void delayms(tword);
sbit row0=P0^0;
sbit row1=P0^1;
sbit row2=P0^2;
sbit row3=P0^3;

sbit col0=P1^3;
sbit col1=P1^2;
sbit col2=P1^1;
sbit col3=P1^0;

tbyte code keys[4][4]={{'0','1','2','3'},
					  {'4','5','6','7'},
					  {'8','9','A','B'},
					  {'C','D','E','F'}};

main()
{
	tbyte rowpos,colpos;
	row0=row1=row2=row3=0; //outputs
	col0=col1=col2=col3=1; //inputs
	SCON=0X50;
	TMOD=0X20;
	TH1=-3;
	TR1=1;
	TI=1;
	while(1)
	{
		while(1)
		{
			row0=0;row1=1;row2=1;row3=1;rowpos=0;
			if(col0==0){colpos=0;break;}
			if(col1==0){colpos=1;break;}
			if(col2==0){colpos=2;break;}
			if(col3==0){colpos=3;break;}

			row0=1;row1=0;row2=1;row3=1;rowpos=1;
			if(col0==0){colpos=0;break;}
			if(col1==0){colpos=1;break;}
			if(col2==0){colpos=2;break;}
			if(col3==0){colpos=3;break;}

			row0=1;row1=0;row2=0;row3=1;rowpos=2;
			if(col0==0){colpos=0;break;}
			if(col1==0){colpos=1;break;}
			if(col2==0){colpos=2;break;}
			if(col3==0){colpos=3;break;}

			row0=1;row1=1;row2=1;row3=0;rowpos=3;
			if(col0==0){colpos=0;break;}
			if(col1==0){colpos=1;break;}
			if(col2==0){colpos=2;break;}
			if(col3==0){colpos=3;break;}
		}
		delayms(20); //debounce
		P0=keys[rowpos][colpos]; //output on LEDs
		delayms(1000);

		SBUF=keys[rowpos][colpos]; // serially to terminal
		while(col0==0 || col1==0 || col2==0 || col3==0);
		delayms(20);
	}
}

void delayms(tword x)
{
	tword i;
	while(x--)
		for(i=0;i<300;i++);
}
