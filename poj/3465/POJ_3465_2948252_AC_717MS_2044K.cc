//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//pku 3293
#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<__int64> heap;
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
//	scanf("%d%I64d%I64d%I64d%I64d",&n,&x,&y,&h1,&h2);
	while(scanf("%d%d%d%d%d",&n,&x,&y,&h1,&h2)!=EOF)
	{
	//	puts(s);
//		scanf("%d%I64d%I64d%I64d%I64d",&n,&x,&y,&h1,&h2);
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
	//	printf("Sample Output %d\n",t++);
		if(h2<=0) printf("Win\n%d\n",i+1);
		else 
		{
			for(i=0,max=b[0];i<n;i++)
			{
				if(max>b[i])max=b[i];
			}
			printf("Lose\n%d\n",temp-max);
		}
//		getchar();
	}
	return 0;
}