#include<stdio.h>
#include<math.h>
char a[740][740];
void print(int x,int y,int n)
{
	long i;
	if(n==1) a[x][y]='X';
	else
	{
		i=pow(3,n-2);
		print(x,y,n-1);
		print(x+2*i,y,n-1);
		print(x+i,y+i,n-1);
		print(x,y+2*i,n-1);
		print(x+2*i,y+2*i,n-1);
	}
}
void main()
{
	int n,i,j;
	print(0,0,7);
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		for(i=0;i<pow(3,n-1);i++)
		{
			for(j=0;j<pow(3,n-1);j++)
			{
				if(a[i][j]=='X')
					printf("X");
				else
					printf(" ");
			}
			printf("\n");
		}
		printf("-\n");
	}

}