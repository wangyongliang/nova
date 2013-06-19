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

long long a[100];
int heap[2000000];
int cnt;
int n,c;
void dfs(int cur,long long sum){
    
    if(sum>c)  return;
    if(cur==n) 
    {
        if(sum<c) heap[cnt++]=(int)sum;;
    }
    else{
        dfs(cur+1,sum);
        dfs(cur+1,sum+a[cur]);
    }
}
int find(int k){
    int min,max,mid;
    min=0;
    max=cnt;
    heap[cnt]=0x7fffffff;
    while(min<max){
        mid=(min+max+1)/2;
        if(heap[mid]<=k) min=mid;
        else max=mid-1;
    }
    return heap[min];
}
int main()
{

    int i,j;
    set<int> ::iterator it;
    int ans=0;
    while(cin>>n>>c){
    //    printf("%d\n",c);
        ans=0;
        for(i=0;i<n;i++) cin>>a[i];
        j=n/2;
        cnt=0;
        dfs(j,0);
        sort(heap,heap+cnt);
    //    for(i=0;i<cnt;i++) printf("%d ",heap[i]);
      //  printf("\n");
   //     system("pause");
        //printf("%d\n",heap.size());
     //   for(it=heap.begin();it!=heap.end();it++) printf("%d\n",*it);
        for(i=0;i<(1<<j);i++){
            long long tp=0;
            for(int k=0;k<j;k++){
                if(i&(1<<k)) tp+=a[k];
            }
            if(tp<=c) {
            //    printf("%d",c);
                int m=c-tp;
              //  printf("%d\n",m);
         //       printf("tp=%I64d c-tp=%I64d\n",tp,c-tp);
                m=find(m);
           //     printf("%d\n",m);
      //     printf("%I64d %d %d\n",tp,m,c-tp);
                ans=MAX(ans,tp+m);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

