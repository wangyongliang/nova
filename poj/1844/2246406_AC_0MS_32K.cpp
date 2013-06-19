#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,sum;
	while(scanf("%d",&n)!=EOF)
	{
		i=(sqrt(1+8*n)-1)/2;
		sum=(i+1)*i/2;
		while(sum<n) sum+=++i;
		if((sum-n)%2==0) printf("%d\n",i);
		else printf("%d\n",i&1?i+2:i+1);
	}
	return 0;
}
