#include<stdio.h>
#include<algorithm>
using namespace std;
#define  maxn 1000100
int a[maxn];
int ans[maxn];
int main()
{
	int i,j,k,n,p;
	int pb,pe,t;
	while(scanf("%d%d%d",&n,&k,&p)!=EOF)
	{
		t=0;
		for(i=0;i<k;i++) a[i]=i;
		pb=0;
		pe=k;
		for(i=1;i<=k;i++)
		{
			if(i%n==0) ans[t++]=a[pb];
			pb=(pb+1)%maxn;
			for(j=0;j<p;j++) 
			{
				a[pe]=a[pb];
				pe=(pe+1)%maxn;
				pb=(pb+1)%maxn;
			}
		}
		sort(ans,ans+t);
		for(i=0;i<t;i++) 
		{
				//	if(i) printf(" ");
			printf("%d\n",ans[i]+1);
		}
	
	//	printf("\n");
	}
	return 0;
}