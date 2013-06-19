/*
ID: 05272021
LANG: C++
PROG:
*/
/*crackerwang*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define ABS(X)  (x)>0?(x):-(x)
#define ps system("pause")
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
double area[100010];
double pi;
int main()
{
	pi=acos(-1.0);
	int t;
//	printf("%lf\n",pi);
	scanf("%d",&t);
	int i;
	int n,f;
	while(t--)
	{
		scanf("%d%d",&n,&f);
		double min=0;
		double max=0.0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&area[i])			;
			area[i]=area[i]*area[i];
			if(max<area[i]) max=area[i];
		}
	//	for(i=0;i<n;i++) printf("%lf ",area[i]*pi);
	//	printf("\n");
		f++;
		min=max/(double)f;
	//	printf("%lf %lf\n",min,max);
		while(max-min>1e-6)
		{
			double mid=(min+max)/2.0;
			int sum=0;
			for(i=0;i<n;i++) sum+=(int)(area[i]/mid);
		//	printf("%lf %d\n",mid,sum);
			if(sum>=f) min=mid;
			else max=mid;
		}
		printf("%.4lf\n",min*pi);
		
	}
	return 0;
}
