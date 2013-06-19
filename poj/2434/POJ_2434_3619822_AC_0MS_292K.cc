#include<stdio.h>
#include<algorithm>
using namespace std;
int abs(int x)
{
	if(x>=0) return x;
	else return -x;
}
int a[10][10];
int n,b1,b2,r;
void f(int x,int y,int t,int flag)
{
	int i,j,k,tpx,tpy,xx,yy,p;
	for(i=0;i<=9;i++)
	{
		tpx=t-i;
		tpy=i;
		tpx=t-abs(tpy-y);
		if(tpx<0) continue;
		for(j=-1;j<=1;j+=2)
		{
		//	for(k=-1;k<=1;k+=2)
			{
				xx=j*tpx;
				yy=tpy;
				if(xx==0&&j==1) continue;
			//	if(yy==0&&k==1) continue;
				xx+=x;
			//	yy+=y;
				if(x<b1)
				{
					if(xx>=b1) xx=b1+b1-1-xx;
				}
				else if(x>b2)
				{
					if(xx<=b2)	xx=b2+b2+1-xx;
				}
				else
				{
					if(j==-1&&xx<=b1)
					{
					//	xx=abs(xx-x)-abs(x-b1)+1;
						xx=b1-xx+1;
						p=xx/(b2-b1-1);
						xx%=(b2-b1-1);
						if(p%2==0)
						{
							if(xx)xx+=b1;
							else xx=b1+1;
						}
						else 
						{
							if(xx) xx=b2-xx;
							else xx=b2-1;
						}
					}
					if(j==1&&xx>=b2)
					{
						//xx=abs(xx-x)-abs(b2-x)+1;
						xx=xx-b2+1;
						p=xx/(b2-b1-1);
						xx%=(b2-b1-1);
						if(p%2==0)
						{
							if(xx)xx =b2-xx;
							else xx=b2-1;
						}
						else
						{
							if(xx)xx+=b1;
							else xx=b1+1;
						}
					}
				}
				if(xx>=0&&xx<10&&yy>=0&&yy<10) a[xx][yy]+=flag;
			}
		}
	}
}
int main()
{
	int i,j,k;
	int x,y,t;
//	freopen("1.in","r",stdin);
//	freopen("2.out","w",stdout);
	while(scanf("%d%d%d%d",&n,&b1,&b2,&r)!=EOF)
	{
		b1+=4;
		b2+=4;
		if(b1>b2) swap(b1,b2);
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++) a[i][j]=0;
		}
		int t;
		while(n--)
		{
			scanf("%d%d%d",&x,&y,&t);
			x+=4;
			y+=4;
			f(x,y,r-t,1);
			f(x,y,r-t-2,-1);
		}
		for(i=8;i>=0;i--)
		{
			for(j=0;j<9;j++) 
			{
				if(j==b1||j==b2) 
				{
					printf("X");
					continue;
				}
				if(a[j][i]>0) printf("*");
				else if(a[j][i]==0) printf("-");
				else printf("o");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}