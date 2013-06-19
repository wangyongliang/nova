#include<iostream>
#include<algorithm>
using namespace std;
int bit[32];
struct node
{
	int min,max;
	int color;
	int flag;
}a[100000*3+100];

void build(int min,int max,int father)
{
	a[father].min=min;
	a[father].max=max;
	int mid=(min+max)/2;
	a[father].color=bit[1];
	a[father].flag=0;
	if(min<max)
	{
		build(min,mid,father*2);
		build(mid+1,max,father*2+1);
	}
}

void insert(int min,int max,int father,int color)
{
	if(min<=a[father].min&&max>=a[father].max)
	{
		a[father].color=bit[color];
		a[father].flag=color;
	}
	else
	{
		int mid=(a[father].min+a[father].max)/2;
		if(a[father].flag)
		{
			insert(a[father].min,a[father].max,father*2,a[father].flag);
			insert(a[father].min,a[father].max,father*2+1,a[father].flag);
			a[father].flag=0;
		}
		if(min<=mid) insert(min,max,father*2,color);
		if(max>mid) insert(min,max,father*2+1,color);
		a[father].color=a[father*2].color|a[father*2+1].color;
	}
}

int find(int min,int max,int father)
{
	int ans=0;
	int mid=(a[father].min+a[father].max)/2;
	if(min<=a[father].min&&max>=a[father].max)
	{
		return a[father].color;
	}
	else
	{
		if(a[father].flag)
		{
			insert(a[father].min,a[father].max,father*2,a[father].flag);
			insert(a[father].min,a[father].max,father*2+1,a[father].flag);
			a[father].flag=0;
		}
		if(min<=mid) ans|=find(min,max,father*2);
		if(max>mid) ans|=find(min,max,father*2+1);
		return ans;
	}
}
int main()
{
	int i,j;
	bit[0]=1;
	for(i=1;i<32;i++) bit[i]=bit[i-1]*2;
	int n,t,o;
	char str[100];
	while(scanf("%d%d%d",&n,&t,&o)!=EOF)
	{
		build(0,n,1);
		while(o--)
		{
			scanf("%s",str);
			if(str[0]=='C')
			{
				int A,B,C;
				scanf("%d%d%d",&A,&B,&C);
				if(A>B) swap(A,B);
				insert(A,B,1,C);
			}
			else
			{
				int A,B;
				int ans;
				scanf("%d%d",&A,&B);
				if(A>B)swap (A,B);
				ans=find(A,B,1);
				int cnt=0;
				for(i=0;i<32;i++)
				{
					if(ans&bit[i]) cnt++;
				}
				printf("%d\n",cnt);
			}
		}
	}
	return 0;
}