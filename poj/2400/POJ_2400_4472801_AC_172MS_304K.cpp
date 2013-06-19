#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>

using namespace std;
#define maxn 15
int a[maxn][maxn],b[maxn][maxn];
int best,n;
vector<string> ans;
int flag[maxn];
int id[maxn];
void dfs(int deep,int cur)
{
	int i,j;
	if(cur>best) return;
	if(deep==n)
	{
		if(cur<best)
		{
			best=cur;
			ans.clear();
		}
		if(cur==best)
		{
	//		ans.clear();
			char s[100];
			for(j=i=0;i<n;i++){
				j+=sprintf(s+j,"%d ",id[i]+1);
			}
			string str;
			str=s;

		//	cout<<"strat"<<ans.size()<<endl;
			ans.push_back(str);
		//	cout<<ans.size()<<endl;
		//	cout<<str<<endl;
		}
	}
	else
	{
		//int i;
		for(i=0;i<n;i++)
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				id[deep]=i;
				dfs(deep+1,cur+a[deep][i]+b[i][deep]);
				flag[i]=0;
			}
		}
	}
}
int main()
{
	int i,j;
	int t;
	cin>>t;
	int cas=1;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) 
			{
				int x;
				cin>>x;
				x--;
				b[i][x]=j;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				int x;
				cin>>x;
				x--;
				a[i][x]=j;
			}
		}
		best=0x7ffffff;
		dfs(0,0);
		printf("Data Set %d, Best average difference: ",cas++);
		printf("%.6lf\n",best/2.0/n);
	//	cout<<ans.size()<<endl;
		for(i=0;i<ans.size();i++) 
		{
			cout<<"Best Pairing "<<i+1<<endl;
		//	cout<<ans[i]<<endl;
			istringstream scin(ans[i]);
			int bt=0;
			for(j=0;j<n;j++)
			{
				int k;
				scin>>k;
					printf("Supervisor %d with Employee %d\n",j+1,k);

			}
			//cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}