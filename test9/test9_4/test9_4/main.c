/*
 * test9_4.c
 *
 * Created: 2018/7/28 下午 04:35:08
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"
#define DC1 0b00000000;
#define DC2 0b01000000;
#define DC3 0b10000000;
#define DC4 0b11000000;


int main(void)
{
	ASA_M128_set();
	char v,a;
	DDRA |= ~(DDRA);
	DDRC &= ~(DDRC);
	//PORTC |=  ~(PORTC);
    /* Replace with your application code */
    while (1)
    {
		printf("mode:");
		scanf("%d",&a);
		if (a<5)
		{
				switch(a){
					case 1:{
						PORTA=DC1;
						printf("PA7=0\tPA6=0:\tOUTPUT:");
						break;
					}
					case 2:{
						PORTA=DC2;
						printf("PA7=0\tPA6=1:\tOUTPUT:");
						break;
					}
					case 3:{
						PORTA=DC3;
						printf("PA7=1\tPA6=0:\tOUTPUT:");
						break;
					}
					case 4:{
						PORTA=DC4;
						printf("PA7=1\tPA6=1:\tOUTPUT:");
						break;
					}
				}
				_delay_ms(50);
				v=PINC;
				printf("%d\n",v);
				v=0;
		}
		else printf("error!!");
    }
}

