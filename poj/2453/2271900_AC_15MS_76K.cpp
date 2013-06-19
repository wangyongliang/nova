#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,k,a,b;
	char s[32];
	while(scanf("%d",&n)&&n)
	{
		i=k=0;
		a=n%2;
		if(a) k++;
		n/=2;
		i++;
		while(1)
		{
			b=n%2;
			n/=2;
			i++;
			if(b) k++;
			if(!b&&k)
			{
				
				n=n*2+1;
			    n*=pow(2,i-1);
				n+=pow(2,k-1)-1;
				break;
			}
		}
		printf("%d\n",n);
	}
return 0;
}