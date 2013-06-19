#include<stdio.h>
#include<vector>
#define inf 1000000000
using namespace std;
struct node
{
	int x,y;
};
vector<node> a[1010],b[1010];
int n,s,f;
int dij()
{
	int close[1100],i,j,min;
	int num[1100][2];
	vector <node> ::iterator it;
	for(i=1;i<=n;i++) close[i]=inf,num[i][0]=num[i][1]=0;
	close[s]=0;
	num[s][0]=1;
	while(1)
	{
		for(i=1;close[i]==-1;i++) ;
		min=i;
		for(;i<=n;i++)
		{
			if(close[i]!=-1&&close[i]<close[min]) min=i;
		}
		for(it=b[min].begin();it!=b[min].end();it++)
		{
			if(close[it->x]==close[min]) num[min][1]+=num[it->x][0];
		}
		if(min==f) return num[f][0]+num[f][1];
		for(it=a[min].begin();it!=a[min].end();it++)
		{
			if(close[it->x]!=-1)
			{
				if(close[min]+it->y==close[it->x]+1) num[it->x][1]+=num[min][0];
				else if(close[min]+it->y==close[it->x]) 
				{
					num[it->x][0]+=num[min][0];
					num[it->x][1]+=num[min][1];
				}
				else if(close[min]+it->y==close[it->x]-1)
				{
					close[it->x]--;
					num[it->x][1]=num[it->x][0]+num[min][1];
					num[it->x][0]=num[min][0];
				}
				else if(close[min]+it->y<close[it->x])
				{
					close[it->x]=close[min]+it->y;
					num[it->x][0]=num[min][0];
					num[it->x][1]=num[min][1];
				}
			}
		}
		close[min]=-1;
	}
}
int main()
{
	int t,i,j;
	int m;
	node temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++) a[i].clear(),b[i].clear();
		while(m--)
		{
			scanf("%d%d%d",&i,&temp.x,&temp.y);
			a[i].push_back(temp);
			if(temp.y==1)
			{
				j=temp.x;
				temp.x=i;
				b[j].push_back(temp);
			}
		}
		scanf("%d%d",&s,&f);
		printf("%d\n",dij());
	}
	return 0;
}