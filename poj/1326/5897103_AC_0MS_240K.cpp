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

int main()
{
    string str1,str2;
    int n;
    string str3;
    while(cin>>str1)
    {
        if(str1=="#") break;
        else
        {
            int ans=0;
            
            
            do
            {
                
                if(str1=="0")
                {
                    break;
                }
                cin>>str2>>n>>str3;
                if(str3=="F") ans+=n*2;
                else if(str3=="B")
                {
                    ans+=n+n/2+n%2;
                }
                else
                {
                    if(n<=500) ans+=500;
                    else ans+=n;
                }
            }
            while(cin>>str1);
            cout<<ans<<endl;
            
        }
        
    }
    return 0;
}
