#include <iostream>
using namespace std;

int a[110000];
int flag[100100];
int main()
{
	int c,m,n,i;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<n;i++) flag[i]=-1;
		int sum=0;
		flag[0]=0;
		for(i=0;i<m;i++)
		{
			int tp;
			scanf("%d",&tp);
			sum+=tp;
			sum%=n;
			if(flag[sum]>=0) break;
			else flag[sum]=i+1;
		}
		for(int j=flag[sum];j<=i;j++)
		{
			printf("%d ",j+1);
		}
		printf("\n");
		int tp;
		for(i++;i<m;i++) scanf("%d",&tp);
	}
	return 0;
}