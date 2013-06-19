#include<stdio.h>
int n;
int a[1100][1100];
int b[1100][1100];
void updata(int x,int y)
{
	int k;
	while(x<n)
	{
		k=y;
		while(k<n)
		{
			a[x][k]++;
			k+=(k&-k);
		}
		x+=(x&-x);
	}
}
int sum(int x,int y)
{
	int k;
	int ans=0;
	while(x>0)
	{
		k=y;
		while(k>0)
		{
			ans+=a[x][k];
			k-=(k&-k);
		}
		x-=x&(-x);
	}
	return ans;
}
int main()
{
	int x;
	int t,ans,x1,y1,x2,y2;
	int flag=0;
	char s[10];
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d%d",&n,&t);
		n++;
		for(x1=0;x1<1010;x1++)
		{
			for(y1=0;y1<1010;y1++) b[x1][y1]=a[x1][y1]=0;
		}
		if(flag) printf("\n");
		else flag=1;
		while(t--)
		{
			scanf("%s",s);
			if(s[0]=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				updata(x1,y1);
				if(x2+1<n) updata(x2+1,y1);
				if(y2+1<n) updata(x1,y2+1);
				if(x2+1<n&&y2+1<n) updata(x2+1,y2+1);
			}
			else
			{
				scanf("%d%d",&x1,&y1);
				ans=sum(x1,y1)+b[x1][y1];
				printf("%d\n",ans&1);
			}
		}
	//	printf("\n");
	}
	return 0;
}
