#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#define SP(x) setprecision(x)
using namespace std;

#define maxn 1100

int cnt[maxn],flag[maxn];
long long dis[maxn];
int n;
queue<int> q;
struct node{
    int x,y;
};
vector<node> a[maxn];
int spfa(){
    int i,j;
    for(i=0;i<=n;i++) 
    {
        dis[i]=0x7fffffff;
        flag[i]=cnt[i]=0;
        cnt[i]=0;
    }
    flag[1]    =1;
    dis[1]=0;
    q.push(1);
    while(q.size()){
        int x=q.front();
        q.pop();
        if(cnt[x]>=n) return 0;
       // q.pop();
        flag[x]=0;
   //     printf("%d\n",a[x].size());
        
        for(i=0;i<a[x].size();i++){
     //       printf("%I64d %I64d\n",dis[a[x][i].x],dis[x]+a[x][i].y);
            if(dis[a[x][i].x]>dis[x]+a[x][i].y){
                dis[a[x][i].x]=dis[x]+a[x][i].y;
                cnt[a[x][i].x]++;
                if(flag[a[x][i].x]==0){
                    flag[a[x][i].x]=1;
                    q.push(a[x][i].x);
                }
            }
        }
    }
    return 1;    
}
int  main()
{
    int m1,m2,i,j,k;
    node tp;
    //printf("%d\n",0xfffffff);
    while(scanf("%d%d%d",&n,&m1,&m2)!=EOF){
        for(i=0;i<=n;i++) a[i].clear();
    /*    for(i=1;i<=n;i++){
            tp.x=i;
            tp.y=0;
            a[0].push_back(tp);
        } */
        while(m1--){
            scanf("%d %d %d",&i,&j,&tp.y);
        //    tp.y*=-1;
            tp.x=j;
    //        printf("%d\n",i);
            a[i].push_back(tp);
        }
    //    printf("---\n");
        while(m2--){
            scanf("%d%d%d",&i,&j,&tp.y);
            tp.y*=-1;
            tp.x=i;
            a[j].push_back(tp);
        }
        if(spfa()){
    //        for(i=1;i<=n;i++) printf("%d ",dis[i]);
        //    printf("\n");
            if(dis[n]==0x7fffffff) printf("-2\n");
            else printf("%I64d\n",dis[n]);
        }
        else printf("-1\n");
    }
    system("pause");
    return 0;
}
