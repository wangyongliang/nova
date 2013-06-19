#include<stdio.h>
#include<math.h>
int a[32],n;
double sum;
double jie(double k)
{
	double i=1;
	if(k==0)return 1;
	else
	{
		while(k>0)
		{
			i*=k;
			k--;
		}
		return i;
	}
}
void jisuan()
{
	int i;
	double l=0,k=1,j=1;
	for(i=n;i>0;i-=2)
	{
		if(a[i])
		{
			k*=jie(a[i]);
			l+=a[i];
			j*=pow(2,a[i]);
		}
	}
	j/=pow(2,a[2]);
	j*=pow(3,a[2]);
	l=jie(l);
	l*=j;
	l/=k;
	sum+=l;
} 
void com(int k,int l)
{
	int i;
	if(k==n+2||l==n)
	{
	if(l==n)
	{
		jisuan();
	}
		
	}

	else
	{
		for(i=0;i*k+l<=n;i++)
		{
			a[k]=i;
			com(k+2,l+i*k);
			a[k]-=i;
		}
	}
}
void main()
{
	int i;
	while(scanf("%d",&n)&&n!=-1)
	{
		if(n%2==1)printf("0\n");
		else
		{
			for(i=0;i<=31;i+=2)
				a[i]=0;
			sum=0;
			com(2,0);
			printf("%.0lf\n",sum);
		}
	}
}