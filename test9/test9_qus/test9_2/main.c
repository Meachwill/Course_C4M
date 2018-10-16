/*
 * test9_2.c
 *
 * Created: 2018/7/26 下午 01:43:08
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	_delay_ms(10);
	DDRC |= ~DDRC;
	DDRA &= ~DDRA;
    /* Replace with your application code */
    while (1) 
    {
		int a,b;
		//scanf("%d",&a);
		if (PINA & (1<<PA0))
		{
			printf("pina0=1");
			
		}
		if (PINA & (1<<PA1))
		{
			printf("pina1=1");
		}
		
		if (PINA & (1<<PA2))
		{
			printf("pina2=1");
		}
		/*if (PINA & (1<<PA1))
		{
			printf("a");
			//PORTC &= ~PORTC;
			//PORTC |= (1<<a);
		}*/

		//b = PINA;
		//_delay_ms(10);
	//	printf("%d",b);
    }
}

