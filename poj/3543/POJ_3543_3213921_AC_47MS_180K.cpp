#include<stdio.h>
int main()
{
	int a,b,n;
	int tp1,tp2,tp;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0) 
		{
			printf("Impossible\n");
			continue;
		}
		for(n=1;;n++)
		{
			if(n%2==0)
			{
				tp=n/2;
				tp*=n;
				if(tp>a||tp>b) break;
			}
			else
			{
				tp1=(n/2+1)*(n/2+1)+(n/2)*(n/2);
				tp2=(n/2+1)*(n/2)*2;
				if((tp1<=a&&tp2<=b)||(tp1<=b&&tp2<=a)) continue;
				else break;
			}
		}
		printf("%d\n",n-1);
	}
	return 0;
}