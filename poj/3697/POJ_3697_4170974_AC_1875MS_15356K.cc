#include<stdio.h>
#include<vector>
using namespace std;

#define maxn 100010
int d[maxn],index[maxn],heap[maxn],m;
vector<int> a[maxn];
void shiftdown(int k)
{
	heap[0]=heap[k];
	int i=k;
	int j=i*2;
	while(j<=m)
	{
		if(j+1<=m&&d[heap[j+1]]<d[heap[j]]) j++;
		if(d[heap[j]]<d[heap[0]])
		{
			heap[i]=heap[j];
			index[heap[i]]=i;
			i=j;
			j=i*2;			
		}
		else break;
	}
	heap[i]=heap[0];
	index[heap[i]]=i;
}
int main()
{
	int n,k=1,i,j;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=1;i<=n;i++) 
		{
			a[i].clear();
			d[i]=0;
			heap[i]=i;
			index[i]=i;
		//	flag[i]=1;
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			a[j].push_back(i);
		}
		int ans=1;
		m=n;
		heap[1]=heap[m--];
		index[1]=maxn;
		shiftdown(1);
		for(i=0;i<a[1].size();i++)
		{
			d[a[1][i]]++;
			shiftdown(index[a[1][i]]);
		}
		while(m>0)
		{
			int x=heap[1];
			if(d[x]>=ans) break;
			ans++;
			index[x]=maxn;
			heap[1]=heap[m--];
			shiftdown(1);
			for(i=0;i<a[x].size();i++)
			{
				if(index[a[x][i]]<=m)
				{
					d[a[x][i]]++;
					shiftdown(index[a[x][i]]);
				}
			}
		}
		printf("Case %d: %d\n",k++,ans-1);
	}
	return 0;
}