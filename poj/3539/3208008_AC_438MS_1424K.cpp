#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct cmp
{
	bool operator () (const int &a, const int &b)
	{
		return a>b;
	}
};
typedef __int64 int64;
priority_queue<int64,vector<int64>,cmp> heap;
#define maxn 1000010
int flag[maxn]={0};
int64 cnt[maxn];

int main()
{
	int64 n,a,b,c,ans,m,tp;
	int i,t=1;
	while(scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c)!=EOF)
	{
		if(a==1||b==1||c==1)
		{
			printf("%I64d\n",n);
			continue;
		}
		flag[1]=t;
		cnt[1]=1;
		while(heap.size()) heap.pop();
		heap.push(1);
		while(heap.size())
		{
			m=heap.top();
			heap.pop();
			if(m>=n) continue;
			tp=(m+a)%c;
			if((flag[tp]!=t&&m+a<=n)||(flag[tp]==t&&cnt[tp]>m+a))
			{
				flag[tp]=t,heap.push(m+a);
				cnt[tp]=m+a;
			}
			tp=(m+b)%c;
			if((flag[tp]!=t&&m+b<=n)||(flag[tp]==t&&cnt[tp]>m+b))
			{
				flag[tp]=t,heap.push(m+b);
				cnt[tp]=m+b;
			}
		}
		ans=0;
		for(i=0;i<c;i++)
		{
			if(flag[i]==t)
			{
				ans+=(n-cnt[i])/c+1;
			}
		}
		if(ans==0) ans=1;
		printf("%I64d\n",ans);
		t++;
	}
	return 0;
}
