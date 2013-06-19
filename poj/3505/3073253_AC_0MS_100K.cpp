#include<stdio.h>
int a[100000][2];
int b[100];
int abs(int n)
{
	if(n>0) return n;
	else  return -n;
}
int min(int n,int m){return n>m?m:n;}
int main()
{
	int n,m,k,i,j,x;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		k=0;
		for(i=0;i<n;i++) b[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				if(x>0)
				{
					a[x][0]=i;
					a[x][1]=j;
					k=k<x?x:k;
				}
			}
		}
		int ans=0;
		for(i=1;i<=k;i++)
		{
			n=abs(a[i][1]-b[a[i][0]]);
			b[a[i][0]]=a[i][1];
			ans+=min(n,m-n)*5+a[i][0]*20;
		}
		printf("%d\n",ans);
	}
	return 0;
}