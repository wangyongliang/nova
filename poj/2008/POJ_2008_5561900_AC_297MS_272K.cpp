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

#define maxn 1010
int x[maxn],y[maxn];
struct node
{
	int x,y;
}a[maxn];
int A,B,C;
bool cmp(node x,node y)
{
	return A*x.x+B*x.y<A*y.x+B*y.y;	
}

struct cp
{
	bool operator ()(node x,node y)
	{
		return x.y>y.y;
	}
};
priority_queue<node,vector<node>,cp> heap;
node tp[maxn];
int main()
{
	int n;
	int i,j,k;
	while(cin>>n)
	{
		cin>>A>>B>>C;
		for(i=0;i<n;i++)
		{
			 cin>>a[i].x>>a[i].y;
			 x[i]=a[i].x;
			 y[i]=a[i].y;
		}
		sort(x,x+n);
		sort(y,y+n);
		sort(a,a+n,cmp);
//		for(i=0;i<n;i++)
		{
	//		cout<<a[i].x<<"--"<<a[i].y<<endl;
		}
	//	cout<<"-------"<<endl;
		int ans=0;
		int m;
		for(i=0;i<n;i++)
		{
			if(i&&x[i]==x[i-1]) continue;
			while(heap.size()) heap.pop();
			k=0;
			m=0;
			for(j=0;j<n;j++)
			{
				if(a[j].x>=x[i]) tp[m++]=a[j];
			}
	//		for(j=0;j<m;j++) cout<<tp[j].x<<" "<<tp[j].y<<endl;
//			cout<<"-----------"<<endl;
			for(j=0;j<n;j++)
			{
				if(j&&y[j]==y[j-1]) continue;
				for(;k<m;k++)
				{
					if(A*tp[k].x+B*tp[k].y<=C+A*x[i]+B*y[j]) heap.push(tp[k]);
					else break;
				}
	//			cout<<"k== "<<k<<" "<<C+A*x[i]+B*y[j]<<endl;
	//			ps;
				while(heap.size())
				{
					if(heap.top().y<y[j]) heap.pop();
					else break;
				}
		//		if(ans<heap.size()) cout<<"heap.size() = "<<heap.size()<<endl;
				ans=MAX(ans,heap.size());
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
