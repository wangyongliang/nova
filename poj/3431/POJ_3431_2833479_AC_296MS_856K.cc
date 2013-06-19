#include<iostream>
using namespace std;
#define N 380
int a[N][N],x,y,n,f[N];
bool ok(int ans)
{
	int i,j,i2,j2,k;
	memset(f,0,sizeof(f));
		for (i=0;i<n&&ans<=n-i;i++)
			for (j=0;j<n&&ans<=n-j;j++)
			{
				if (f[j]>i)
					continue;
				j2=j+ans-1;
					if (a[i][j]==a[i][j2])
					{
						i2=j2-j+i;
						for (k=j;k<=j2;k++)
							if (a[i2][k]!=a[i][k])
								break;
						if (k>j2)
						{
							for (k=i+1;k<i2;k++)
								if (a[k][j2]!=a[k][j])
									break;
							if (k>=i2)
							{
								x=i+1;
								y=j+1;
								return 1;	
							}
							else
								f[j]=k+1;
						}
						else
							j=k;
					}
			}
	return 0;
}
int main()
{
	int i,j,ans;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				scanf("%d",a[i]+j);
		x=y=1;
		ans=n;
		while (!ok(ans))
			ans--;
		printf("%d %d %d\n",x,y,ans);
	}
	return 0;
}
