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

using namespace std;

#define maxn 100
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")
int dp[100][100];

int check(string str1,string str2)
{
    int i,j;
    bool flg=0;
    for(j=i=0;i<str1.size();i++)
    {
        if(str1[i]!=str2[j])        
        {
            if(flg==0) flg=1;
            else return 0;
            i--;
            j++;
        }
        else j++;
    }
    return 1;
}
string str[maxn*11];
bool cmp(string str1,string str2)
{
    if(str1.size()!=str2.size())
    {
        return  str1.size()<str2.size();
    }
    else return str1<str2;
}
bool flag[maxn*11];
int last[maxn*11];
int main()
{

    int n;
    int i,j;

   // cout<<check("cal","coal")<<endl;
    while(cin>>n)
    {
        cin>>str[0];
        flag[0]=0;
        for(i=1;i<=n;i++) 
        
        {
            cin>>str[i];
            flag[i]=0;
        }
        flag[0]=1;
        n++;
        sort(str+1,str+n,cmp);
        last[0]=0;
     //   cout<<"--------------"<<endl;
    //    for(i=0;i<n;i++) cout<<str[i]<<endl;
        for(i=0;i<n;i++)
        {
            if(flag[i])
            {
                for(j=i;j<n;j++)
                {
                    if(str[j].size()>str[i].size()+1) break;
                    if(str[j].size()==str[i].size()+1&&check(str[i],str[j])) flag[j]=1;
                }
            }
        }
        /*
        for(i=0;i<n;i++)
        {
            cout<<flag[i]<<endl;
        }
        */
        for(i=n-1;i>=0&&flag[i]==0;i--);
        cout<<str[i]<<endl;
    }
   // PS;
    return 0;
}
