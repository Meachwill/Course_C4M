/*
 * test12.c
 *
 * Created: 2018/8/9 下午 02:32:50
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

int sec=0;
int msc=0;
int ftp=0;
int last_sec=0;
void timer2_fun();
int main(void)
{
	
	ASA_M128_set();
	printf("start-------------------\n");
	M128_TIM_set(222,0x07,0,3);
	M128_TIM_set(222,0x48,3,1);
	M128_TIM_set(207,0x80,7,1);
	unsigned char ocr2 = 179;
	M128_TIM_put(10,1,&ocr2);
	
	M128_TIM_isr(2,timer2_fun);
	sei();
	
	printf("start!!while!!----------\n");
	
    while (1) 
    {
		//printf("%d\n",sec);
		_delay_ms(5);
		if (ftp==1)
		{
			printf("time");
			printf("now sec=%d\n",sec);
			last_sec=sec;
			ftp=0;
		}
    }
}
void timer2_fun(){
	msc++;
	if (msc==1000)
	{
		msc=0;
		sec++;
		ftp+=1;
	}
}
