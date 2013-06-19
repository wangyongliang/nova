#include<stdio.h>
int a[10009];
int f1(int x,int y)
{
	int i=y;
	while(x!=i&&a[i])
	{
		i=a[i];
		if(i==x) return 1;
	}
	return 0;
}
int f2(int x,int y)
{
	int i;
	if(f1(x,y)) return x;
	else
	{
		i=x;
		while(1)
		{
			if(a[i]==0) return i;
			i=a[i];
			if(f1(i,y)) return i;
		}
	}
}

int main()
{
	int i,t,n,q,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&q);
			a[q]=j;
		}
		scanf("%d%d",&i,&j);
		printf("%d\n",f2(i,j));
	}
	return 0;
}
