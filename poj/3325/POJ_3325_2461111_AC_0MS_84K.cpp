#include<stdio.h>
#include<stdlib.h>
int cmp(const void *n,const void *m)
{
	return *(int *)n-*(int *)m;
}
int main()
{
	int n,i,j;
	int a[1009];
	double av;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		if(n==1)
		{
			printf("%d\n",a[0]);
			continue;
		}
		if(n==2)
		{
			printf("%d\n",(a[0]+a[1])/2);
			continue;
		}
		qsort(a,n,sizeof(a[0]),cmp);
		for(i=1,av=0.0;i<n-1;i++)
		{
			av+=a[i];
		}
		av/=(n-2);
		printf("%d\n",(int)av);
	}
	return 0;
}