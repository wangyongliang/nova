#include<stdio.h>
void main()
{
	int a[1000],n,i,k;
	float j;
	float sum;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		scanf("%f",&j);
		for(i=0;i<j;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sum/=j;
		k=0;
		for(i=0;i<j;i++)
		{
			if(a[i]>sum)k++;
		}
		sum=k*100/j;
		printf("%.3f%c\n",sum,'%');
	}

}