#include<stdio.h>
int a[300];
struct node
{
	int x,y;
	int a,b;
}b[10][300];
void f(int deep,int k)
{
	int i,j;
	if(k>1)
	{
		f(deep+1,k/2);
	}
	if(k==1)
	{
		b[deep][0].x=(b[deep][0].b+a[0])/2;
		b[deep][0].y=(a[0]-b[deep][0].b)/2;
		b[deep-1][0].a=b[deep][0].x;
		b[deep-1][1].a=b[deep][0].y;
	}
	else
	{
		for(i=0;i<k;i++)
		{
		b[deep][i].x=(b[deep][i].b+b[deep][i].a)/2;
		b[deep][i].y=(b[deep][i].a-b[deep][i].b)/2;
		b[deep-1][i*2].a=b[deep][i].x;
		b[deep-1][i*2+1].a=b[deep][i].y;
		}
	}
}
int main()
{
	int n,i,j,k,l;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		if(n==1)
		{
			printf("%d\n",a[0]);
			continue;
		}
		for(k=n,i=1;k>=1;k/=2,i++)
		{
			for(l=0,j=k/2;l<k/2;l++,j++)
			{
				b[i][l].b=a[j];
			}
		}
		k=n;
		f(1,k/2);
		printf("%d %d",b[1][0].x,b[1][0].y);
		for(i=1;i<n/2;i++)
		{
			printf(" %d %d",b[1][i].x,b[1][i].y);
		}
		printf("\n");
	}
	return 0;
}