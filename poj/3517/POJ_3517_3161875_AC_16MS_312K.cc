#include<stdio.h>
int main()
{
	int n,m,k;
	int s,i;
	while(scanf("%d%d%d",&n,&m,&k)&&(n+m+k))
	{
		s=0;
		for(i=2;i<=n;i++)
		{
			s=(s+m)%i;
		}
		s++;
		m%=n;
		if(m==0) m=n;
		s=s+(k-m);
		s=(s%n+n)%n;
		if(!s) s=n;
		printf("%d\n",s);
	}
	return 0;
}