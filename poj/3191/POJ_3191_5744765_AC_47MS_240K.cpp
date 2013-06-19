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
#define ABS(X) ((X)>=0?(X):-(X))
long long bit[64];


int main()
{

    int i,j;
    bit[0]=1;
    for(i=1;i<64;i++) bit[i]=bit[i-1]*2;
    long long  n;
    bool flag[100];
    while(cin>>n)
    {
        for(i=0;i<100;i++) flag[i]=0;
        if(n>0){
        for(i=0;n!=0;i++)        
        {
            if(ABS(n)%2)
            {
                flag[i]=1;                
                if(i%2) n+=2;
                else n-=1;
            }
            else flag[i]=0;
            n/=2;
        }
    }
    else if(n<0)
    {
        
        for(i=0;n!=0;i++)        
        {
            if(ABS(n)%2)
            {
                flag[i]=1;                
                if(i%2) n+=1;
                else n-=1;
            }
            else flag[i]=0;
            n/=2;
        }
    }
    else 
    {
        flag[0]=0;
        i=1;
    }
        for(i--;i>=0;i--) cout<<flag[i];
        cout<<endl;
    }
    return 0;
}
