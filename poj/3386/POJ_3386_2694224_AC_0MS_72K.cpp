#include<stdio.h>
int main()
{
	int A,a,B,b,P;
	int temp;
	while(scanf("%d%d%d%d%d",&A,&a,&B,&b,&P)!=EOF)
	{
		if(A>B)
		{
			temp=A;
			A=B;
			B=temp;
			temp=a;
			a=b;
			b=temp;
		}
		if(B>P)
		{
			printf("No\n");
			continue ;
		}
		if(b>=A) printf("Yes\n");
		else
		{
			if(A+B<=P) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}