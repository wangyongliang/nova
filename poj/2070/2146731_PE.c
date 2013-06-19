#include<stdio.h>
void main()
{
	float i,j,k,flag;
	while(1)
	{
		scanf("%f %f %f",&i,&j,&k);
		if(!i&&!j&&!k)
			break;
		else
		{
			flag=0;
			if(i<=4.5&&j>=150&&k>=200)
			{printf("Wide Receiver ");
			flag=1;
			}
			if(i<=6.0&&j>=300&&k>=500){
				printf("Lineman ");
				flag=1;}
			if(i<=5.0&&j>=200&&k>=300){
				printf("Quarterback ");
				flag=1;}
			if(flag==0)
				printf("No positions \n");
			printf("\n");
		}
	}
}