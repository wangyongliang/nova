#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int a[5];
}b[ 10010];
int ans[10010];
bool cmp(const node &x,const node &y)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(x.a[i]!=y.a[i]) return x.a[i]<y.a[i];
	}
	return 0;
}
int ck(int i,int j)
{
	int k;
	for(k=0;k<5;k++) if(b[i].a[k]!=b[j].a[k]) return 0;
	return 1;
}
int main()
{
	int c[5];
	int n,i,j;
	int max;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++) scanf("%d",&c[j]);
			sort(c,c+5);
			for(j=0;j<5;j++) b[i].a[j]=c[j];
		}
		sort(b,b+n,cmp);
		ans[0]=1;
		max=0;
		for(i=1;i<n;i++)
		{
			int k=ck(i-1,i);
			if(k) ans[i]=ans[i-1]+1;
			else ans[i]=1;
			max=max<ans[i]?ans[i]:max;

		}
		j=0;
		for(i=0;i<n;i++)
		{
			if(max==ans[i]) j+=ans[i];
		}
		printf("%d\n",j);
	}
	return 0;
}
