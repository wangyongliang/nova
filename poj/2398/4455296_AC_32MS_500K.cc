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

#define maxn 1010
struct node
{
    int x,y;
}b[maxn];

struct card
{
    node p1,p2;
}p[maxn];

bool cmp(const card x ,const card y){
    return MIN(x.p1.x,x.p2.x)<MIN(y.p1.x,y.p2.x);
}

bool flag[maxn];
bool cp(const node &x,const node &y){
    return x.x<y.x;
}
int cross(node point,card line){
    int dx1=line.p2.x-line.p1.x;
    int dy1=line.p2.y-line.p1.y;
    int dx2=point.x-line.p1.x;
    int dy2=point.y-line.p1.y;
 //   cout<<"---------------"<<endl;
 //   cout<<dx1*dy2-dx2*dy1<<endl;
    return dx1*dy2-dx2*dy1;
}
int ans[maxn];
int  main()
{
    int n,m,x1,y1,x2,y2;
    int i,j;
    while(cin>>n)
    {
        if(n==0) break;
        cin>>m>>x1>>y1>>x2>>y2;
        for(i=0;i<n;i++){
            cin>>p[i].p1.x>>p[i].p2.x;
            p[i].p1.y=y1;
            p[i].p2.y=y2;
            if(p[i].p1.y>p[i].p2.y) swap(p[i].p1,p[i].p2);
            
        }
        p[n].p1.x=x2;
        p[n].p1.y=y2;
        p[n].p2.x=x2;
        p[n].p2.y=y1;
        sort(p,p+n+1,cmp);
     /*   for(i=0;i<=n;i++){            
            cout<<p[i].p1.x<<"  "<<p[i].p2.x<<endl;
        }*/
   //     cout<<"OK"<<endl;
        ans[0]=0;
        for(i=0;i<m;i++){
            ans[i+1]=0;
             cin>>b[i].x>>b[i].y;
             flag[i]=1;
        }
        sort(b,b+m,cp);
        j=0;
        for(i=0;i<=n;i++)
        {
            int cnt=0;
            for(;j<m;j++){
                if(b[j].x>=MIN(p[i].p1.x,p[i].p2.x)) break;
                if(flag[j])
                {
                    flag[j]=1;
                    cnt++;
                }
            }
            for(int k=j;k<m&&b[k].x<=MAX(p[i].p1.x,p[i].p2.x);k++)
            {
                if(flag[k]&&cross(b[k],p[i])>=0) 
                {
                    cnt++;
                    flag[k]=0;
                }
            }            
           ans[cnt]++;
        }
        cout<<"Box"<<endl;
        for(i=1;i<=n;i++){
            if(ans[i]>0) cout<<i<<": "<<ans[i]<<endl;
        }
//        for(i=0;i<=n;i++) cout<<ans[i]<<endl;

    }
    system("pause");
    return 0;
}
