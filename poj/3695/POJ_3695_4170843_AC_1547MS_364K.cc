#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int sum[4100],cnt;
struct node
{
	int x1,y1,x2,y2;
}a[201];
vector<int> ans[201];
int flag[4100];
int main()
{
	int n,m,i,j,k=1,l;
	int b[42],c[42];
	int ct=1;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(j=i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
			b[i*2]=a[i].x1;
			b[i*2+1]=a[i].x2;
			c[i*2]=a[i].y1;
			c[i*2+1]=a[i].y2;
			ans[i].clear();
		}
		sort(b,b+n*2);
		sort(c,c+n*2);
		cnt=0;
		for(i=0;i+1<n*2;i++)
		{
			for(j=0;j+1<n*2;j++)
			{
				sum[cnt]=(b[i+1]-b[i])*(c[j+1]-c[j]);
				if(sum[cnt])
				{
					flag[cnt]=0;
					for(l=0;l<n;l++)
					{
						if(b[i]>=a[l].x1&&b[i+1]<=a[l].x2&&c[j]>=a[l].y1&&c[j+1]<=a[l].y2)
						{
							ans[l].push_back(cnt);
						}
					}
					cnt++;
				}
			}
		}
	//	for(i=0;i<n;i++)
	//	{
	//		printf("%d\n",ans[i].size());
	//	}
		printf("Case %d:\n",k++);
		for(int kk=1;kk<=m;kk++,ct++)
		{
			int res=0;
			scanf("%d",&i);
			while(i--)
			{
				scanf("%d",&l);
				l--;
				for(j=0;j<ans[l].size();j++)
				{
						int tp=ans[l][j];
					if(flag[ans[l][j]]!=ct)
					{
						int tp=ans[l][j];
						res+=sum[ans[l][j]];
						flag[ans[l][j]]=ct;
					}
				}
			}
			printf("Query %d: %d\n",kk,res);
		}
		printf("\n");

	}
	return 0;
}