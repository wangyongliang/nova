#include<stdio.h>
typedef __int64 int64;
bool flag[50009]={0};
int main()
{
	int64 n,m,sum;
	int i,j,k;
	while(scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		if(n==-1&&m==-1) break ;
		k=1;
		for(i=1;i<n;i++)
		{
			sum=(n-i)*(n-i-1)/2;
			if(sum>=m)
			{
				for(;flag[k];k++);
				printf("%d ",k);
				flag[k]=1;
			}
			else
			{
				m=m-sum;
				for(j=k;j<=n;j++)
				{
					if(flag[j]==0) m--;
					if(m==0) break;
				}
				for(j++;flag[j];j++);
				printf("%d ",j);
				flag[j]=1;
				i++;
				break;
			}
		}
		if(i<n)
		{
			for(j=n;j>=1&&i<n;j--) 
			{
				if(!flag[j])
				{
					printf("%d ",j);
					flag[j]=1;
					i++;
				}
				flag[j]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				printf("%d\n",i);
				break;
			}
			flag[i]=0;
		}
	}
	return 0;
}
