#include<stdio.h>
#define maxn 200000
int flag[maxn],a[maxn],index[maxn];
int find(int x)
{
	if(x==flag[x]) return x;
	else 
	{
		flag[x]=find(flag[x]);
		return flag[x];
	}
}
int n;
int sum(int x)
{
	int cnt=0;
	while(x>0)
	{
		cnt+=index[x];
		x-=(x&(-x));
	}
	return cnt;
}

void   g(int x,int flg)
{
	while(x<=n)
	{
		index[x]+=flg;
		x+=(x&(-x));
	}
}

int kth(int k)
{
	int min,max,mid;
	min=0;
	max=n;
	while(min<max)
	{
		mid=(min+max)/2;
		int tp=sum(mid);
		if(tp<k) min=mid+1;
		else max=mid;
	}
	return min;
}
int gcnt;
int main()
{
	int m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) 
		{
			index[i]=0;
			flag[i]=i;
			a[i]=1;
		}
		g(1,n);
		gcnt=n;
		while(m--)
		{
			scanf("%d",&j);
			if(j==0)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				int xx=find(x);
				int yy=find(y);
				if(xx!=yy)
				{
					g(a[xx],-1);
					g(a[yy],-1);
					flag[yy]=xx;
					a[xx]+=a[yy];
					g(a[xx],1);
					gcnt--;
				}
			}
			else
			{
				int k;
				scanf("%d",&k);
				printf("%d\n",kth(gcnt-k+1));
			}
		}
	}
	return 0;
}