#include"ASA_Lib.h"
#include"stdlib.h"
int a=1,b=2,c=3,d=4;

int iteration(int u);
int main(void){
  ASA_M128_set();
  while(1){
    int i,u,y,k;
	printf("-----------part1------------\n");
	printf("a=%d\tb=%d\tc=%d\td=%d\n",a,b,c,d);
	printf("u=");
	scanf("%d",&u);
	printf("\n");
	
	for(i=1;i<=10;i++){
		y=iteration(u);
		printf("y=%d\n",y);
	}
	printf("-----------part2------------\n");
	printf("a=");scanf("%d",&a);
	printf("b=");scanf("%d",&b);
	printf("c=");scanf("%d",&c);
	printf("d=");scanf("%d",&d);
	printf("u=");scanf("%d",&u);
	for(i=1;i<=10;i++){
		y=iteration(u);
		printf("y=%d\n",y);
	}
	scanf("%d",k);
	if(k==0) break;
  }
  }
  int iteration(int u){
	static int x=0;
	int y;
	x=a*x+b*u;
	y=c*x+d*u;
	return(y);
}
