#include<stdio.h>
bool flag[3012600]={0};
int a[500009];
int main()
{
	int i,j;
	a[0]=0;
	flag[0]=1;
	for(i=1;i<=500000;i++)
	{
		j=a[i-1]-i;
		if(j>0)
		{
			if(!flag[j])
			{
				a[i]=j;
				flag[j]=1;
			}
			else
			{
				a[i]=a[i-1]+i;
				flag[a[i]]=1;
			}
		}
		else
		{
			a[i]=a[i-1]+i;
			flag[a[i]]=1;
		}
	}
	while(scanf("%d",&i)&&i!=-1)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
