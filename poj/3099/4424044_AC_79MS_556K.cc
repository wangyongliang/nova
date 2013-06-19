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
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)>0?(x):-(x))
#define SP(x) setprecision(x)
using namespace std;
#define maxn 1100
int x[maxn],y[maxn],z[maxn];
int id[maxn],cnt[maxn];
vector<int> a[maxn];
int ans[maxn];
void dfs(int x){
    int i;
    for(i=0;i<a[x].size();i++){
        if(ans[a[x][i]]==0x7fffffff) {
            ans[a[x][i]]=ans[x]+1;
            dfs(a[x][i]);
        }
    }
}
int dis(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
}
int tp[maxn];
vector<int> b;
int  main()
{
    int n;
    int i,j;
    while(cin>>n&&n){
        for(i=0;i<n;i++) a[i].clear();
        for(i=0;i<n;i++) cin>>id[i]>>x[i]>>y[i]>>z[i];
        a[0].push_back(1);
    a[1].push_back(0);
    for(i=2;i<n;i++){
        int min=0;
        for(j=1;j<i;j++){
            if(dis(min,i)>dis(i,j)) min=j;
        }
        a[min].push_back(i);
        a[i].push_back(min);
    }
  //  for(i=0;i<n;i++){
      ///  cout<< a[i].size()<<":";
      //  for(j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";
    //    cout<<endl;
   // }
    for(i=0;i<n;i++)    {
        for(j=0;j<n;j++) ans[j]=0x7fffffff;
        ans[i]=0;
        dfs(i);
        tp[i]=0;
        for(j=0;j<n;j++) {
            tp[i]=MAX(tp[i],ans[j]);
       //     cout<<ans[j]<<" ";
        }
    //    cout<<"I"<<tp[i]<<endl;
        
    }
    j=0;
  //  cout<<"OK"<<endl;
    for(i=0;i<n;i++){
        if(tp[j]>tp[i]) j=i;
    }
    int flag=0;
  //  cout<<tp[j]<<endl;
  b.clear();
    for(i=0;i<n;i++){
        if(tp[i]==tp[j]){
         //   if(flag) cout<<" ";
         //   else flag=1;
         //   cout<<id[i];
         b.push_back(id[i]);
        }
    }
    sort(b.begin(),b.end());
    for(i=0;i<b.size();i++) cout<<b[i]<<" ";
    cout<<endl;
}
    system("pause");
    return 0;
}
 
