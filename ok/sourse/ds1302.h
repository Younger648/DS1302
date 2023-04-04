#ifndef __DS1302_H_
#define __DS1302_H_

extern unsigned char Write_adr[7];
extern unsigned char Read_adr[7];
extern unsigned char Timer[7];

void Write_ds1302_config();
void Read_ds1302_config();

#endif