#include<stdio.h>
__int64 ans[110][110],a[110][110],c[110][110];
int n,m;
int main()
{
	int z,x,i,j,nn,mm,k;
	scanf("%d",&z);
	while(z--)
	{
		scanf("%d",&x);
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) scanf("%I64d",&ans[i][j]);
		}
		while(--x)
		{
			scanf("%d %d",&nn,&mm);
			for(i=0;i<nn;i++)
			{
				for(j=0;j<mm;j++) scanf("%I64d",&a[i][j]);
			}
			__int64 temp;
			for(i=0;i<n;i++)
			{
				for(j=0;j<mm;j++)
				{
					temp=0;
					for(k=0;k<m;k++)
						temp+=ans[i][k]*a[k][j];
					c[i][j]=temp;
				}
			}
			m=mm;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++) ans[i][j]=c[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(j) printf(" %I64d",ans[i][j]);
				else printf("%I64d",ans[i][j]);
			}
			printf("\n");
		}
		if(z) printf("\n");
	}
	return 0;
}