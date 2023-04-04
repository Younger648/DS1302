#ifndef __DS1302_H_
#define __DS1302_H_


extern unsigned char write_adr [7];
extern unsigned char read_adr [7];
extern unsigned char Timer [7];

void write_ds1302_config();
void read_ds1302_config();

#endif

