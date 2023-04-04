#include "head.h"





void delay_138(unsigned int t)
{
	while(t--);
}





void HC138_config(unsigned char n)
{
	switch(n)
	{
		case 4:
			P2 = (P2 & 0x1f) | 0x80;
		break;
		
		case 5:
			P2 = (P2 & 0x1f) | 0xa0;
		break;
				
		case 6:
			P2 = (P2 & 0x1f) | 0xc0;
		break;
						
		case 7:
			P2 = (P2 & 0x1f) | 0xe0;
		break;
								
		case 0:
			P2 = (P2 & 0x1f) | 0x00;
		break;
	}
}


void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
}




void SMG_config(unsigned char adr,unsigned char dat)
{
  P0 = 0XFF;
	HC138_config(6);
	P0 = adr;
	
	
	delay_138(1);
	HC138_config(7);
	P0 = dat;
	
}











