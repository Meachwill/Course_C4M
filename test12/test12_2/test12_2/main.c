/*
 * test12_2.c
 *
 * Created: 2018/8/9 下午 10:53:58
 * Author : lenovo
 */ 

#define F_CPU 11059200
#include <avr/io.h>
#include "ASA_Lib.h"
void timer_EX();
void printftime(char *a);
void set_time(char *x);
void set_clock(char *b);

char encode[10]={48,49,50,51,52,53,54,55,56,57};
char reencode[10]={0,1,2,3,4,5,6,7,8,9};
int erro=0;
int msc=0;
int sec=0;
int sec_d=0;
int min_ftp=0;
int min=0;
int min_d=0;
int clock_ftp=0;
int clock_on=0;
char clock_time[4]={99,99,99,99};
int main(void)
{
	DDRA=0x01;
	ASA_M128_set();
	ASA_KB00_set(2,200,0x01,0,1);
	ASA_7S00_set(1,200,0xFF,0,0);
	_delay_ms(30);
	M128_TIM_set(222,0x07,0,3);
	M128_TIM_set(222,0x48,3,1);
	M128_TIM_set(207,0x80,7,1);

	unsigned char ocr2 = 259;
	M128_TIM_put(10,1,&ocr2);
	M128_TIM_isr(2,timer_EX);
	sei();
    /* Replace with your application code */
	char kb_in=0;
	char p[4]={0,0,0,0},k[4]={0,0,0,0};
    while (1) 
    {
		_delay_ms(10);
		ASA_KB00_get(2,100,1,&kb_in);
		if (kb_in==65)
		{
			set_time(&p);
			if (erro!=1)
			{
				min_d=reencode[p[0]%48];
				min=reencode[p[1]%48];
				sec_d=reencode[p[2]%48];
				sec=reencode[p[3]%48];
				min_ftp=(reencode[p[2]%48]*10)+(reencode[p[3]%48]);
			}
			erro=0;
			
		}
		if (kb_in==67)
		{
			set_clock(&k);
			if (erro!=1){
				clock_time[0]=reencode[k[0]%48];
				clock_time[1]=reencode[k[1]%48];
				clock_time[2]=reencode[k[2]%48];
				clock_time[3]=reencode[k[3]%48];
			}
			erro=0;
			
		}
		if (kb_in==68)
		{
			if (clock_ftp!=1)
			{
				clock_ftp=1;
			}
			else{
				clock_ftp=0;
			}
			
		}
		if (kb_in==70)
		{
			clock_on=0;
		}
		printftime(&p);
		ASA_7S00_put(1,0,4,p);
		_delay_ms(10);
		if (k[0]==p[0])
		{
			if (k[1]==p[1])
			{
				if (k[2]==p[2])
				{
					if (k[3]==k[3])
					{
						clock_on=1;
					}
				}
			}
		}
		if (clock_on==1)
		{
			if (clock_ftp==1)
			{
				printf("bring!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			}
		}
				

    }
}
void timer_EX(){
	msc++;
	if (msc==1000)
	{
		msc=0;
		sec++;
		min_ftp++;
		if (sec%10==0)
		{
			sec=0;
			if (sec_d<5)
			{
				sec_d+=1;
			}
			else sec_d=0;
		}
		if (min_ftp>59)
		{
			min++;
			min_ftp=0;
			if (min>9)
			{
				min_d++;
				min=0;
			}
		}
		
	}
	if (clock_ftp==1 && clock_on==1)
	{
		PORTA=0x01;
	}
}

void printftime(char *a){
	*a=encode[min_d];
	*(a+1)=encode[min];
	*(a+2)=encode[sec_d];
	*(a+3)=encode[sec];
}

void set_time(char *x){
	int i=0,hold=0;
	char enter=1;
	char set_print[4]={48,48,48,48};
	char set_time_ftp=1;
	char number_get=0;
	char kb_set=0;
	ASA_7S00_put(1,0,4,set_print);
	while(set_time_ftp){
		_delay_ms(100);
		ASA_KB00_get(2,100,1,&kb_set);
		if (kb_set==69)
		{
			set_time_ftp=0;
		}
		if (hold==0)
		{
			if (kb_set!=0)
			{
			number_get=kb_set;
			//*(x+i)=number_get;
			set_print[i]=number_get;
			i++;
			hold=1;
			ASA_7S00_put(1,0,4,set_print);
			}
		}
		if (kb_set==0)
		{
			hold=0;
		}
		if (i>3)
		{
			if (set_print[0]>53||set_print[2]>53)
			{
				set_print[0]=45;
				set_print[1]=45;
				set_print[2]=45;
				set_print[3]=45;
				ASA_7S00_put(1,0,4,set_print);
				erro=1;
			}
			while(enter){
				ASA_KB00_get(2,100,1,&kb_set);
				if (kb_set==69)
				{
					set_time_ftp=0;
					enter=0;
				}
				if (kb_set==66)
				{
					if (erro==0)
					{
						*(x+0)=set_print[0];
						*(x+1)=set_print[1];
						*(x+2)=set_print[2];
						*(x+3)=set_print[3];
						set_time_ftp=0;
						enter=0;
					}
					else{
						set_time_ftp=0;
						enter=0;
					}

				}
			}
			
		}
	}
}

void set_clock(char *b){
	int i=0,hold=0;
	char enter=1;
	char set_print[4]={48,48,48,48};
	char set_clock_ftp=1;
	char number_get=0;
	char kb_set=0;
	ASA_7S00_put(1,0,4,set_print);
	while(set_clock_ftp){
		_delay_ms(100);
		ASA_KB00_get(2,100,1,&kb_set);
		if (kb_set==69)
		{
			set_clock_ftp=0;
		}
		if (hold==0)
		{
			if (kb_set!=0)
			{
				number_get=kb_set;
				//*(b+i)=number_get;
				set_print[i]=number_get;
				i++;
				hold=1;
				ASA_7S00_put(1,0,4,set_print);
			}
		}
		if (kb_set==0)
		{
			hold=0;
		}
		if (i>3)
		{
			if (set_print[0]>53||set_print[2]>53)
			{
				set_print[0]=45;
				set_print[1]=45;
				set_print[2]=45;
				set_print[3]=45;
				ASA_7S00_put(1,0,4,set_print);
				erro=1;
			}
			while(enter){
				ASA_KB00_get(2,100,1,&kb_set);
				if (kb_set==69)
				{
					set_clock_ftp=0;
					enter=0;
				}
				if (kb_set==66)
				{
					if (erro==0)
					{
						*(b+0)=set_print[0];
						*(b+1)=set_print[1];
						*(b+2)=set_print[2];
						*(b+3)=set_print[3];
						set_clock_ftp=0;
						enter=0;
					}
					else{
						set_clock_ftp=0;
						enter=0;
					}
					
				}
			}
			
		}
	}
}