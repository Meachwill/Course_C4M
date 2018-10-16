/*
 * GccApplication1.c
 *
 * Created: 2018/7/10 下午 03:30:42
 * Author : lenovo
 */ 
#define F_CPU 10520000
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	DDRA =0xff;
    /* Replace with your application code */
    while (1) 
    {
		char encode[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x03,0x78,0x00,0x18};
			for (int i=0;i<10;i++)
			{
				PORTA=encode[i];
				_delay_ms(500);
			}
		
		}
}