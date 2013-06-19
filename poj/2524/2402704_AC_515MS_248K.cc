#include<stdio.h>
int a[50002];

int main()
{
	int n,m,temp;
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
				father_p=p;
				while(a[father_p]!=0) father_p=a[father_p];
				while(father_p!=p){ temp=a[p];a[p]=father_p;p=temp;}
				father_q=q;
				while(a[father_q]!=0) father_q=a[father_q];
				while(father_q!=q){ temp=a[q];a[q]=father_q;q=temp;}
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
