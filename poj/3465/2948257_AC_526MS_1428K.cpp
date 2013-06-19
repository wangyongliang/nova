
#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int> heap;
void init()
{
	while(heap.size()) heap.pop();
}
#define maxn 200000
int a[maxn], b[maxn];
int main()
{
	int i,n,t=1;
	int h1,h2,max,temp,x,y;
	while(scanf("%d%d%d%d%d",&n,&x,&y,&h1,&h2)!=EOF)
	{
		init();
		temp=h2;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			b[i]=h2;
		}
		for(i=0;i<n;i++)
		{
			if(y>a[i]) max=y;
			else max=a[i];
			heap.push(max);
			h2-=x;
			b[i]=h2;
			if(h2>0) h1-=a[i];
			else break;
			while(h1<=0)
			{
				h1+=heap.top();
				h2+=x;
				heap.pop();
			}
		}
		if(h2<=0) printf("Win\n%d\n",i+1);
		else 
		{
			for(i=0,max=b[0];i<n;i++)
			{
				if(max>b[i])max=b[i];
			}
			printf("Lose\n%d\n",temp-max);
		}
	}
	return 0;
}