/*
 * GccApplication1.c
 *
 * Created: 2018/7/10 下午 03:30:42
 * Author : lenovo
 */ 
#define F_CPU 10520000
#include <avr/io.h>
#include "ASA_Lib.h"
void keyresoure(char key_in,char *a,char *b);
void counting(char number,char sign,long int *a);
void calculate(long int cal,char number,char sign,long int *a,long int *b);
void printfdata(int cal,int ans,int number,int sing,char *a);
void kb_get(char *a);
int main(void)
{
	ASA_M128_set();
    /* Replace with your application code */
	char n=0,a,b;
	long int m=0,ans=0;
	char p[4]={0,0,0,48};
	ASA_7S00_set(1,200,0xFF,0,0);
	_delay_ms(100);
	
	ASA_7S00_put(1,0,4,p);
	_delay_ms(100);
    while (1) 
    {
		while(n==0){
			kb_get(&n);
		}
		
		if (p[0]==45 && p[1]==45 && p[2]==45 && p[3]==45){
			while(n!=65){
				kb_get(&n);
			}
		}
		keyresoure(n,&a,&b);
		printf("%d\t%d\n",a,b);
		if (a==10 && b==1)
		{
			m=ans=0;
		}
		counting(a,b,&m);
		printf("%d\n",m);
		calculate(m,a,b,&ans,&m);
			
		printfdata(m,ans,a,b,p);
		printf("%d\t",p[0]);
		printf("%d\t",p[1]);
		printf("%d\t",p[2]);
		printf("%d\n",p[3]);
		ASA_7S00_put(1,0,4,p);
		_delay_ms(100);
		while(n!=0){
			kb_get(&n);
			printf("inwhile!!\n");
		}
		
    }
}

void keyresoure(char key_in,char *a,char *b){
	int x=0,y=0;
	switch(key_in){
		case 48:{x=0;y=0;break;}
		case 49:{x=1;y=0;break;}
		case 50:{x=2;y=0;break;}
		case 51:{x=3;y=0;break;}
		case 52:{x=4;y=0;break;}
		case 53:{x=5;y=0;break;}
		case 54:{x=6;y=0;break;}
		case 55:{x=7;y=0;break;}
		case 56:{x=8;y=0;break;}
		case 57:{x=9;y=0;break;}
		case 65:{x=10;y=1;break;}  //A"clr"
		case 66:{x=10;y=2;break;}  //B"="
		case 67:{x=10;y=3;break;}  //C"/"
		case 68:{x=10;y=4;break;}  //D"*"
		case 69:{x=10;y=5;break;}  //E"-"
		case 70:{x=10;y=6;break;}  //F"+"
	}
	*a=x;
	*b=y;
}

void counting(char number,char sign,long int *a){
	static long int counter=0;
	static int s_flag=0;
	
	if (number==10)
	{
		if (sign==1)
		{
			counter=0;
			s_flag=0;
			
		}
		else 
		{
			s_flag=1;
		}
	}
	else{
		if (s_flag==1)
		{
			counter=0;
			s_flag=0;
		}
		counter=(counter*10+number);
		*a=counter;
	}
}

void calculate(long int cal,char number,char sign,long int *a,long int *b){
	static int cal_f2=0,cal_f3=0,cal_f4=0;//f2:運算子f3:等號旗標f4:運算旗標
	static int cal_n1=0;  //暫存器1
	static int cal_n2=0;  //暫存器2
	if (number==10){                
		if (sign==1)
		{
			cal_n1=0;cal_n2=0;cal_f2=0;cal_f3=0;cal_f4=0;
		}
		else if (sign==2)
		{
			cal_f3=1;
			cal_n2=cal;
			switch(cal_f2){   //最後運算
			case 0:{*a=cal_n2;break;}	
				case 6:{*a=cal_n1+cal_n2;cal_n1=*a;break;}
					case 5:{*a=cal_n1-cal_n2;cal_n1=*a;break;}
						case 4:{*a=cal_n2*cal_n1;cal_n1=*a;break;}
							case 3:{
								if (cal_n2==0)
								{
									*a=100000;
								}
								else{*a=cal_n1/cal_n2;cal_n1=*a;}
									break;}
			}
		}
		else 
		{
			if (cal_f3==0 && cal_f4==0){
			switch(cal_f2){
				case 0:{
					cal_n1=cal;
					break;
					}
				case 6:{
					cal_n2=cal;
					*a=cal_n1+cal_n2;
					cal_n1=*a;
					*b=*a;
					break;
					}
				case 5:{
					cal_n2=cal;
					*a=cal_n1-cal_n2;
					cal_n1=*a;
					*b=*a;
					break;
					}
				case 4:{
					cal_n2=cal;
					*a=cal_n1*cal_n2;
					cal_n1=*a;
					*b=*a;
					break;
					}
				case 3:{cal_n2=cal;
					*a=cal_n1/cal_n2;
					cal_n1=*a;
					*b=*a;
					break;
					}
				}
				cal_f2=sign;
				cal_f4=1;
		}
		else {
			if(cal_f4==1){
				cal_f2=sign;
			}
			if (cal_f3==1)
			{
				cal_n1=*a;
				*b=*a;
				cal_f2=sign;
				cal_f3=0;
				cal_f4=1;
			}
		}
	}
}
    if (number!=10)
	{
		cal_f4=0;
		if (cal_f3==1)
		{
			cal_n1=0;cal_n2=0;cal_f2=0;cal_f3=0;cal_f4=0;
		}
	}
  }
  
  
		
void printfdata(int cal,int ans,int number,int sign,char *a){
	int print,x,y,i;
	int prm=0,neg=0;
	*a=*(a+1)=*(a+2)=*(a+3)=0;
		if (sign==2)
		{
			print=ans;
		}
		else if (sign==1)
		{
			print=0;
		}
		else{
			print=cal;
		}
		
		if (print==0)
		{
			*a=*(a+1)=*(a+2)=0;
			*(a+3)=48;
		}
		else
		{
			if (print>0){
				if (print/10){
					if (print/100){
						if (print/1000){
							prm=4;
						}
						else prm=3;
					}
					else prm=2;
				}
				else prm=1;
			}
			if (print<0)
			{
				print=print*(-1);
				neg=1;
				if (print/10)
				{
					if (print/100)
					{
						if (print/1000)
						{
							neg=2;
						}
						else prm=3;
					}
					else prm=2;
				}
				else prm=1;
			}
			x=print;
			y=0;
			for (i=3;i>=4-prm;i--)
			{
				y=x-(x/10)*10;
				x=(x-y)/10;
				*(a+i)=y+48;
				if (neg==1)
				{
					*(a+i-1)=45;
				}
			}
			if (x!=0||neg==2)
			{
				*a=*(a+1)=*(a+2)=*(a+3)=45;
			}
		}
    
}

void kb_get(char *a){
	char num[4][4]={{48,65,66,70},{49,50,51,69},{52,53,54,68},{55,56,57,67}};
	char port[4]={0x70,0xb0,0xd0,0xe0},pin[4]={1,2,4,8};
	int i=0,k=0,flg_1=1,hold=0,print_num=0;
	
	if (*a==0)
	{
	for (i=0;i<4;i++)
	{
		DDRC =0xf0;
		PORTC=port[i];
		for (k=0;k<4;k++)
		{
			DDRC=0xf0;
			flg_1=((PINC&pin[k])>>k);
			if (flg_1==0)
			{
				_delay_ms(50);
				hold=0;
				while (hold==0)
				{
					DDRC=0xf0;
					flg_1=((PINC&pin[k])>>k);
					if (flg_1>0)
					{
						_delay_ms(50);
						print_num=num[i][k];
						//printf("%d\n",print_num);
						*a=print_num;
						hold=1;
					}
				}
			}
		}
	}
}
else {
	*a=0;
}
	}