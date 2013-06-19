#include<stdio.h>
int re(int n)
{
	int m=0;
	for(;n;)
	{
		m=n%10+m*10;
		n/=10;
	}
	return m;
}
int main()
{
	int n,m,sum,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m); 
		n=re(n);
	m=re(m);
	printf("%d\n",re(n+m));
	}
	return 0;

}