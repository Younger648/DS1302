#include "head.h"


void Timer0Init()		//1毫秒@11.0592MHz
{
	
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	
	TL0 = (65535 - 10000) % 256;		//设置定时初始值
	TH0 = (65535 - 10000) / 256;		//设置定时初始值
	
	TF0 = 0;		//清除TF0标志
	
	
	EA = 1;
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
}



void ServiceTimer0() interrupt 1
{
	TL0 = (65535 - 100) % 256;		//设置定时初始值
	TH0 = (65535 - 100) / 256;		//设置定时初始值
	
	ds1302_show();
//	ds18b20_show();
	
	
}


//void Timer0Init()		//1毫秒@11.0592MHz
//{
//	
//	TMOD &= 0xF0;		//设置定时器模式
//	TMOD |= 0x01;		//设置定时器模式
//	
//	TL0 = 0x18;		//设置定时初始值
//	TH0 = 0xfc;		//设置定时初始值
//	
//	TF0 = 0;
//	TR0 = 1;
//	ET0 = 1;
//}


//void ServiceTimer0() interrupt 1
//{
//	TL0 = 0X18;		//设置定时初始值
//	TH0 = 0XFC;		//设置定时初始值
//	
//	SMG_show();
//	
//	
//}


