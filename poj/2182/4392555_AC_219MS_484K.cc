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

struct node{
    int min,max;
    int ans;
    int col;
}a[10000*3];
/*
void build(int min,int max,int k){
    a[k].min=min;
    a[k].max=max;
    if(min==max) a[k].ans=b[min];
    else{
        int mid=(min+max)/2;
        build(min,mid,k*2);
        build(mid*2+1,max,k*2+1);
        a[k].min=MIN(a[k*2].min,a[k*2].max);
    }
}
*/
int b[10000];
int ans[10000];
int  main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)!=EOF){
        b[0]=0;
        for(i=1;i<n;i++) scanf("%d",&b[i]);
        for(i=1;i<=n;i++){
            for(j=n-1;j>=0;j--){
                if(b[j]==0) break;
            }
            ans[j]=i;
            for(;j<n;j++) b[j]--;
        }
        for(i=0;i<n;i++) printf("%d\n",ans[i]);
    }
    system("pause");
    return 0;
}

