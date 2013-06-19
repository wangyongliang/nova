#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int dis,fule;
}data[100100];
bool cmp(const node &a,const node &b)
{
	return a.dis<b.dis;
}
bool operator< (const node &a,const node &b)
{
	return a.fule<b.fule;
}
priority_queue<node> heap;
void init()
{
	while(heap.size()) heap.pop();
}
int  main()
{
	int n;
	node temp;
	int l,p,i,j;
	vector <node> ::iterator it;
	while(scanf("%d",&n)!=EOF)
	{
		data[0].dis=0;
		data[0].fule=0;
		for(i=1;i<=n;i++) scanf("%d%d",&data[i].dis,&data[i].fule);
		sort(data,data+n+1,cmp);
		for(i=0;i<n;i++)
		{
			if(data[i+1].dis==data[i].dis) data[i+1].fule+=data[i].fule,data[i].fule=0;;
		}
		scanf("%d%d",&l,&p);
		for(i=n;i>=0&&data[i].dis==l;i--)
		{
			p+=data[i].fule;
		}
		int cnt=0;
		init();
		int flag=1;
		while(i>=0)
		{
			while(p<l-data[i].dis)
			{
				if(heap.size()==0) 
				{
					flag=0;
					goto line;
				}
				p+=heap.top().fule;
				cnt++;
				heap.pop();
			}
			heap.push(data[i]);
			i--;
		}
line:;
	 if(flag==0) printf("-1\n");
	 else printf("%d\n",cnt);
	}
	return 0;
}