#include<stdio.h>
#define maxn 1000000
int a[maxn],b[maxn],l[maxn],r[maxn];
__int64 ans[maxn];
int q[maxn];
bool flag[maxn];

int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	int n;
	int i,j,qq;
	while(scanf("%d",&n)!=EOF)
	{
		j=0;
		b[0]=10000000;
		for(i=1;i<=n;i++) 
		{
			scanf("%d%d",&a[i],&b[i]);
			if(b[i]<b[j]) j=i;
			r[i]=l[i]=i;
			flag[i]=0;
		}
		b[n+1]=10000000;
		qq=0;
		q[qq++]=j;
		flag[j]=1;
		__int64 t=0,tp;
		while(qq)
		{
			i=q[qq-1];
			if(b[i]==10000000) break;
			if(b[r[i]-1]>b[i]&&b[l[i]+1]>b[i])
			{
				ans[i]=t+a[i];
				qq--;
				tp=a[i];
				t+=tp*(min(b[r[i]-1],b[l[i]+1])-b[i]);
				if(b[r[i]-1]<b[l[i]+1])
				{
					j=r[i]-1;
					l[j]=l[i];
					a[j]+=a[i];
					if(flag[j]==0)
					{
						q[qq++]=j;
						flag[j]=1;
					}
				}
				else
				{
					j=l[i]+1;
					r[j]=r[i];
					a[j]+=a[i];
					if(flag[j]==0)
					{
						q[qq++]=j;
						flag[j]=1;
					}
				}
			}
			else if(b[r[i]-1]<b[l[i]+1])
			{
				j=r[i]-1;
				flag[j]=1;
				q[qq++]=j;
			}
			else
			{
				j=l[i]+1;
				flag[j]=1;
				q[qq++]=j;
			}
		}
		for(i=1;i<=n;i++) printf("%I64d\n",ans[i]);
	}
	return 0;
}