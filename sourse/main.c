#include "head.h"



void main()
{
	write_ds1302_config();
	Timer0Init();
    
	while(1)
	{
//		ds18b20_config();
		read_ds1302_config();
	}

}





