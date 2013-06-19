#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 2000
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
vector<int> cnt;
int n;
void print()
{
	int i,j;
						for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
						printf("\n");
}
int main()
{
	int i,j,k;
	int x,y,xx,yy,xxx,yyy;
	int flag,t=1;
//	freopen("rings.in","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		flag=1;
		for(i=0;i*2<n;i++)
		{
			for(j=i;j+i<n;j++) 
			{
				a[i][j]=0;
				a[n-i-1][j]=1;
				a[j][i]=3;
				a[j][n-i-1]=2;
			}
		//	print();
			a[i][i]=0;
			a[i][n-i-1]=2;
			a[n-i-1][n-i-1]=1;
			a[n-i-1][i]=3;
		}
	//	print();
		k=1;
		cnt.clear();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				b[i][j]=k++;
				scanf("%d",&c[i][j]);
			//	cnt.push_back(c[i][j]);
			}
		}
	//	sort(cnt.begin(),cnt.end());
		for(i=0;i+i<n&&flag;i++)
		{
			if(i+i==n-1)
			{
				if(c[i][i]!=b[i][i])  flag=0;
				break;
			}
			x=i;
			y=i;
			cnt.clear();
			cnt.push_back(b[i][i]);
			xxx=yyy=-1;
			if(c[i][i]==b[i][i]) xxx=yyy=i;
			while(1)
			{
				xx=x+dx[a[x][y]];
				yy=y+dy[a[x][y]];
				if(c[xx][yy]==b[i][i]) 
				{
					xxx=xx;
					yyy=yy;
				}
				if(xx==i&&yy==i) break;
				cnt.push_back(b[xx][yy]);
				x=xx;
				y=yy;
			}
		//	for(i=0;i<cnt.size();i++) printf("%d ",cnt[i]);
		//	printf("\n");
			if(xxx==-1)
			{
				flag=0;
				break;
			}
			k=0;
			x=xxx;
			y=yyy;
			while(k<cnt.size())
			{
				if(c[x][y]==cnt[k]) k++;
				else
				{
					flag=0;
					break;
				}
				xx=x+dx[a[x][y]];
				yy=y+dy[a[x][y]];
				x=xx;
				y=yy;
			}
			if(k<cnt.size()) flag=0;
		}
		printf("%d. %s\n",t++,flag?"YES":"NO");
		//print();
		
	}
	return 0;
}
