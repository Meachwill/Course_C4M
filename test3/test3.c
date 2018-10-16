#include"ASA_Lib.h"
#include"stdlib.h"
#include "math.h"

float cal(float a,int b);

int main(void){


  ASA_M128_set();
  while(1){
    float x=8.0,y;
	int n=5;
	y=cal(x,n);
	printf("x=%f\nn=%d\n",x,n);
	printf("Ans=%f\n",y);
  
  }
  
  }
 float cal(float a,int b){
	int y;
	y=pow(a,b);
	return(y);
}
