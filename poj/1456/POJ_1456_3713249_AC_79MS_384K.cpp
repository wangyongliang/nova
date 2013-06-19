#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int x,y;
}a[11000];
bool cmp(const node &x,const node &y)
{
	if(x.y==y.y) return x.x>y.x;
	else return x.y<y.y;
}
struct cp
{
	bool operator()(const int &x,const int &y)
	{
		return x>y;
	}
};
priority_queue<int,vector<int>,cp>heap;
int main()
{
	int n;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		while(heap.size()) heap.pop();
		sort(a,a+n,cmp);
		int t=0;
		for(i=0;i<n;i++)
		{
			heap.push(a[i].x);
			while(heap.size()>a[i].y) heap.pop();
		}
		int sum=0;
		while(heap.size()) 
		{
			sum+=heap.top();
			heap.pop();
		}
		printf("%d\n",sum);
	}
	return 0;
}