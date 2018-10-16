#include "ASA_Lib.h"

void keyresoure(int key_in,char *a,char *b);

int main(void){
  ASA_M128_set();
}


void keyresoure(int key_in,char *a,char *b){
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
   case 65:{x=10;y=1;break;}  //A
   case 66:{x=10;y=2;break;}  //B
   case 67:{x=10;y=3;break;}  //C
   case 68:{x=10;y=4;break;}  //D
   case 69:{x=10;y=5;break;}  //E
   case 70:{x=10;y=6;break;}  //F
   }
   *a=x;
   *b=y;
}

