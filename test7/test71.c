#include "ASA_Lib.h"
char KB00_num();
void display(char w[4]);
void reset();
char check_region(char y);
void operation(char c);
char detect_num (char s);
void explode(int solution);

//void pow(float a);
//float stf(char e[4]);


int i,out,spc,spc1,spc2,spc3,spc4,spc5,spc6;
int p1,c,f[5],n;
//float solution,p;
int solution,p;
char s,y[4],b,tmp1,tmp2,tmp3,z[4];


int main(void)
{
ASA_M128_set();

y[0]='0';
y[1]='\0';
y[2]='\0';
y[3]='\0';
display(y);
   while(1)
    {   
	    y[0]='0';
	    y[1]='\0';
	    y[2]='\0';
		y[3]='\0';
        c=0;
        for(i=0;c!=2;i++)
        {



        tmp1=KB00_num();
		reset();  
		
		tmp2=detect_num (tmp1);  	    
	    c=check_region(tmp1);
		

	         switch(c)
               {
			   case 1:
			    spc5++;
			   	if(spc5>4)//不可鍵入5位數
	           	{
                  y[0]='-';
	              y[1]='-';
	              y[2]='-';
	              y[3]='-';
	              display(y);
	         	}
	    
			   if(spc6==1)
			   {
			   solution=0;
			   p=0;
			   }	
			   spc4=0;  	
			   y[i]=tmp2;
			   	 if(y[0]=='0')
	              {
		           i--;
		          }	   	                   
		  	   display(y);
	           break;

			   case 2:
			   spc6=0;
			   spc5=0;
			   spc4++;//加減乘除紀錄最後一個
			   spc3=0;//等於連續計算特別
               if(spc4<2)//加減乘除紀錄最後一個
			   {
			   p=atoi(y);
			   }
			   //p=stf(y);
			   
			   if(spc1==0)
               {
			    tmp3=tmp2;
				spc1++;
               }

			   if(tmp3!=tmp2)
			   {
			   operation(tmp3);
			   sprintf(z,"%d",solution);
			   //pow(solution);
			   explode(solution);
               display(z);
			   }
			   else
			   {
			   operation(tmp2);
			   sprintf(z,"%d",solution);
			   printf("%s",z);
			   //pow(solution);
			   explode(solution);
               display(z);
			   }
			   tmp3=tmp2;
			   spc++;	
               z[0]='0';
			   z[1]='\0';
			   z[2]='\0';
			   z[3]='\0';
			   
			   break;

			   case 3: 
			   spc5=0;
			   i=-1;
			   c=0;
			   solution=0; 
			   p=0;   
			   spc=0; //四則運算特別  
			   spc1=0;//連續四則運算特別
			   spc2=0;//乘除運算特別 
			   spc3=0;//等於連續計算特別
			   spc6=0;
			   y[0]='0';
			   y[1]='\0';
			   y[2]='\0';
			   y[3]='\0'; 
			   display(y);	    
               break;	
			   
			   case 4:
			   spc6=1;//條件12
			   spc5=0;
			   spc3++;//等於連續計算特別
			   i=-1;
			   //p=stf(y);
			   if(spc3<2)
			   p=atoi(y);
			   operation(tmp3);
			   sprintf(z,"%d",solution);
			   printf("%s",z);
			   //pow(solution);
			   explode(solution);
               display(z);
			   spc2=1;//乘除運算特別  
			   spc1=0;//連續四則運算特別
			   if(spc3==1)
			   {
			   y[0]='0';
			   y[1]='\0';
			   y[2]='\0';
			   y[3]='\0';
			   }
			   
			   break;
			   	  			  			   
			   }
          
         }     	 
     }  
}

char KB00_num()
{
char s=0;
while(s==0)
          {
           ASA_KB00_get(1,0,1,&s);
          } 
return s;
}



void reset()
{
char s=1;
        while(s!=0)
          {
           ASA_KB00_get(1,0,1,&s);       
          }  
}



char detect_num (char s)
{
 switch (s)
 {
  case 0 : return '0';
  case 1 : return 'F';
  case 2 : return 'E';
  case 3 : return 'D';
  case 4 : return 'C';
  case 5 : return 'B';
  case 6 : return '3';
  case 7 : return '6';
  case 8 : return '9';
  case 9 : return 'A';
  case 10 : return '2';
  case 11 : return '5';
  case 12 : return '8';
  case 13 : return '0';
  case 14 : return '1';
  case 15 : return '4';
  case 16 : return '7';
 }
}
char check_region(char w)
{
switch(w)
   {
    case 1 : return 2;
    case 2 : return 2;
    case 3 : return 2;
    case 4 : return 2;
    case 5 : return 3;
    case 6 : return 1;
    case 7 : return 1;
    case 8 : return 1;
    case 9 : return 4;
    case 10 : return 1;
    case 11 : return 1;
    case 12 : return 1;
    case 13 : return 1;
    case 14 : return 1;
    case 15 : return 1;
    case 16 : return 1; 
   }
}
void operation(char c)
{
   switch(c)
    {
     case 'F'://加法
	 if(spc4>=2)
	 {
	 p=0;
	 }
     solution=solution+p;
	 break;		  
			 
     case 'E'://減法
     if(spc4>=2)
	 {
	 p=0;
	 }
	 if(spc==0)
	 {
	 solution=p;
	 }
	 else
	 {
	 solution=solution-p;
	 }
	 break;		   
			   

	 case 'D'://乘法
     if(spc2==1&&spc3<2)
	 {
	 p=1;
	 spc2=0;
	 }
     if(spc4>=2)
	 {
	 p=1;
	 }
     if(spc==0)
	 {
	 solution=p;
	 }
	 else
	 {
	 solution=solution*p;
	 }
     break;		
	 case 'C'://除法
	 if(spc2==1&&spc3<2)
	 {
	 p=1;
	 spc2=0;
	 }
	 if(spc4>=2)
	 {
	 p=1;
	 }
	 if(spc==0)
	 {
	 solution=p; 
	 }
	 else
	 {
	 solution=solution/p;
	 }
     break;	
	 default:
	 break;		
    }
}
void display(char w[4])
{
     switch(n)
       {
     case 1:
         ASA_7S00_set(1,0,0xFF,0,0x80);
     case 2:
         ASA_7S00_set(1,0,0xFF,0,0x40);
     case 3:
         ASA_7S00_set(1,0,0xFF,0,0x20);
     default:
         break;     
       }
ASA_7S00_put(1,0,4,w);
}


void explode(int solution)
{
if(solution>9999||solution<-9999)
    {
        y[0]='-';
        y[1]='-';
        y[2]='-';
        y[3]='-';
        z[0]='-';
        z[1]='-';
        z[2]='-';
        z[3]='-';
    }
}
