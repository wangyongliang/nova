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
#define MIN(x,y) (x)>(y)?(y):(x);
#define MAX(x,y) (x)<(y)?(y):(x);
#define ABS(x) (x)>0?(x):-(x);
#define maxn 1000000

using namespace std;
struct node
{
    int x,y;
};
vector<node> a[maxn];
int flag[maxn],dis[maxn];
int ans;
void f(int x)
{
    flag[x]=1;
    dis[x]=0;
    int max1=0,max2=0,i;
    for(i=0;i<a[x].size();i++)   {
        if(flag[a[x][i].x]==0)
        {
            f(a[x][i].x);
            int tp=dis[a[x][i].x]+a[x][i].y;
            if(tp>=max1){
                max2=max1;
                max1=tp;                
            }
            else if(tp>max2) max2=tp;
        }
    }
    ans=MAX(ans,max1+max2);
    dis[x]=max1;
}
int  main()
{
    int x,y;
    node tp;
    for(int i=0;i<maxn;i++) 
    {
        a[i].clear();
        flag[i]=0;
    }
    while(cin>>x>>y>>tp.y){
        tp.x=y;
        a[x].push_back(tp);
        tp.x=x;
        a[y].push_back(tp);
    }
    ans=0;
    f(1);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
