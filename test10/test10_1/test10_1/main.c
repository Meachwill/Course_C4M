/*
 * test10_1.c
 *
 * Created: 2018/7/30 下午 03:36:07
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

void pin_get(char *a);

int main(void)
{
	
	ASA_M128_set();
	DDRA |= ~(DDRA);
	DDRC &= ~(DDRC);
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(250);
		char a;
		pin_get(&a);
		_delay_ms(50);
		printf("%d\n",a);
		PORTA=a;
		_delay_ms(250);
    }
}

void pin_get(char *a){
	*a=PINC;
}