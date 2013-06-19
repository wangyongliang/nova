#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 20000
struct node
{
	int x,y;
}a[maxn];
int b[maxn][2];
bool cmp(const node &x,const node &y)
{
	if(x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}
bool operator<(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x>y.x;
}
priority_queue<node> heap;
int main()
{
	int i,j,n,l,k;
	node temp;
	while(heap.size()) heap.pop();
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
		//	temp=heap.top();
			k=heap.size();
			if(heap.size()<l*(a[i].y+1)) heap.push(a[i]);
			else
			{
				temp=heap.top();
				if(temp.x<a[i].x) 
				{
					heap.pop();
					heap.push(a[i]);
				}
			}
		}
		int ans=0;
		while(heap.size()) 
		{
			temp=heap.top();
			ans+=temp.x;
			heap.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}