#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define maxn 100
struct node
{
	char s[10];
	int b;
}ans[maxn];
void f(int n,char s[],int i)
{
	int a[10],k;
	for(k=0;k<i;k++)
	{
		a[k]=n%10;
		n/=10;
	}
	for(n=0,k--;k>=0;k--,n++)
	{
		s[n]=a[k]+'0';
	}
	s[n]='\0';
}
bool cmp(const node &x,const node &y)
{
	return x.b>y.b;
}
int m;
int pow(int n)
{
	int ans=1;
	while(n--) ans*=10;
	return ans;
}
int main()
{
	int a[10];
	int n,i,j,m,l,tp,cnt,k,p;
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;
		for(j=n,i=0;j;i++,j/=10);
		m=i;
		if(m<=1)
		{
			printf("0\n");
			continue;
		}
		if(n%11<10)
		{
			ans[cnt].b=n/11;
			itoa(ans[cnt].b,ans[cnt].s,10);
			cnt++;
		}
		if(n%2==0)
		{
			k=pow(m-1);
			for(i=1;i*k<=n;i++)
			{
				if((n-i*k)/2<k)
				{
					ans[cnt].b=(n-i*k)/2;
					f(ans[cnt].b,ans[cnt].s,m-1);
					cnt++;
				}
			}
		}
		for(i=1;i+1<m;i++)
		{
			for(j=0;j<10;j++)
			{
				k=pow(i);
				tp=n-j*k;
				if(i*2<=m)
				{
					for(l=0;l<k;l++)
					{
						if((tp-2*l)%(11*k)==0)
						{
							ans[cnt].b=l+(tp-2*l)/(11*k)*k;
							itoa(ans[cnt].b,ans[cnt].s,10);
							cnt++;
						}
					}
				}
				else
				{
					if(tp%2) continue;
					p=m-i-1;
					p=pow(p);
					for(l=0;l<p*10&&tp-l*k*11>=0;l++)
					{
						if((tp-l*k*11)/2<k)
						{
							ans[cnt].b=l*k+(tp-l*k*11)/2;
							itoa(ans[cnt].b,ans[cnt].s,10);
							cnt++;
						}
					}
				}
			}
		}
		sort(ans,ans+cnt,cmp);
		for(j=i=0;i+1<cnt;i++)
		{
			if(ans[i].b==ans[i+1].b) j++;
		} 
		printf("%d\n",cnt-j);
		for(i=0;i<cnt;i++)
		{
			if((i+1)<cnt&&ans[i].b ==ans[i+1].b) continue;
			printf("%d + %s = %d\n",n-ans[i].b,ans[i].s,n);
		}
	}
	return 0;
}