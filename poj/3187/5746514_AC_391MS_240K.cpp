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

#define maxn 100010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

int a[10];

int c[10][10];
int main()
{
    int n,m;
    int i,j;
    int tmp[10];
    for(i=0;i<10;i++)
    {
        c[i][0]=1;
        for(j=1;j<=i;j++)
        {
         //   cout<<i<<" "<<j<<endl;
        //    PS;
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }

    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)
        {
             a[i]=i;
             tmp[i]=10;
          //   cout<<c[n-1][i]<<" ";
            }
          //  cout<<endl;
            
        do
        
        {
            int cnt=0;
            for(i=0;i<n;i++) cnt+=c[n-1][i]*(a[i]+1);
            if(cnt==m) 
            {
                for(i=0;i<n;i++)
                {
                    if(tmp[i]>a[i]) break;
                    if(tmp[i]<a[i])
                    {
                        i=n;
                    }
                    
                }
                if(i<n)
                {
               //     printf("----------\n");
                    for(i=0;i<n;i++) 
                    {
                        tmp[i]=a[i];
                //        cout<<a[i]+1<<endl;
                    }
                }
            }
            
        }
        while(next_permutation(a,a+n));
        for(i=0;i<n;i++)
        {
            if(i)cout<<" ";
             cout<<tmp[i]+1;
        }
        cout<<endl;
    }
    return 0;
}
