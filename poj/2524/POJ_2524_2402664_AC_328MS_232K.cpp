#include<stdio.h>
int find(int n,int a[])
{
	int i,j;
	i=n;
	while(a[i]!=0)
	{
		i=a[i];
	}
	while(i!=n)
	{
		j=a[n];
		a[n]=i;
		n=j;
	}
	return i;
}
int fun(int n,int m)
{
	int a[50002]={0};
	int	sum=n,i;
	int father_p,father_q,p,q;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		if(p!=q)
		{
			father_p=find(p,a);
			father_q=find(q,a);
			if(father_p!=father_q)
			{
				sum--;
				a[father_q]=father_p;
			}
		}
	}
	return sum;
}
int main()
{
	int n,m,k=1;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		printf("Case %d: %d\n",k,fun(n,m));
		k++;
	}
	return 0;
}