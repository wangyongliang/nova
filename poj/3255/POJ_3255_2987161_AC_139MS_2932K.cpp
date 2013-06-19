#include<queue>
#include<vector>
#include<stdio.h>
#include<algorithm>
#define inf 1000000000
#define maxn 5000+10
using namespace std;
struct node
{
	int x,dis;
};
bool operator < (const node &xx,const node &yy)
{
//	if(xx.dis==yy.dis) return xx.cnt>yy.cnt;
	return xx.dis>yy.dis;
}
priority_queue<node> heap;
vector<node> a[maxn];
int n,m,flag[maxn],min[maxn][2];
int bfs()
{
	node temp,temp1;
	temp.x=1;
	temp.dis=100;
//	temp.cnt=0;
	flag[1]=0;
	min[1][0]=0;
	heap.push(temp);
	vector <node>::iterator it;
	while(1)
	{
		temp=heap.top();
	//	printf("%d %d\n",heap.top().x,heap.top().dis);
		if(temp.x==n)
		{
			if(flag[n]) return temp.dis;
		}
		if(flag[temp.x]==2) 
		{
			heap.pop();
			continue;
		}
		else
		{
			for(it=a[temp.x].begin();it!=a[temp.x].end();it++)
			{
				if(flag[it->x]<2)
				{
					if(it->dis+temp.dis<min[it->x][1])
					{
						min[it->x][1]=it->dis+temp.dis;
						if(min[it->x][1]<min[it->x][0]) swap(min[it->x][0],min[it->x][1]);
						temp1.x=it->x;
					//	temp1.cnt=temp.cnt+1;
						temp1.dis=it->dis+temp.dis;
						heap.push(temp1);
					}
				}
			}
		//	printf("%d\n",heap.size());
			heap.pop();
		//	printf("%d\n",heap.size());
			
			flag[temp.x]++;
		}
		
	}
}
int main()
{
	int i,j;
	node temp;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) 
		{
			a[i].clear();
			flag[i]=0;
			min[i][0]=min[i][1]=inf;
		}
		while(!heap.empty()) heap.pop();
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&temp.dis);
			temp.x=j;
			a[i].push_back(temp);
			temp.x=i;
			a[j].push_back(temp);
		}
		printf("%d\n",bfs()-100);
	}
	return 0;
}