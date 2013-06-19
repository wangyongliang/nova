//pku 3181
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *n,const void *m)
{
	return *(int *)n-*(int *)m;
}
#include<string.h>
int a[1001];
int main()
{
	int i,j,k,n,t=0;
	double sum;
	char s[100];
	while(scanf("%d%d",&n,&k)&&(n+k))
	{
		t++;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			a[i]=strlen(s);
		}
		qsort(a,i,sizeof(a[0]),cmp);
		for(i=0;i<n;)
		{
			sum=0;
			for(j=i;j<i+k;j++)
			{
				sum+=a[j];
			}
			sum/=k;
			for(j=i;j<i+k;j++)
			{
				if(sum-a[j]>2) goto line;
			}
			i=j;
		}
line:;
		if(i==n) printf("Case %d: yes\n",t);
		else printf("Case %d: no\n",t);
		printf("\n");
	}
	return 0;
}