#include<stdio.h>
#include<list>
using namespace std;
#define maxn 40000
list<int> a;
list<int> ::iterator it;
int ans[3010];
int main()
{
	int i,j,k;
	a.clear();
	int tp;
	for(i=2;i<maxn;i++) a.push_back(i);
	for(i=0;i<3000;i++)
	{
		it=a.begin();
		if(it==a.end()) break;
		k=*it;
		it=a.erase(it);
		ans[i]=k;
		for(j=0;it!=a.end();it++,j++)
		{
			tp=*it;
			if(j==k-1) 
			{
				it=a.erase(it);
				it--;
				tp=*it;
				j=-1;
			}
		}
	//	printf("%d\n",i);
	}
//	printf("OK\n");
	int n;
	while(scanf("%d",&n)&&n)
	{
		printf("%d\n",ans[n-1]);
	}
	return 0;
}
