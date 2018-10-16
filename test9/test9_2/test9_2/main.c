/*
 * test9_2.c
 *
 * Created: 2018/7/28 下午 03:50:03
 * Author : lenovo
 */ 
#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	char a=0,i=0;
    /* Replace with your application code */
    while (1) 
    {
			char ot_mask,ot_shift,ot_data;
			char in_mask,in_shift,in_data;
			char pr_mask,pr_shift;
			char go_mask,go_shift,go_data;
			printf("ot_mask=");scanf("%d",&ot_mask);
			printf("ot_shift=");scanf("%d",&ot_shift);
			printf("ot_data=");scanf("%d",&ot_data);
			M128_DIO_set(200,ot_mask,ot_shift,ot_data);
			printf("in_mask=");scanf("%d",&in_mask);
			printf("in_shift=");scanf("%d",&in_shift);
			printf("in_data=");scanf("%d",&in_data);
			M128_DIO_set(202,ot_mask,ot_shift,ot_data);
			while(i<11){
				printf("pr_mask=");scanf("%d",&pr_mask);
				printf("pr_shift=");scanf("%d",&pr_shift);
				M128_EXT_fgt(0,pr_mask,pr_shift,&a);
				printf("a=%d",a);
				printf("go_mask=");scanf("%d",&go_mask);
				printf("go_shift=");scanf("%d",&go_shift);
				printf("go_data=");scanf("%d",&go_data);
				M128_DIO_fpt(2,go_mask,go_shift,go_data);
				i+=1;
			}
    }
}

