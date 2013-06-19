#include<stdio.h>
int main()
{
	int n;
	int i;
	int j;
	int cnt;
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;
		n*=2;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				j=n/i-i+1;
				if(j%2==0) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}