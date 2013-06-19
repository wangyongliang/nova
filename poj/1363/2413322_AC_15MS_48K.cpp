#include<stdio.h>
int a[1009];
int b[1009];
int main()
{
	int i,j,k,n,flag=0;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		if(flag) printf("\n");
		while(1)
		{
			scanf("%d",&b[1]);
			if(b[1]==0) break;
			else 
			{
				for(i=2;i<=n;i++) scanf("%d",&b[i]);
				j=1;
				k=1;
				a[1]=1;
				for(i=1;i<=n;)
				{
					if(k>n) break;
					if(a[j]==b[i])
					{
						i++;
						if(j>1)j--;
						else j=0;
					}
					else	a[++j]=++k;
				}
				if(i>n) printf("Yes\n");
				else printf("No\n");
			}
		}
		flag=1;
	}
	return 0;
}