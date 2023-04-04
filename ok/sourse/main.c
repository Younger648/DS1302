#include "head.h"



void main()
{
	Write_ds1302_config();
	Timer0Init();
    
	while(1)
	{
		Read_ds1302_config();
//		ds18b20_config();
	}

}





