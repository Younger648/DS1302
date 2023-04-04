#ifndef __SMG_H_
#define __SMG_H_

extern unsigned char code SMG_Table[18];
extern unsigned char code SMG_adr[8];
extern unsigned int temperature;

void ds18b20_show();
void ds1302_show();


#endif
