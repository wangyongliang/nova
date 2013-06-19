#include<stdio.h>
int a[50002];
int find(int n)
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
int main()
{
	int n,m;
	int i,j,k=1;
	int p,q,sum;
	int father_p,father_q;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=1;i<=n;i++) a[i]=0;
		sum=n;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&p,&q);
			if(p!=q)
			{
				father_p=find(p);
				father_q=find(q);
				if(father_p!=father_q)
				{
					sum--;
					a[father_q]=father_p;
				}
			}
		}
		printf("Case %d: %d\n",k,sum);
		k++;
	}
	return 0;
}