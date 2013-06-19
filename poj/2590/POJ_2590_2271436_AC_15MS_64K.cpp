#include<stdio.h>
#include<math.h>
int main()
{
	long x,y,n,k;
	double i;
	scanf("%ld",&k);
	while(k--)
	{ 
		scanf("%ld%ld",&x,&y);
		x=y-x;
		if(x==0) 
		{
			printf("0\n");
			continue;
		}
		i=x;
		n=(long)sqrt(i)+1;
		while(n*(n+1)>x) n--;
		x=x-n*(n+1);
		if(x>n+1) printf("%ld\n",2*n+2);
		else if(x==0) printf("%ld\n",n*2);
		else
			printf("%ld\n",2*n+1);

	}
	return 0;
}