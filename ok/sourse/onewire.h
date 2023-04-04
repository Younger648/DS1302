#ifndef __ONEWIRE_H_
#define __ONEWIRE_H_

void Delay_OneWire(unsigned int t);
void Write_DS18B20(unsigned char dat);



extern unsigned char Read_DS18B20();


bit init_ds18b20();

#endif



