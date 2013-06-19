#include<stdio.h>
int a[14],b[14],n;
void dfs(int deep,int x)
{
	int i,flag=0;
	if(deep==6)
	{
		for(i=0;!b[i];i++);
		printf("%d",a[i]);
		for(i++;i<n;i++) 
		{
			if(b[i]) 
				printf(" %d",a[i]);
		
		}	printf("\n");
			return ;
	}
	for(i=x;i<n;i++)
	{
		b[i]=1;
		dfs(deep+1,i+1);
		b[i]=0;
	}
}
int main()
{
	int i,j,flag=1;
	while(scanf("%d",&n)&&n)
	{
		if(flag) flag--;
		else printf("\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",a+i);
			b[i]=0;
		}
		dfs(0,0);
	}
	return 0;
}	