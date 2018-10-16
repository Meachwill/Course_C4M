#include"ASA_Lib.h"
#include"stdlib.h"
int main(void){
  ASA_M128_set();
  while(1){
  int i,sum,x;
  int score=0,level=0;

  for(i=1;i<=10;i++){
  int a=(rand()%10)+1;
  int b=(rand()%10)+1;
  sum=a+b;
  printf("%d + %d=",a,b);
  scanf("%d",&x);
  if(x==sum){
  score+=10;
  printf("correct\n");
  }
  else{
  printf("incorrect\n");
  }
  }
  level=score/10;
  switch(level){
  	case 10:printf("Your level is:A\n");break;
  	case 9:printf("Your level is:A\n");break;
  	case 8:printf("Your level is:B\n");break;
  	case 7:printf("Your level is:C\n");break;
  	case 6:printf("Your level is:D\n");break;
  	default:printf("Your level is:F\n");
  }
  printf("Your score is:%d\n",score);
  }
}
