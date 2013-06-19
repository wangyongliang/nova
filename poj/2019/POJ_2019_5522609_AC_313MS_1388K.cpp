#include<iostream>
using namespace std;
#define MIN(x,y) (x)<(y)?(x):(y)
#define MAX(x,y) (x)>(y)?(x):(y)
int a[300][300];
int ans[300][300];
int Min[300][300];
int Max[300][300];
int dp[300][300];
int q[300];
int main()
{
	int i,j;
	int n,b,k;
	int m;
	int st,en;
	while(cin>>n>>b>>m)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) cin>>a[i][j];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				Max[i][j]=Min[i][j]=a[i][j];
				for(k=0;k<b&&k+i<n;k++) 
				{
					Min[i][j]=MIN(Min[i][j],a[i+k][j]);
					Max[i][j]=MAX(Max[i][j],a[i+k][j]);

				}
			}
		}
/*		cout<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) cout<<Min[i][j]<<" ";
			cout<<endl;
		}
		*/
		for(i=0;i<n;i++)		
		{
			st=en=0;
			
			for(j=0;j<n;j++)
			{
				while(en>st&&Min[i][q[en-1]]>Min[i][j]) en--;
				q[en++]=j;
				while(q[st]<=j-b) st++;
				ans[i][j]=Min[i][q[st]];
				
			}
		}

		/*		cout<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) cout<<Max[i][j]<<" ";
			cout<<endl;
		}
		*/

		for(i=0;i<n;i++)		
		{
			st=en=0;
			
			for(j=0;j<n;j++)
			{
				while(en>st&&Max[i][q[en-1]]<Max[i][j]) en--;
				q[en++]=j;
				while(q[st]<=j-b) st++;
				dp[i][j]=Max[i][q[st]];
				
			}
		}
		while(m--)
		{
			int x,y;
			cin>>x>>y;
			x--;
			y--;
			printf("%d\n",dp[x][y+b-1]-ans[x][y+b-1]);
		}
		
	}
	return 0;
}
