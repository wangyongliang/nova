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
int main()
{
	int a[100];
	int n;
	int i;
	int sum;
	while(scanf("%d",&n)&&n)
	{
		sum=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%2) printf("No equal partitioning.\n");
		else
		{
			int cnt=0;
			for(i=0;i<n;i++) 
			{
				cnt+=a[i];
				if(cnt*2==sum) break;
			}
			if(cnt*2==sum) printf("Sam stops at position %d and Ella stops at position %d.\n",i+1,i+2);
			else printf("No equal partitioning.\n");
		}
	}
	ps;
	return 0;
}
