#include<stdio.h>
int main()
{
	int a[105],n,i,j,k,mod,b[105];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=0;i<k;i++) b[i]=a[i]=0;
		scanf("%d",&j);
		a[(j%k+k)%k]=1;
		while(--n)
		{
			scanf("%d",&j);
			for(i=0;i<k;i++)
			{
				if(a[i]&&!b[i])
				{
					a[i]=0;
					mod=i+j;
					if((mod%k+k)%k>i&&!a[(mod%k+k)%k])
						b[(mod%k+k)%k]=1;
					a[(mod%k+k)%k]=1;
					mod=i-j;
					if((mod%k+k)%k>i&&!a[(mod%k+k)%k])
						b[(mod%k+k)%k]=1;
					a[(mod%k+k)%k]=1;
			//		a[i]=0;
				}
				if(b[i]) b[i]=0;
			}
		}
		if(a[0]) printf("Divisible\n");
		else printf("Not divisible\n");
	}
	return 0;
}