#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define ABS(x) (x)>0?(x):-(x)
using namespace std;
double eps=1e-6;
double radi[60];
int a[100];
int check(int i,int k)
{
    double rp=radi[k]-radi[i];
    while(rp<0.0) rp+=360;
    if(rp<178) return 1;
    else return 0;
}
int cut[60];
map<int,int> mp;
int  main()
{
    int i,j,k,l;
    int n,sum,ans,min;
    int flag=0;
    while(cin>>n&&n){
        mp.clear();
        if(flag) cout<<endl;
        flag++;
        for(i=0;i<n;i++) 
        {
            cin>>a[i];
     //       mp[a[i]]=0x7ffffff;
        }
        for(i=0;i<n;i++)
        {
            cut[i]=0;
            for(j=0;j<n;j++)
            {
                if(a[j]>a[i]) cut[i]+=a[j]-a[i];
            }
            mp[a[i]]=cut[i];
        }
        radi[0]=0;
        double ave=360.0/(double)n;
        for(i=1;i<n;i++) 
        {
            radi[i]=radi[i-1]+ave;
        //    cout<<radi[i]<<endl;
        }
        ans=0x7fffffff;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(check(k,i)&&check(j,k)&&check(i,j))
                    {
                        sum=a[i]+a[j]+a[k];
                        min=MIN(a[i],MIN(a[j],a[k]));
                        ans=MIN(ans,mp[min]);
                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    for(l=k+1;l<n;l++)
                    {
                        if(check(i,j)&&check(j,k)&&check(k,l)&&check(l,i)){
                        sum=a[i]+a[j]+a[k]+a[l];
                        min=MIN(a[i],MIN(a[j],MIN(a[l],a[k])));
                        ans=MIN(ans,mp[min]);
                    }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    
 //   system("pause");
    return 0;
}
