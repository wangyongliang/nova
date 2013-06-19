#include<stdio.h>
#define maxn 1000000+10
int a[maxn];
int q[maxn];
int st,en;
int main()
{
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		scanf("%d",&a[0]);
		q[0]=0;
		en=1;
		st=0;
		for(i=1;i<m;i++)
		{
			scanf("%d",&a[i]);
			while(en>st&&a[i]<a[q[en-1]]) en--;
			q[en++]=i;
		}
		printf("%d",a[q[0]]);
		for(;i<n;i++)
		{
			scanf("%d",&a[i]);
			while(en>st&&a[i]<a[q[en-1]]) en--;
			q[en++]=i;
			while(i-q[st]>=m) st++;
			printf(" %d",a[q[st]]);
		}
		q[0]=0;
		en=1;
		st=0;
		for(i=1;i<m;i++)
		{
			while(en>st&&a[i]>a[q[en-1]]) en--;
			q[en++]=i;
		}
		printf("\n%d",a[q[0]]);
		for(;i<n;i++)
		{
			while(en>st&&a[i]>a[q[en-1]]) en--;
			q[en++]=i;
			while(i-q[st]>=m) st++;
			printf(" %d",a[q[st]]);
		}
		printf("\n");
	}
	return 0;
}