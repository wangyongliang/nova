

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<time.h>

using namespace std;

#define maxn 100010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")
int a[20];
int n;
int max_deep;
bool flag[2100]={0};


int dp[2100];
int dfs(int deep)
{
    if(deep==max_deep) return 0;
    if(a[deep]==n) return 1;
	if(dp[a[deep]]<deep) return 0;
	else dp[a[deep]]=deep;



	
	int b[14];
	int i;
	for(i=0;i<=deep;i++) b[i]=a[i];
	sort(b,b+deep);
	if(b[deep]>2*n) return 0;
	if(b[deep]*(1<<(max_deep-deep))<n) return 0;
    for(i=deep;i>=0;i--)
    {
        
        a[deep+1]=b[i]+b[deep];
        

        if(flag[a[deep+1]]==0&&b[deep]<n)
        {
            flag[a[deep+1]]=1;
            if(dfs(deep+1)) return 1;
            flag[a[deep+1]]=0;
        }
        
        if(b[deep]>b[i])        
        {
            a[deep+1]=b[deep]-b[i];
			if(flag[a[deep+1]]==0)
			{
				flag[a[deep+1]]=1;
				if(dfs(deep+1)) return 1;
				flag[a[deep+1]]=0;
			}
        }        
    }
    return 0;
}

int main()
{
    int i,j;
    for(i=1;i<1100;i++) 
	{
		dp[i]=0;
		for(j=0;(1<<j)<=i;j++)
		{
			if((1<<j)&i) dp[i]++;
		}
		dp[i]+=i;
		if(dp[i]>16) dp[i]=16;
		flag[i]=0;
	}
    flag[0]=1;
	for(i=0;i<20;i++) a[i]=0;
	/*
	for(i=1;i<=1000;i++)
	{
		n=i;
       // for(j=0;j<1100;j++) flag[j]=0;
        flag[0]=1;

		a[0]=1;
		flag[1]=1;
		for(max_deep=0;max_deep<=dp[i];max_deep++) 
		{
			if(dfs(0)) 
			{
				dp[i]=max_deep;
				for(j=0;j<max_deep;j++) flag[a[j]]=0;
				break;
			}
		}
		cout<<i<<endl;
	}
	cout<<dp[811]<<endl;
	*/
    while(cin>>n)
    {
        if(n==0) break;

        max_deep=13;
        a[0]=1;
        int st=clock();
        for(i=0;i<1100;i++) flag[i]=0;
        flag[0]=1;
        for(max_deep=0;max_deep<=dp[n];max_deep++)        
        {
			if(max_deep==dp[n]) continue;
			//   if(max_deep==13) break;
			
     //       cout<<"max_deep :"<<max_deep<<endl;

            if(dfs(0)) break;
            
            
        }
      //  for(i=0;i<max_deep;i++) cout<<a[i]<<" ";
       // cout<<endl;
        cout<<max_deep-1<<endl;

        int en=clock();
        dp[n]=max_deep-1;
      //  cout<<"time is:"<<en-st<<endl;

    }
    return 0;
}
