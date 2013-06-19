#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
struct node
{
	int x,y;
	double l;
}a[300000];
char s[10000];
int n;
int f(double mid)
{
	double dis[900];
	int i,j,flag;
	for(i=0;i<900;i++) dis[i]=-1e10;
	int x,y;
	double l;
	for(i=0;i<=680;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			x=a[j].x;
			y=a[j].y;
			l=a[j].l-mid;
			if(dis[x]+l>dis[y]) dis[y]=dis[x]+l,flag=1;
		}
		if(flag==0) break;
	}
	return flag;
}
int main()
{
	int i,j;
	int x,y,l;
	double min,max,mid;
//	freopen("i1.in","r",stdin);
//	freopen("ans.out","w",stdout);
	while(scanf("%d",&n)&&n)
	{
		min=1e10;
		max=0.0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			l=strlen(s);
			x=(s[0]-'a')*26+s[1]-'a';
			y=(s[l-2]-'a')*26+s[l-1]-'a';
			a[i].x=x;
			a[i].y=y;
			a[i].l=(double)l;
			min=min>a[i].l?a[i].l:min;
			max=max<a[i].l?a[i].l:max;
		}
		min=0.00;
		while(max-min>1e-3)
		{
			mid=(min+max)/2;
			if(f(mid)) min=mid;
			else max=mid;
		}
		if(min>1e-3)
			printf("%.2lf\n",min);
		else printf("No solution.\n");
	}
	return 0;
}
