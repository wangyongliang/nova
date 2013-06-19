#include<stdio.h>
#include<algorithm>
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int min(int x,int y)
{
	if(x>y) return y;
	return x;
}

using namespace std;
struct node
{
	int x,y;
} a[1000000],c[1000000];
int n;
struct line
{
	int dir,x,y,xx,yy;
}b[1000000];
bool cmp (const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool map[2100][2100];
bool check(int i,int j)
{
	int k;
	if(a[i].x==a[j].x||a[i].y==a[j].y) return 0;
	for(k=min(a[i].x,a[j].x);k<=max(a[j].x,a[i].x);k++) 
		if(map[k][a[i].y]==0)		return 0;
	for(k=min(a[i].x,a[j].x);k<=max(a[j].x,a[i].x);k++) 
		if(map[k][a[j].y]==0)		return 0;
	for(k=min(a[i].y,a[j].y);k<=max(a[j].y,a[i].y);k++)
		if(map[a[i].x][k]==0)
			return 0;
	for(k=min(a[i].y,a[j].y);k<=max(a[j].y,a[i].y);k++) 
		if(map[a[j].x][k]==0)
			return 0;
	return 1;
}
bool eq(int i,int j)
{
	if(a[i].x==a[j].x&&a[i].y==a[j].y) return 1;
	return 0;
}
bool cmp2(const line &A,const line &B)
{
	if(A.x==B.x)
	{
		if(A.y==B.y)
		{
			if(A.xx==B.xx)
			{
				return A.yy<B.yy;
			}
			return A.xx<B.xx;
		}
		return A.y<B.y;
	}
	return A.x<B.x;
}
int main()
{
	int t,s,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&s);
		for(i=0;i<=2000;i++)
		{
			for(j=0;j<=2000;j++) map[i][j]=0;
		}
		for(n=i=0;i<s;i++)
		{
			scanf("%d%d%d%d",&b[i].y,&b[i].x,&b[i].yy,&b[i].xx);
			b[i].x*=2;
			b[i].y*=2;
			b[i].xx*=2;
			b[i].yy*=2;
		//	a[n].x=b[i].x;
		//	a[n++].y=b[i].y;
		//	a[n].x=b[i].xx;
		//	a[n++].y=b[i].yy;
			if(b[i].x==b[i].xx)
			{
				b[i].dir=0;
				if(b[i].y>b[i].yy) swap(b[i].y,b[i].yy);
				for(j=b[i].y;j<=b[i].yy;j++)
				{
					map[b[i].x][j]=1;
				}
			}
			else
			{
				b[i].dir=1;
				if(b[i].x>b[i].xx) swap(b[i].x,b[i].xx);
				for(j=b[i].x;j<=b[i].xx;j++) map[j][b[i].y]=1;
			}
		}
		for(i=0;i<s;i++)
		{
			for(j=i+1;j<s;j++)
			{
				if(b[i].dir!=b[j].dir)
				{
					if(b[i].dir==0&&b[j].x<=b[i].x&&b[j].xx>=b[i].x&&b[i].y<=b[j].y&&b[i].yy>=b[j].y)
					{
						a[n].x=b[i].x;
						a[n++].y=b[j].y;
					}
					if(b[i].dir==1&&b[j].y<=b[i].y&&b[j].yy>=b[i].y
						&&b[i].x<=b[j].x&&b[i].xx>=b[j].x)
					{
						a[n].x=b[j].x;
						a[n++].y=b[i].y;
					}
				}
			}
		}
		sort(a,a+n,cmp);
		c[0]=a[0];
		for(i=j=1;i<n;i++)
		{
			if(!eq(i,i-1))
			{
				c[j++]=a[i];
			}
		}
		for(i=0;i<j;i++) a[i]=c[i];
		n=j;
		int ans=0;
//		printf("sjdls\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(check(i,j))
				{
					b[ans].x=min(a[i].x,a[j].x);
					b[ans].xx=max(a[i].x,a[j].x);
					b[ans].y=min(a[i].y,a[j].y);
					b[ans++].yy=max(a[i].y,a[j].y);
				}
			}
		}
		sort(b,b+ans,cmp2);
		for(i=j=0;i<ans;i++)
		{
			if(i>0&&b[i].x==b[i-1].x&&b[i].y==b[i-1].y&&b[i].xx==b[i-1].xx
				&&b[i].yy==b[i-1].yy) continue;
			j++;
		}
		printf("%d\n",j);
	}
	return 0;
}