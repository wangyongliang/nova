#include<stdio.h>
void main()
{
	int n,sum,i,k;
	while(scanf("%d",&n)!=EOF)
	{
		k=n;
		for(i=1;i*(i+1)/2<=n;i++);
		sum=i*(i-1)/2;
		n-=sum;
		if(n)
		{
			if(i&1) printf("TERM %d IS %d/%d\n",k,i+1-n,n);
			else n=i-n+1,printf("TERM %d IS %d/%d\n",k,i+1-n,n);
		}
		else
		{
			if(i&1) printf("TERM %d IS %d/%d\n",k,i-1,1);
			else n=i-n+1,printf("TERM %d IS %d/%d\n",k,1,i-1);
		}
	}
}