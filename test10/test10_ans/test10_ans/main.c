#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

#define bit_set(p,m) (p |=(1<<m))
#define bit_clear(p,m) (p &=~(1<<m))
#define bit_writ(c,p,m) (c ? bit_set(p,m):bit_clear(p,m))


void kb_get();
int main(void)
{
	ASA_M128_set();
	printf("start");
	/* Replace with your application code */
	while (1)
	{
		kb_get();
	}
}

void kb_get(){
	char num[4][4]={{13,9,5,1},{14,10,6,2},{15,11,7,3},{16,12,8,4}};
	char port[4]={0x70,0xb0,0xd0,0xe0},pin[4]={1,2,4,8};
	int i=0,k=0,flg_1=1,hold=0,print_num=0;
	for (i=0;i<4;i++)
	{
		DDRC =0xf0;
		DDRA =0x00;
		PORTC=port[i];
		for (k=0;k<4;k++)
		{
			DDRC=0xf0;
			flg_1=((PINA&pin[k])>>k);
			if (flg_1==0)
			{
				_delay_ms(50);
				hold=0;
				while (hold==0)
				{
					DDRC=0xf0;
					flg_1=((PINA&pin[k])>>k);
					if (flg_1>0)
					{
						_delay_ms(50);
						print_num=num[i][k];
						printf("%d\n",print_num);
						hold=1;
					}
				}
			}
		}
	}
}