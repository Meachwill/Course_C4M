#include"ASA_Lib.h"
#include"stdlib.h"
#include "math.h"

void seq(int a);

int main(void){


  ASA_M128_set();
  while(1){
    int x;
	printf("x=");
	scanf("%d",&x);printf("\n");
	printf("--------change----------\n");
	seq(x);
	

  
  }
  
  }
void seq(int a){
	static int temp1=0,temp2=1,temp3=0;
	for(int i=1;i<=a;i++){
	printf("%d",temp3);
	if(temp3>0){
	temp3=temp3%10;
	}
	temp3=temp1+temp2;
	temp1=temp2;
	temp2=temp3;
}
}
