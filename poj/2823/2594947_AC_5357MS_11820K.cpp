#include<stdio.h>
#define maxn 1000009
int a[maxn][2];
int b[maxn];
int n,m,flag;
void f()
{
	int i,j;
	flag=0;
	for(i=0;i<n;i++) a[i][flag]=b[i];
	flag=1;
	for(j=1;(1<<j)-1<m;j++)
	{
		for(i=0;i+(1<<j)-1<n;i++)
		{
			if(a[i][1-flag]>a[i+(1<<(j-1))][1-flag]) a[i][flag]=a[i][1-flag];
			else a[i][flag]=a[i+(1<<(j-1))][1-flag];
		}
		flag=1-flag;
	}
}
void ff()
{
	int i,j;
	flag=0;
	for(i=0;i<n;i++) a[i][flag]=b[i];
	flag=1;
	for(j=1;(1<<j)-1<m;j++)
	{
		for(i=0;i+(1<<j)-1<n;i++)
		{
			if(a[i][1-flag]<a[i+(1<<(j-1))][1-flag]) a[i][flag]=a[i][1-flag];
			else a[i][flag]=a[i+(1<<(j-1))][1-flag];
		}
		flag=1-flag;
	}
}

int g(int i,int j)
{
	int k=0;
	while((1<<k)<=j-i+1) k++;
	k--;
	if(a[i][flag]>a[j+1-(1<<k)][flag]) return a[i][flag];
	else return a[j+1-(1<<k)][flag];
}
int gg(int i,int j)
{
	int k=0;
	while((1<<k)<=j-i+1) k++;
	k--;
	if(a[i][flag]<a[j+1-(1<<k)][flag]) return a[i][flag];
	else return a[j+1-(1<<k)][flag];
}


int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		ff();
		flag=1-flag;
		printf("%d",gg(0,m-1));
		for(i=1;i+m<=n;i++)
			printf(" %d",gg(i,i+m-1));
		printf("\n");
		f();
		flag=1-flag;
		printf("%d",g(0,m-1));
		for(i=1;i+m<=n;i++)
			printf(" %d",g(i,i+m-1));
		printf("\n");

	}
	return 0;
}