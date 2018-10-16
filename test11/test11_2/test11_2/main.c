/*
 * test11_2.c
 *
 * Created: 2018/8/2 下午 03:09:20
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
	char encode[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x03,0x78,0x00,0x18};
	char choose[4]={0x0E,0x0D,0x0B,0x07};
    /* Replace with your application code */
    while (1) 
    {
		
		//PORTC=choose[0];
		//_delay_ms(2);
		
		for (int i=0;i<4;i++)
		{
			PORTC=choose[i];
			PORTA=~encode[i];
			_delay_ms(5);
			/*for (int k=0;k<3;k++)
			{
				PORTA=~encode[k];
				_delay_ms(1);
			}*/
			//PORTA=~encode[0];

		}
    }
}

