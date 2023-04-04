#ifndef __DS1302GG_H_
#define __DS1302GG_H_

void Write_Ds1302(unsigned  char temp);
void Write_Ds1302_Byte( unsigned char address,unsigned char dat );
extern unsigned char Read_Ds1302_Byte ( unsigned char address );

#endif

