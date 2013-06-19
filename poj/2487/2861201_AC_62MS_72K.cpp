#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10000];
int main()
{
	int t;
	int i,n,m;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=n-1;i>=0&&m>0;i--)
		{
			m-=a[i];
		}
		printf("Scenario #%d:\n",j);
		if(i==-1&&m>0) printf("impossible\n");
		else printf("%d\n",n-i-1);
		printf("\n");
	}
	return 0;
}