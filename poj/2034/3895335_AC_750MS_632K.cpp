#include<stdio.h>
int flag[100000]={0};
void init()
{
	int i,j;
	for(i=2;i<100000;i++)
	{
		if(flag[i]==0)
		{
			for(j=i*2;j<100000;j+=i) flag[j]=1;
		}
	}
	flag[1]=1;
}
int a[10000],use[10000];
int d;
int find(int deep,int n,int m)
{
	int i,sum,j;
	int ok;
	if(deep==m-n+1) return 1;
	else
	{
		for(i=n;i<=m;i++)
		{
			if(use[i])
			{
				ok=1;
				sum=i;
				for(j=deep-1;j>=0&&j>deep-d;j--)
				{
					sum+=a[j];
					if(flag[sum]==0) 
					{
						ok=0;
						break;
					}
				}
				if(ok)
				{
					use[i]=0;
					a[deep]=i;
					if(find(deep+1,n,m)) return 1;
					use[i]=1;
				}
			}
		}
		return 0;
	}
}
int main()
{
	int n,m,i;
	init();
	while(scanf("%d%d%d",&n,&m,&d)&&(n+m+d))
	{
		for(i=n;i<=m;i++) use[i]=1;
		if(find(0,n,m))
		{
			for(i=0;i<m-n+1;i++) 
			{
				if(i) printf(",");
				printf("%d",a[i]);
			}
			printf("\n");
		}
		else printf("No anti-prime sequence exists.\n");
	}
	return 0;
}