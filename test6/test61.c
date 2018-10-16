#include "ASA_Lib.h"

int main(void){
   ASA_M128_set();
   ASA_KB00_set(2,200,0x01,0,1);
   ASA_7S00_set(1,200,0xFF,0,0);
   char value=0;
   char data[4]={0,0,0,0};
   int i;

   while(1){
     ASA_KB00_get(2,100,1,&value);

	 if(value!=0){
	     printf("%d\n",value);
		 for(i=4;i>2;i++){
		   data[i]=data[i+1];
		   }
		   data[3]=value;
	     }
		 	 ASA_7S00_put(1,0,4,&data);
	 _delay_ms(200);
     }



}
