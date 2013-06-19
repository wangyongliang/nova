#include<stdio.h>
typedef __int64 int64;
void f(int64 n,int64 a[10])
{
	int i,j;
	int64 s;
	if(n<=0)
	{
		for(i=0;i<10;i++) a[i]=0;
		if(n==0) a[0]=1;
		return ;
	}
	s=n;
	a[0]=s/10+1;
	for(i=1;i<10;i++)
	{
		if(s%10>=i)
		{
			a[i]=s/10+1;
		}
		else
		{
			a[i]=s/10;
		}
	}
	s/=10;
	for(i=10;s;i*=10)
	{
		if(s%10)a[0]+=i*(s/10);
        else 
        {
            a[0]+=i*((s/10)-1);
            a[0]+=n%(i*10)+1;
        }
		for(j=1;j<10;j++)
		{
			if(s%10>j) 
			{
				a[j]+=i*(s/10+1);
			}
			else if(s%10==j)  
			{
				a[j]+=i*(s/10);
				a[j]+=n%i+1;
			}
			else
			{
				a[j]+=i*(s/10);
			}
		}
		s/=10;
	}
}
int main()
{
	int64 n,m,temp;
	int64 a[11], b[11];
	int i;
	while(scanf("%I64d%I64d",&n,&m)&&(n+m))
	{
		if(n>m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		f(m,a);
		f(n-1,b);
		printf("%I64d",a[0]-b[0]);
		for(i=1;i<=9;i++)
		{
			printf(" %I64d",a[i]-b[i]);
		}
		printf("\n");
	}
	return 0;
}

