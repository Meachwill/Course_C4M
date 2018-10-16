/*
 * test11_ans.c
 *
 * Created: 2018/8/14 下午 01:39:32
 * Author : lenovo
 */ 

#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	DDRA =0xff;
	DDRC =0x0f;
	char encode[12]={0x01,0x01,0x01,0x01,0x20,0x10,0x08,0x08,0x08,0x08,0X04,0X02};
	char choose[12]={0x0E,0x0D,0x0B,0x07,0x07,0x07,0x07,0x0B,0x0D,0x0E,0x0E,0x0E};
	/* Replace with your application code */
	while (1)
	{
		for (int i=0;i<12;i++)
		{
			PORTC=choose[i];
			_delay_ms(100);
			PORTA=encode[i];
			_delay_ms(100);
		}
	}
}
