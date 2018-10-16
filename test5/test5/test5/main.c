/*
 * test5.c
 *
 * Created: 2018/7/23 下午 11:43:12
 * Author : lenovo
 */ 
#define  F_CPU 10520000
#include <avr/io.h>
#include "ASA_Lib.h"

int main(void)
{
	ASA_M128_set();
	int i,k,c,d;
    /* Replace with your application code */
    while (1) 
    {
		int i,k,c;
		printf("   ");
		for(i=1;i<=5;i++){
			printf("%4d",i);
		}
		printf("\n");
		for(i=1;i<=20;i++){
			printf("-");
		}
		printf("\n");

		for(i=1;i<=5;i++){
			for(k=1;k<=5;k++){
				if(k==1){
					printf("%d |",i);
				}
				printf("%4d",i*k);}
		printf("\n");
    }
	scanf("%d",&d);
	if(d==0){
		break;
	}
}
}

