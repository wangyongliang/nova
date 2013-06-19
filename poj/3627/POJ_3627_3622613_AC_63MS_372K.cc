#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000000];
int main()
{
	int n,b,i;
	while(scanf("%d%d",&n,&b)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=n-1;i>=0&&b>0;i--) b-=a[i];
		printf("%d\n",n-i-1);
	}
	return 0;
}