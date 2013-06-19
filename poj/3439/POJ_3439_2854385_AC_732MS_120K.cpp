#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
struct node
{
	__int64 x,y;
}a[1100];
int n;
vector<int> b[1100];
double len2,len1;
__int64 len;
__int64 dis(int i,int j)
{
	__int64 ans;	
	ans=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
	return ans;
}
int q[100000];
int bfs(int x,int y)
{
	int st=0,en=2,i,j;
	int ans=0;
	bool flag[1100]={0};
	vector<int> ::iterator it;
	q[0]=x;
	flag[x]=1;
	q[1]=-1;
	while(1)
	{
		if(st==en-1&&q[st]==-1) return -1;
		if(q[st]==-1)
		{
			q[en++]=-1;
			ans++;
		}
		else if(q[st]==y) return ans;
		else
		{
			j=q[st];
			for(i=0;i<n;i++)
			{
				if(i==j) continue;
				if(!flag[i]&&dis(i,j)<len)
				{
					flag[i]=1;
					q[en++]=i;
				}
			}
		}
		st++;
	}
}
int main()
{
	int i,j;
	int t;
	int x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%lf%lf",&n,&x,&y,&len1,&len2);
		len1+=len2;
		len1*=len1;
		len=(__int64) len1 +1;
		for(i=0;i<n;i++) 
		{
			scanf("%I64d%I64d",&a[i].x,&a[i].y);
		}
		x--;
		y--;
		i=bfs(x,y);
		if(i==-1) printf("Impossible\n");
		else printf("%d\n",i);
	}
	return 0;
}
