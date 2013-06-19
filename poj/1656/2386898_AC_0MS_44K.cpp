#include<stdio.h>
int main()
{
	int a[101][101]={0},i,j;
	int x,y,l,n,sum;
	char str[20];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s %d %d %d",str,&x,&y,&l);
		if(str[0]=='B')
		{
			for(i=x;i<x+l&&i<101;i++)
			{
				for(j=y;j<y+l&&j<101;j++) a[i][j]=1;
			}
		}
		else if(str[0]=='W')
		{
			for(i=x;i<x+l&&i<101;i++)
			{
				for(j=y;j<y+l&&j<101;j++) a[i][j]=0;
			}
		}
		else
		{
			sum=0;
			for(i=x;i<x+l&&i<101;i++)
			{
				for(j=y;j<y+l&&j<101;j++) if(a[i][j]) sum++;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}