#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x,y;
}a[2600],b[2600];
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
struct cp
{
	bool operator()(const int &x,const int &y) {return x>y;}
};
priority_queue<int,vector<int>,cp> heap;
int main()
{
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		while(heap.size()) heap.pop();
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		for(i=0;i<m;i++) scanf("%d%d",&b[i].x,&b[i].y);
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		int ans=0;
		for(j=i=0;i<m;i++)
		{
			for(;j<n&&a[j].x<=b[i].x;j++)  heap.push(a[j].y);
			while(heap.size()&&(heap.top()<b[i].x)) heap.pop();
			while(heap.size()&&b[i].y)
			{
				ans++;
				k=heap.top();
				heap.pop();
				b[i].y--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}