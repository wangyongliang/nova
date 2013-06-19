#include<stdio.h>
int b[10]= {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int a[10]={1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
int f(int n)
{
	int i,j,k;
	if(n<10) return b[n];
	i=f(n/5)*a[n%10]*6; 
	i%=10;
	j=n/5;
	if(j%4==0) j=4;
	else j=j%4;
	for(;j;j--)
	{
		if(i==2) i=6;
		else if (i==6)  i=8;
		else i/=2;
	}
	return i;
}
int g(int n,int k)
{
	int cnt=0;
	while(n)
	{
		cnt+=n/k;
		n/=k;
	}
	return cnt;
}
int main()
{
	int n,m,k;
	int n2,m2,k5,ln,lm,lk;
	int o1,o2;
	int i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		k=n-m;
		ln=f(n);
		lm=f(m);
		lk=f(k);
		o1=g(n,5);
		o2=g(m,5)+g(k,5);
		n2=g(n,2);
		m2=g(m,2)+g(k,2);
		if(n2-m2<o1-o2) 
		{
			printf("5\n");
			continue ;
		}
		if(n2-(o1-o2)==m2) i=1;
		else i=2;
		lm=(lm*lk)%10;
		for(;i<10;i+=2)
		{
			if((i*lm)%10==ln)  break;
		}
		printf("%d\n",i);
	}
	return 0;
}