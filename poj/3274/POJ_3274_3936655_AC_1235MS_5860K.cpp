#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
struct node 
{
	long long tp1,tp2;
};
bool operator <(const node &x,const node &y)
{
	if(x.tp1==y.tp1) return x.tp2<y.tp2;
	return x.tp1<y.tp1;
}
map<node,int > mp;
long long c1[32],c2[32];
int main()
{
	int n,k;
	srand(432758235);
	int i,j;
	long long cnt[32],ct[32];
	node tp;
	int ans=0;
	for(i=0;i<32;i++)
	{
		c1[i]=rand();
		c2[i]=rand();
	}
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		mp.clear();
		for(i=0;i<k;i++) cnt[i]=0;
		tp.tp1=tp.tp2=0;
		mp[tp]=1;
		ans=0;
		for(i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			for(j=0;j<k;j++)
			{
				if((1<<j)&m)
				{
					cnt[j]++;
				}
			}
			for(m=j=0;j<k;j++)
			{
				if(cnt[j]<cnt[m]) m=j;
				ct[j]=cnt[j];
			}
			m=ct[m];
			for(j=0;j<k;j++) ct[j]-=m;
			tp.tp1=tp.tp2=0;
			for(j=0;j<k;j++) 
			{
				tp.tp1+=ct[j]*c1[j];
				tp.tp2+=ct[j]*c2[j];
			}

			if(mp[tp])
			{
				if(ans<i+2-mp[tp]) ans=i+2-mp[tp];
			}
			else mp[tp]=i+2;
		}
		printf("%d\n",ans);
	}
	return 0;
}