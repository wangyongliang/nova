#include<stdio.h>
#define inf 9999999
int b[22],loc;
int a[20][22],n;
int path[22];
struct des
{
	int de;
	int time;
};
struct des p[22];
void dijs()
{
	int i,min,mini,t;
	int closed[22];
	t=n;
	for(i=1;i<=n;i++)
	{
		closed[i]=a[i][loc],path[i]=loc;
		if(a[i][loc]==-1) closed[i]=inf;
	}
	closed[loc]=-1;
	while(t--)
	{
		min=inf;
		mini=inf;
		for(i=1;i<=n;i++)
		{
			if(closed[i]<min&&closed[i]!=-1) min=closed[i],mini=i;
		}
		if(mini==inf) return ;
		closed[mini]=-1;
		b[mini]=min;
		for(i=1;i<=n;i++)
		{
			if(closed[i]!=-1&&a[i][mini]!=-1)
			{
				if(closed[i]>a[i][mini]+min) {closed[i]=a[i][mini]+min;path[i]=mini;}
			}
		}
	}
}
void find(int x,int y)
{
	if(x==y){printf("%d\n",x); return;}
	printf("%d\t",x);
	find(path[x],y);
}
int main()
{
	int i,j,k,min;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	scanf("%d",&loc);
	i=0;
	while(scanf("%d",&p[i++].de)!=EOF);
	i--;
	dijs();
	for(j=0;j<i;j++) p[j].time=b[p[j].de];
	printf("Org\tDest\tTime\tPath\n");
	for(k=0;k<i;k++)
	{
		min=k;
		for(j=k+1;j<i;j++) min=p[j].time<p[min].time?j:min;
		printf("%d\t%d\t%d\t",p[min].de,loc,p[min].time);
		find(p[min].de,loc);
		if(min!=k)
		{
			p[min].de=p[k].de;
			p[min].time=p[k].time;
		}
	}
	return 0;
}