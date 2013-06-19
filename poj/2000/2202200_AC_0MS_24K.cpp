#include<stdio.h>
void main()
{
	int n,i,j,sum,m;
//	scanf("%d",&n);
//	while(n)
//	{
		while(scanf("%d",&m))
		{
			if(!m)
			{
//				n--;
//				if(n)
//					printf("\n");
				break;
			}
			else
			{
				sum=0;
				for(i=1;i*(i+1)/2<=m;i++)
				{
					sum+=i*i;
				}
				i--;
				sum+=(m-(i+1)*i/2)*(i+1);
				printf("%d %d\n",m,sum);				
			}
		}
//	}
}