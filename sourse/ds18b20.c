#include "head.h"

unsigned int temp;



void ds18b20_config()
{
	unsigned char LSB,HSB;
	
	EA = 0;
	init_ds18b20();
	EA = 1;
	
	
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);
	
	
	
	Delay_OneWire(10000);
	
	
	
	init_ds18b20();
	

	
	
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);
	
	
	
	LSB = Read_DS18B20();
	HSB = Read_DS18B20();
	EA = 1;
	
	temp = HSB;
	temp = (temp << 8) | LSB;
	
	
	if((temp & 0x800) == 0x0000)
	{
		temp >>= 4;
		temp = temp*10;
		temp = temp +(LSB & 0x0f)*0.625;
	}

}







































