//http://acm.pku.edu.cn/JudgeOnline/searchproblem?field=source&key=Ural+Collegiate+Programming+Contest+1998
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[ 250000];
int main()
{
	double ans;
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(n%2==0) printf("%.1lf\n",(double)((double)a[n/2]+(double)a[n/2+1])/2.0);
		else printf("%.1lf\n",(double)a[(n+1)/2]);
	}
	return 0;
}