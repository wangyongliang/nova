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


int  main()
{
    int t;
    int p,q,a[300],beg,end;
    cin>>t;
    int cas=1;
    while(t--){
        cin>>p>>q>>beg>>end;
        cout<<"Problem set "<<cas++<<": "<<p<<" / "<<q<<", base 7 digits "<<beg<<" through "<<end<<
        ": ";
        p=p%q;
        int i;
        
        for(i=0;i<300;i++){
            p*=7;
            a[i]=p/q;
            p=p%q;
        }
        
        for(i=beg;i<=end;i++) cout<<a[i];
        cout<<endl;
    }
    system("pause");
    return 0;
}

