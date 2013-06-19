#include<stdio.h>
#include<vector>
using namespace std;
struct node
{
	int x,time;
};
vector<node> a[1000];
int dis[1000];
int main()
{
	int n,m;
	int i,j,k,x,y;
	node tp;
	char s[10];
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		n++;
		m++;
		for(i=0;i<=n*m;i++) a[i].clear();
		for(i=0;i<n;i++)
		{
			for(j=0;j+1<m;j++)
			{
				x=i*m+j;
				y=i*m+j+1;
				scanf("%d%s",&k,s);
				if(k)
				{
					tp.time=2520/k;
					if(s[0]=='*')
					{
						tp.x=x;
						a[y].push_back(tp);
						tp.x=y;
						a[x].push_back(tp);
					}
					if(s[0]=='>') tp.x=y,a[x].push_back(tp);
					if(s[0]=='<') tp.x=x,a[y].push_back(tp);
				}
			}
			if(i==n-1) break;
			for(j=0;j<m;j++)
			{
				x=i*m+j;
				y=(i+1)*m+j;
				scanf("%d%s",&k,s);
				if(k)					
				{
					tp.time=2520/k;
					if(s[0]=='*')
					{
						tp.x=x;
						a[y].push_back(tp);
						tp.x=y;
						a[x].push_back(tp);
					}
					if(s[0]=='v') tp.x=y,a[x].push_back(tp);
					if(s[0]=='^') tp.x=x,a[y].push_back(tp);
				}
			}
		}
		int en=(n-1)*m+m-1;
		for(i=0;i<=en;i++) dis[i]=0x7ffffff;
		dis[0]=0;
		for(i=0;i<=en;i++)
		{
			for(k=0;dis[k]==-1&&k<=en;k++);
			for(j=k;j<=en;j++)
			{
				if(dis[j]>0&&dis[j]<dis[k]) k=j;
			}
			if(k==en) break;
		//	printf("%d\n",a[k].size());
			for(j=0;j<a[k].size();j++)
			{
			//	printf("%d %d\n",a[k][j].x,a[k][j].time);
				if(dis[a[k][j].x]>0&&dis[a[k][j].x]>dis[k]+a[k][j].time)
				{
					dis[a[k][j].x]=dis[k]+a[k][j].time;
				}
			}
			dis[k]=-1;
		}
		if(dis[en]==0x7ffffff) printf("Holiday\n");
		else printf("%d blips\n",dis[en]);
	}
	return 0;
}