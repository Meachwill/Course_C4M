#include"ASA_Lib.h"
#include"stdio.h"
int main(void){
ASA_M128_set();
  while(1){
  int i,k,c;
	printf("   ");
	for(i=1;i<=9;i++){
		printf("%4d",i);
	}
	printf("\n");
	for(i=1;i<=40;i++){
		printf("-");
	}
	printf("\n");

	for(i=1;i<=9;i++){
		for(k=1;k<=9;k++){
			if((i*k)%3==0 && (i*k)%5==0){
	   c=1;}
			if(k==1){
				printf("%d |",i);
			}
			if(c==1){
			printf("%4d",i*k);
			c=0;
			}
			else if((i*k)%3==0){
			printf("   *");
			}
			else if((i*k)%5==0){
			printf("   *");
			}
			else
			{printf("%4d",i*k);}
			
		}
		printf("\n");
	}
  }
  system("pause");
}
