//pku 1468 1470 的其他方法
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define maxn 1000
using namespace std;
struct node
{
	int x;
	int y;
}a[maxn];
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
int main()
{
	int n,i,j;
	int t=1;
	int x,y,z;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d: ",t++);
		if(n==1) printf("1\n");
		else
		{
			j=0;
			if(n%2==0)
			{
				a[j].x=1;
				a[j++].y=1;
				while(n%2==0) n/=2;
			}
			for(i=3;n!=1;i+=2)
			{
				if(n%i==0)
				{
					if(i%4==3)
					{
						a[j].x=i;
						a[j++].y=0;
					}
					else
					{
						x=1;
						while(x*x*2<=i)
						{
							z=i-x*x;
							y=(int)sqrt(z);
							if(x*x+y*y==i)
							{
								a[j].x=x;
								a[j++].y=y;
							}
							x++;
						}
					}
					while(n%i==0) n/=i;
				}
			}
			sort(a,a+j,cmp);

			if(a[0].y)
			{
				if(a[0].y!=1)
				{printf("%d+%dj",a[0].x,a[0].y);
				printf(", %d-%dj",a[0].x,a[0].y);}
				else 
				{
					printf("%d+j",a[0].x);
					printf(", %d-j",a[0].x);
				}
			}
			else printf("%d",a[0].x);
			for(i=1;i<j;i++)
			{
				if(a[i].y)
				{
				if(a[i].y!=1)
				{printf(", %d+%dj",a[i].x,a[i].y);
				printf(", %d-%dj",a[i].x,a[i].y);}
				else 
				{
					printf("%d+j",a[i].x);
					printf(", %d-j",a[i].x);
				}
				}
				else
				{
					printf(", %d",a[i].x);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
