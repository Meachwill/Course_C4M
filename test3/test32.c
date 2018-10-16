#include"ASA_Lib.h"
#include"stdlib.h"
#include "math.h"

void transfer(int *a,int *b);

int main(void){


  ASA_M128_set();
  while(1){
    int x,y;
	printf("x=");
	scanf("%d",&x);printf("\n");
	printf("y=");
	scanf("%d",&y);printf("\n");
	transfer(&x,&y);
	printf("--------change----------\n");
	printf("x=%d\ny=%d\n",x,y);
  
  }
  
  }
void transfer(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
