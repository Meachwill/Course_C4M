#include"ASA_Lib.h"
#include"stdlib.h"
void transfer(int *a,int *b);
int main(void){
  ASA_M128_set();
  while(1){
    int score[5];
	int i,k;
	for(i=0;i<6;i++){
	printf("%d:",i);
		scanf("%d",&score[i]);printf("\n");
	}
	for(i=0;i<6;i++){
		for(k=i+1;k<6;k++){
			if(score[i]<=score[k]){
				transfer(&score[i],&score[k]);
			}
		}
	}
	printf("-----------transfer--------------\n");
	for(i=0;i<6;i++){
		printf("%d\n",score[i]);
	}
  
  }
  }
  void transfer(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
