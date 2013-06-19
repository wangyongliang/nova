/*
ID: 05272021
LANG: C++
PROG:
*/
/*crackerwang*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define ABS(X)  (x)>0?(x):-(x)
#define ps system("pause")
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)

#define maxn 100010
struct cmp
{
	bool operator()(const int x,const int y)
	{
		return x<y;
	}
};
priority_queue<int,vector<int>,cmp> heap;
long long total1[maxn],total2[maxn];

struct node
{
	int x,y;
}a[maxn];
bool cp(node x,node y)
{
	return x.x<y.x;
}
int main()
{
	int n,m;
	int i,j;
	long long f;
	while(scanf("%d%d%I64d",&n,&m,&f)!=EOF)
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			total1[i]=total2[i]=f;
		}
		sort(a,a+m,cp);
		while(heap.size()) heap.pop();
		long long sum=0;
		for(i=0;i<n/2;i++)
		{
			heap.push(a[i].y)			;
			sum+=a[i].y;
		}
		for(;i<m;i++)
		{
			total1[i]=sum;
			heap.push(a[i].y);
			sum+=a[i].y;
			sum-=heap.top();
			heap.pop();
		}
		sum=0;
		while(heap.size()) heap.pop();
		for(i=m-1;i>=m-n/2;i--)
		{
			sum+=a[i].y;
			heap.push(a[i].y)			;
		}
		for(;i>=0;i--)
		{
			total2[i]=sum;
			heap.push(a[i].y);
			sum+=a[i].y;
			sum-=heap.top();
			heap.pop();
		}
//		for(i=0;i<m;i++)
		{
	//		cout<<a[i].x<<" "<<a[i].y<<" " <<total1[i]<<" "<<total2[i]<<endl;
		}
		for(i=m-1;i>=0;i--)
		{
			if(total1[i]+total2[i]+a[i].y<=f) break;
		}
		if(i<0) printf("-1\n");
		else printf("%d\n",a[i].x);
		
	}
	return 0;
}
