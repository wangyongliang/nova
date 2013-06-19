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
double eps =1e-6;
#define maxn 2000
int a[maxn][maxn];
double x[maxn],y[maxn];


using namespace std;
int d[maxn];
int  main()
{
    double l,s;
    int i,j,k;
    for(i=0;i<maxn;i++)
    {
        for(j=0;j<maxn;j++)
        { a[i][j]=0;
        }
    }
    cin>>l>>s;
    l*=s*60;
    l*=l;
    int n=0;
    while(cin>>x[n]>>y[n]) n++;
    for(i=0;i<n;i++)  
    {
        for(j=0;j<n;j++)
        {
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<l+eps)a[i][j]=a[j][i]=1;
        }
    }
    for(i=0;i<maxn;i++) d[i]=100000;
    d[0]=0;
    for(i=0;i<n;i++)
    {
        int min;
        for(min=0;min<n&&d[min]==-1;min++);
        for(j=min;j<n;j++)
        {
            if(d[j]!=-1&&d[j]<d[min]) min=j;
        }
        if(min==1) break;
     //   cout<<min<<endl;
        for(j=0;j<n;j++)
        {
            if(a[min][j]&&d[j]>d[min]+1) d[j]=d[min]+1;
        }
        d[min]=-1;
    }
    if(d[1]==100000) cout<<"No."<<endl;
    else cout<<"Yes, visiting "<<d[1]-1<<" other holes."<<endl;
    system("pause");
    return 0;
}
