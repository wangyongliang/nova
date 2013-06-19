#include<stdio.h>
#include<math.h>
void fenxing(long y,int flag)
{
	int i;
	if(flag==0) 
	{
		for(i=0;i<y;i++) printf(" ");
		return ;
	}
	if(y==1) printf("-");
	else
	{
		fenxing(y/3,flag);
		fenxing(y/3,1-flag);
		fenxing(y/3,flag);
	}
}
int main()
{
	int n;
	long m;
	while(scanf("%d",&n)!=EOF)
	{
		m=(long)pow(3,n);
		fenxing(m,1);
		printf("\n");
	}
	return 0;
}