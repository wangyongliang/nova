#include<stdio.h>
#include<math.h>
#include<algorithm>
#define inf 1e-10
#include<queue>
using namespace std;
struct node
{
	int t,b,a;
}data[1001000];
bool operator <(const node &a,const node &b)
{
	 return a.a<b.a;
}
bool cmp(const node &a,const node &b)
{
	return a.t<b.t;
}

priority_queue<node> heap;
void clear()
{
	while(heap.size()) heap.pop();
}
int main()
{
	int n,i,j;
	node temp;
	int sum;
	double ans;
	while(scanf("%d",&n)!=EOF)
	{
		clear();
		for(i=0;i<n;i++) scanf("%d%d%d",&data[i].a,&data[i].b,&data[i].t);
		sort(data,data+n,cmp);
		sum=ans=0;
		for(i=0;i<n;i++)
		{
			heap.push(data[i]);
			sum+=data[i].b;
			while(sum-data[i].t>0)
			{
				temp=heap.top();
				if(sum-data[i].t>temp.b)
				{
					sum-=temp.b;
					ans+=temp.b*1.0/temp.a;
					heap.pop();
				}
				else
				{
					ans+=(sum-data[i].t)*1.0/temp.a;
					temp.b-=sum-data[i].t;
					sum=data[i].t;
					heap.pop();
					heap.push(temp);
				}
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}