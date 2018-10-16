/*
 * TEST9_ans.c
 *
 * Created: 2018/7/29 下午 02:09:06
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	DDRA |= ~(DDRA);
    /* Replace with your application code */
	char run[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	char clr[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};	
	int k=0,p=7;
    while (1) 
    {
		for (int i=8;i>0;i--)
		{	
			for (int k=0;k<i;k++)
		{
			PORTA=run[k];
			_delay_ms(100);
			if ((k+1)<=p)
			{
				run[k]=run[k]|run[p];
			}
			printf("%d\n",run[7]);
			
		}
		p-=1;
			_delay_ms(100);
		}
		for (int j=0;j<8;j++)
		{
			run[j]=clr[j];
		}
		p=7;
		PORTA =0x00;
		_delay_ms(100);

    }
}

