/*
 * test9_3.c
 *
 * Created: 2018/7/26 下午 02:54:32
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	char v,b;
	DDRA |= ~(DDRA);
	DDRC |= ~(DDRC);
    /* Replace with your application code */
    while (1) 
    {
		scanf("%d",&b);
		v=PINA &b;
		PORTC=v;
	}
}

