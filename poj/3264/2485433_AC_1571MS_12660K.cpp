#include<stdio.h>
#define size 50009
int n;
int a[size][32];
int b[size][32];
void init()
{
	int i;
	int j;
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;i+(1<<j)<=n;i++)
		{
			if(a[i][j-1]>a[i+(1<<(j-1))][j-1]) a[i][j]=a[i+(1<<(j-1))][j-1];
			else a[i][j]=a[i][j-1];
			if(b[i][j-1]>b[i+(1<<(j-1))][j-1]) b[i][j]=b[i][j-1];
			else b[i][j]=b[i+(1<<(j-1))][j-1];
		}
	}
}
int q(int x,int y)
{
	int k;
	int min;
	int max;
	k=0;
	while(1<<(k+1)<(y-x+1)) k++;
	min=a[x][k]>a[y-(1<<k)+1][k]?a[y-(1<<k)+1][k]:a[x][k];
	max=b[x][k]>b[y-(1<<k)+1][k]?b[x][k]:b[y-(1<<k)+1][k]; 	
	return max-min;	
}
int main()
{
	int i;
	int m;
	int x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i][0]);
		b[i][0]=a[i][0];
	}
	init();
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",q(x-1,y-1));
	}
	return 0;
}