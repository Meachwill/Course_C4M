/*
 * test9.c
 *
 * Created: 2018/7/24 下午 01:19:24
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"


int main(void){
	ASA_M128_set();
	M128_DIO_set(202,0xff,0,0xff);
	M128_DIO_set(200,0xFF,0,0xff);
	while(1){
		char a=0,b=0;
		M128_DIO_get(100,1,&a);
		_delay_ms(100);
		printf("%d\n",a);
		printf("digital:\n");
		scanf("%d",&b);
		M128_DIO_put(2,1,&b);
		
	}
}

