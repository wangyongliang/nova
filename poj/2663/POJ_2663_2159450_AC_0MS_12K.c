#include<stdio.h>
void main()
{
int n;
while(scanf("%d",&n)&&n!=-1)
{
if(n==0)printf("1\n");
else if(n==2)printf("3\n");
else if(n==4)printf("11\n");
else if(n==6)printf("41\n");
else if(n==8)printf("153\n");
else if(n==10)printf("571\n");
else if(n==12)printf("2131\n");
else if(n==14)printf("7953\n");
else if(n==16)printf("29681\n");
else if(n==18)printf("110771\n");
else if(n==20)printf("413403\n");
else if(n==22)printf("1542841\n");
else if(n==24)printf("5757961\n");
else if(n==26)printf("21489003\n");
else if(n==28)printf("80198051\n");
else if(n==30)printf("299303201\n");
else printf("0\n");
}
}