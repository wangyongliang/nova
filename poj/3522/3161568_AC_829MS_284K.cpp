#include<stdio.h>
struct node
{
	int x,y,z;
}a[10000];
int index[200];
int find(int x)
{
	int y=x,z;
	while(index[y]!=y) y=index[y];
	while(x!=index[x])
	{
		z=x;
		x=index[x];
		index[z]=y;
	}
	return x;
}
int n,m;
int f(int min,int max)
{
	int i,j;
	int x,y;
	for(i=1;i<=n;i++) index[i]=i;
	for(i=0;i<m;i++)
	{
		if(a[i].z>=min&&a[i].z<=max)
		{
			x=find(a[i].x);
			y=find(a[i].y);
			index[y]=x;
		}
	}
	j=find(1);
	for(i=1;i<=n;i++)
	{
		if(j!=find(i)) return 0;
	}
	return 1;
}
bool flag[10100];
int b[10100];
int main()
{
	int min,max,minx,maxx,midx;
	int i,k;
//	freopen("F.in","r",stdin);
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		min=1000000;
		max=0;
		for(i=0;i<10010;i++) flag[i]=0;
		for(i=0;i<m;i++) 
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			flag[a[i].z]=1;
			min=a[i].z<min?a[i].z:min;
			max=a[i].z>max?a[i].z:max;
		}
		for(k=i=0;i<10010;i++)
		{
			if(flag[i]) b[k++]=i;
		}
		if(f(min,max)==0)
		{
			printf("-1\n");
			continue;
		}
		maxx=max-min;
		minx=0;
		b[k]=100000;
		while(minx<maxx)
		{
			midx=(minx+maxx)/2;
			for(i=0;i<k;i++)
			{
				if(i&&b[i-1]+midx>=max)
				{
					i=k;
					break;
				}
				if(f(b[i],b[i]+midx)) break;
			}
			if(i<k) maxx=midx;
			else minx=midx+1;
		}
		printf("%d\n",minx);
	}
	return 0;
}