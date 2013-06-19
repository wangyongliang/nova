#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
double a[100000];
double b[1000][2];
double inf=1e-8;
int main()
{
	int n;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%lf%lf",&b[i][0],&b[i][1]);
		int k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j) continue;
				if(fabs(b[i][0]-b[j][0])<inf) a[k++]=1e9;
				else a[k++]=(b[i][1]-b[j][1])/(b[i][0]-b[j][0]);
			}
		}
		sort(a,a+k);
		int ans=1;
		for(i=1;i<k;i++)
		{
			if(fabs(a[i]-a[i-1])>inf) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
