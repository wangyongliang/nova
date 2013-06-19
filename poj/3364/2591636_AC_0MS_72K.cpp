#include<stdio.h>
long f(int n,int m)
{
	if(n<8||m<8) return 0;
	int i,j;
	i=(n-8)/2+1;
	j=(m-8)/2+1;
	return i*j;
}
int main()
{
	int n,m,c;
	int a1,b1,a2,b2;
	__int64 ans;
	while(1)
	{
		scanf("%d%d%d",&n,&m,&c);
		if(n==0&&m==0&&c==0) break;
		if(n<8||m<8) printf("0\n");
		else
		{
			if(c==0) 
			{
				ans=f(n-1,m)+f(n,m-1);
				printf("%I64d\n",ans);
			}
			else printf("%ld\n",f(n,m)+f(n-1,m-1));
		}
	}
	return 0;
}
