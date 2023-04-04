#include "head.h"





//
static void I2C_Delay(unsigned char n)
{
    do
    {
        _nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();		
    }
    while(n--);      	
}

//
void I2CStart(void)
{
    SDA = 1;
    SCL = 1;
	I2C_Delay(DELAY_TIME);
    SDA = 0;
	I2C_Delay(DELAY_TIME);
    SCL = 0;    
}

//
void I2CStop(void)
{
    SDA = 0;
    SCL = 1;
	I2C_Delay(DELAY_TIME);
    SDA = 1;
	I2C_Delay(DELAY_TIME);
}

//
void I2CSendByte(unsigned char byt)
{
    unsigned char i;
	
    for(i=0; i<8; i++){
        SCL = 0;
		I2C_Delay(DELAY_TIME);
        if(byt & 0x80){
            SDA = 1;
        }
        else{
            SDA = 0;
        }
		I2C_Delay(DELAY_TIME);
        SCL = 1;
        byt <<= 1;
		I2C_Delay(DELAY_TIME);
    }
	
    SCL = 0;  
}

//
unsigned char I2CReceiveByte(void)
{
	unsigned char da;
	unsigned char i;
	for(i=0;i<8;i++){   
		SCL = 1;
		I2C_Delay(DELAY_TIME);
		da <<= 1;
		if(SDA) 
			da |= 0x01;
		SCL = 0;
		I2C_Delay(DELAY_TIME);
	}
	return da;    
}

//
unsigned char I2CWaitAck(void)
{
	unsigned char ackbit;
	
    SCL = 1;
	I2C_Delay(DELAY_TIME);
    ackbit = SDA; 
    SCL = 0;
	I2C_Delay(DELAY_TIME);
	
	return ackbit;
}

//
void I2CSendAck(unsigned char ackbit)
{
    SCL = 0;
    SDA = ackbit; 
	I2C_Delay(DELAY_TIME);
    SCL = 1;
	I2C_Delay(DELAY_TIME);
    SCL = 0; 
		SDA = 1;
	I2C_Delay(DELAY_TIME);
}

