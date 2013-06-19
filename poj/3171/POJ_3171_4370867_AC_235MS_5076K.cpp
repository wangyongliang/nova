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
#define SP(x) setprecision(x)
using namespace std;
#define maxn 90399
long long inf=0x7ffffffffffLL;
struct node
{
    int min,max;
    long long ans;
}a[maxn*3];
void build(int min,int max,int k){
    a[k].min=min;
    a[k].max=max;
    a[k].ans=inf;
    if(min<max){
        int mid=(min+max)/2;
        build(min,mid,k*2);
        build(mid+1,max,k*2+1);
    }
}
long long find(int min,int max,int k){
  //  printf("%d %d %I64d\n",a[k].min,a[k].max,a[k].ans);
    if(min<=a[k].min&&max>=a[k].max) return a[k].ans;
    else{
        int mid=(a[k].min+a[k].max)/2;
        long long tp1,tp2;
        tp1=tp2=inf;
        if(min<=mid) tp1=find(min,max,k*2);
        if(max>mid)tp2=find(min,max,k*2+1);
     //   printf("%d %d %I64d %I64d\n",a[k].min,a[k].max,tp1,tp2);
        if(tp1<tp2) return tp1;
        else return tp2;        
    }
}
void insert(int i,int k,long long t){
    int mid=(a[k].min+a[k].max)/2;
    if(a[k].min==a[k].max) a[k].ans=MIN(a[k].ans,t);
    else{
        if(i<=mid)insert(i,k*2,t);
        else insert(i,k*2+1,t);
        a[k].ans=MIN(a[k*2].ans,a[k*2+1].ans);
    }
}
map<int,long long> mp;
struct Node
{
    int x,y,z;
}b[10100];
bool cmp(const Node x,const Node y){
    if(x.y==y.y) return x.y<y.y;
    else return x.x<y.x;
}
int  main()
{
    long long ans;
    int n,s,e,i;
    while(scanf("%d%d%d",&n,&s,&e)!=EOF){
        s++;
        e++;
        mp.clear();
        mp[e]=inf;
        for(i=0;i<n;i++) {
            scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
            b[i].x++;
            b[i].y++;
            mp[b[i].y]=inf;
        }
        sort(b,b+n,cmp);
        build(0,e,1);
        insert(s-1,1,0);
 //       printf("OK\n");
//for(i=0;i<n;i++) printf("%d %d\n",b[i].x,b[i].y);
//printf("---------\n");
        for(i=0;i<n;i++) {
            ans=find(b[i].x-1,b[i].y,1);
  //          printf("%d %I64d %d\n",b[i].y,ans,b[i].z);
            if(ans<inf) {
                ans+=b[i].z;
                if(mp[b[i].y]>ans){
                    mp[b[i].y]=ans;
    //                printf("%I64d\n",ans);
                    insert(b[i].y,1,ans);
      //              printf("%I64d\n",find(b[i].y,b[i].y,1));
                }
            }
        }
        if(mp[e]==inf) printf("-1\n");
        else        printf("%I64d\n",mp[e]);
    }
    system("pause");
    return 0;
}
