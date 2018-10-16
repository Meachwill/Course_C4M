#include"ASA_Lib.h"
#include"stdlib.h"
void transfer(int *a,int *b);
int main(void){
  ASA_M128_set();
  while(1){
   	int score[5][2];
	int i,k;
	for(i=0;i<5;i++){
		printf("ID:");
		scanf("%d",&score[i][0]);printf("\nscore:");
		scanf("%d",&score[i][1]);printf("\n");
	}
	for(i=0;i<6;i++){
		for(k=i+1;k<6;k++){
			if(score[i][1]>=score[k][1]){
				transfer(&score[i][0],&score[k][0]);
			}
		}
	}
	for(i=0;i<5;i++){
		printf("ID:%d\tscore:%d\n",score[i][0],score[i][1]);
	}
  }
  }
  void transfer(int *a,int *b){
    int temp;
	int temp2;
	temp=*a;
	*a=*b;
	*b=temp;
	temp2=*(a+1);
	*(a+1)=*(b+1);
	*(b+1)=temp2;
}
