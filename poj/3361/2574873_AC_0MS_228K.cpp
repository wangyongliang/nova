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

bool flag[100000]={0};
int prime[10000];

void init()
{
	int i,j;
	prime[0]=1;
	for(i=2;i*i<100000;i++)
	{
		if(flag[i]==0)
		{
			prime[prime[0]]=i;
			prime[0]++;
			for(j=i*i;j<100000;j+=i) flag[j]=1;
		}
	}
	for(;i<100000;i++)
	{
		if(flag[i]==0) 
		{
			prime[prime[0]]=i;
			prime[0]++;
		}
	}
}
int main()
{
	int n,i,j;
	int t=1;
	int x,y,z;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d: ",t++);
		if(n==1) printf("1\n");
		else
		{
			j=0;
			for(i=1;i<prime[0];i++)
			{
				if(n%prime[i]==0)
				{
					if(prime[i]%4==3)
					{
						a[j].x=prime[i];
						a[j++].y=0;
					}
					else
					{
						x=1;
						while(x*x*2<=prime[i])
						{
							z=prime[i]-x*x;
							y=(int)sqrt(z);
							if(x*x+y*y==prime[i])
							{
								a[j].x=x;
								a[j++].y=y;
							}
							x++;
						}
					}
					while(n%prime[i]==0) n/=prime[i];
				}
				if(n==1) break;
			}
			i=n;
			if(i)
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
