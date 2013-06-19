#include<stdio.h>
long a[21][21][21];
long w(int n,int m,int p)
{
	if(n<=0||m<=0||p<=0) return 1;
	else if(n>20||m>20||p>20) return w(20,20,20);
	else if(n<m&&m<p)
	{
		if(a[n][m][p]!=-100) return a[n][m][p];
		else
			a[n][m][p]=w(n,m,p-1) + w(n, m-1, p-1) - w(n, m-1, p);
	}
	else 
	{
		if(a[n][m][p]!=-100) return a[n][m][p];
		else 
			a[n][m][p]=w(n-1, m, p) + w(n-1, m-1, p) + w(n-1, m, p-1) - w(n-1, m-1, p-1);
	}
	return a[n][m][p];
}
int main()
{
	int n,m,p;
	while(1)
	{
		for(n=0;n<=20;n++)
		{
			for(m=0;m<=20;m++)
			{
				for(p=0;p<=20;p++) a[n][m][p]=-100;
			}
		}
		scanf("%d%d%d",&n,&m,&p);
		if(n==-1&&m==-1&&p==-1) break;
		printf("w(%d,%d,%d)=%ld\n",n,m,p,w(n,m,p));
	}
}