#include"ASA_Lib.h"
#include"stdio.h"
int main(void){
ASA_M128_set();
  while(1){
  	int i=1,k=1,a,b;
	printf("   ");
	while(i<10){
		printf("%4d",i);
		i++;
	}
	i=0;
	printf("\n");
	while(i<41){
		printf("-");
		i++;
	}
	i=1;
	printf("\n");
	while(i<10){
		while(k<10){
			if(k==1){
				printf("%d |",i);
			}
			printf("%4d",i*k);
		    k++;	
		}
		printf("\n");
		k=1;
		i++;
	}
  }
}
