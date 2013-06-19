#include<stdio.h>
#include<math.h>
int l,n;
int temp[2010];
int ans[2010];
void g(int s,int x)
{
	int i,j,k;
	int st,en;
	st=x-(s-1);
	en=x+(s-1);
	if(l>en) return ;
	else if(l+n<st) return ;
	if(s==1)
	{
		if(x>=l&&x<l+n) temp[x-l]=1;
	}
	else
	{
		st=st<l?l:st;
		en=en>l+n-1?l+n-1:en;
		k=1;
		while(k<=s) k*=2;
		k/=2;
		if(k==s)
		{
			for(i=st;i<=en;i++)
			{
				if(abs(i-x)%2==0) temp[i-l]=0;
				else temp[i-l]=1;
			}
		}
		else
		{
			k=s-k;
			if(st<=(x-s+2*k-1)) g(k,x-s+k);
			if(en>=x+s-2*k+1) g(k,x+s-k);
			st=st<x-s+2*k?x-s+2*k:st;

			en=en>x+s-2*k?x+s-2*k:en;
			for(i=st;i<=en;i++)
			{
				if((i-l)>=l&&(i-l)<l+n) temp[i-l]=0;
			}
		}
	}
}
int main()
{
	int i,j;
	int k;
	int b[2010];
	int s,f;
	while(scanf("%d",&k)!=EOF)
	{
		for(i=0;i<k;i++)
		{
			scanf("%d",&b[i]);
		}
		scanf("%d%d%d",&s,&l,&n);
		for(i=l;i<=l+n;i++)
		{
			temp[i-l]=0;
			ans[i-l]=0;
		}
		for(i=0;i<k;i++)
		{
			g(s,b[i]);
			for(j=l;j<l+n;j++)
			{
				ans[j-l]=ans[j-l]^temp[j-l];
				temp[j-l]=0;
			}
		}
		for(i=l;i<l+n;i++)
		{
			printf("%d ",ans[i-l]);
		}
		printf("\n");
	}
	return 0;
}