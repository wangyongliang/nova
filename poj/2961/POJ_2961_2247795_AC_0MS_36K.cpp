#include<stdio.h>
int a[30][30];
__int64 n,x,y;
int w,h,i,j,t;
void print(__int64 xx,__int64 yy,__int64 n,int flag)
{
	if(n==1) 
	{
		if(xx>=x&&xx<x+w&&yy>=y&&yy<y+h)
			a[xx-x][yy-y]=flag;
	}
	else
	{
		if(!(xx+n/2<x||yy+n/2<y||xx>x+w||yy>y+h))
			print(xx,yy,n/2,flag);
		if(!(xx+n<x||yy+n/2<y||xx+n/2>x+w||yy>y+h))
			print(xx+n/2,yy,n/2,flag);
		if(!(xx+n/2<x||yy+n<y||xx>x+w||yy+n/2>y+h))
			print(xx,yy+n/2,n/2,flag);
		if(!(xx+n<x||yy+n<y||xx+n/2>x+w||yy+n/2>y+h))
			print(xx+n/2,yy+n/2,n/2,-1*flag);
	}
	
}
int main()
{

	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d%d%d",&n,&y,&x,&h,&w);
		print(0,0,n,1);
		for(i=0;i<w;i++)
		{
			for(j=0;j<h;j++)
			{
				printf("%d",a[i][j]);
				if(j<h-1) printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}