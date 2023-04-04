#include "head.h"

unsigned char Write_adr[7] = {0x80,0x82,0x84,0x86,0x88,0x8a,0x8c};
unsigned char Read_adr[7] = {0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};

unsigned char Timer[7] = {0x29,0x29,0x10,0x01,0x01,0x01,0x21};


void Write_ds1302_config()
{
	unsigned char i;
	
	Write_Ds1302_Byte(0x8e,0x00);
	
	for(i=0;i<7;i++)
	{
		Write_Ds1302_Byte(Write_adr[i],Timer[i]); 
	}
		Write_Ds1302_Byte(0x8e,0x80);
	
	
	
}



void Read_ds1302_config()
{
	unsigned char i;
	

	
	for(i=0;i<7;i++)
	{
		Timer[i] = Read_Ds1302_Byte (Read_adr[i]);
	}


	
}