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
#define maxn 1010
int flag[maxn],d[maxn];
int a[maxn];
int b[maxn];
int  main()
{
    int n,m,i,j;
    char s[10];
    int sum=0;
    int t=1;
    while(scanf("%d",&n)!=EOF){
        if(n==-1) break;
        sum=m=0;
        for(i=0;i<maxn;i++) flag[i]=0;
        while(scanf("%s",s)){
            if(s[0]=='E') break;
            if(s[0]=='R'){
                int x;
                scanf("%d",&x);
                if(flag[x]){
                    for(i=0;i<m;i++) if(b[i]==x) break;
                    for(;i<m;i++) b[i]=b[i+1];
                    m--;
                    sum-=a[x];
                    flag[x]=0;
                }
            }
            else{
                int x;
                scanf("%d",&x);
                scanf("%d",&a[x]);
           //     printf("%d %d\n",x,a[x]);
                for(i=m;i>0;i--) b[i]=b[i-1];
                b[0]=x;
                flag[x]=1;
                sum+=a[x];
                m++;
         //       printf("%d %d\n",sum,m);
                while(sum>n){
                    sum-=a[b[m-1]];
                    flag[b[m-1]]=0;
                    m--;
                }
             //   printf("check is :%d %d\n",sum,m);
            }
        }
        printf("PROBLEM %d:",t++);
        for(i=0;i<m;i++) printf(" %d",b[i]);
        printf("\n");
    }
    system("pause");
    return 0;
}

