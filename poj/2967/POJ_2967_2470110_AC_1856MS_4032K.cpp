#include <stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

unsigned int a[1000010];
int main()
{int i;
	int n,flag1,flag2;
	unsigned int min1,min2,max;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d",&a[0],&a[1]);
		min1=a[0];
		min2=a[1];
		if(min1>min2) swap(min1,min2);
		max=min2;
		for(i=2;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>max) max=a[i];
			if(a[i]<min2)
			{
				min2=a[i];
				if(min1>min2) swap(min1,min2);
			}
		}
   // qsort(a,n,sizeof(unsigned int),comp); 
    flag1=0,flag2=0;
		if(min1+min2<=max)
		{
			flag1=1;
		}
		if(flag1&&n>140)
		{
			printf("The set is accepted.\n");
			continue;
		}
		sort(a,a+n);
	for(i=2;i<n;i++)
		{
			if(a[i-1]+a[i-2]>a[i])
			{
				flag2=1;
				break;
			}
		}
		if(flag1==1&&flag2==1)
		{
			printf("The set is accepted.\n");
		}
		else
		{
			printf("The set is rejected.\n");
		}
	}
}