#include<stdio.h>
int main()
{
	int i,sum1,sum2,sum3,j;
	for(i=2992;i<10000;i++)
	{
		j=i;
		sum1=sum2=sum3=0;
		while(j)
		{
			sum1+=j%10;
			j/=10;
		}
		j=i;
		while(j)
		{
			sum2+=j%12;
			j/=12;
		}
		j=i;
		while(j)
		{
			sum3+=j%16;
			j/=16;
		}
		if(sum1==sum2&&sum2==sum3) printf("%d\n",i);
	}
	return 0;
}