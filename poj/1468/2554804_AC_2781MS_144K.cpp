#include<stdio.h>
#define maxn 5009
int a[maxn][4];
bool jud(int i,int j)
{
	if((a[j][0]>=a[i][0]&&a[j][1]<=a[i][1])&&(a[j][2]>=a[i][2]&&a[j][3]<=a[i][3])) return 1;
	else return 0;
}
int main()
{
	int n;
	int i,j,ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j) continue;
				if(jud(j,i))
				{
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}