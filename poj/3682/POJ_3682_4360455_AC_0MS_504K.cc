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
#define sp(x) setprecision(x)
using namespace std;


int  main()
{
    double ans1,ans2;
    double k,p;
    while(cin>>k&&k){
        cin>>p;
        ans1=k/p;
        ans2=ans2 = (k + 1) * ans1 / p - ans1;
        cout<<fixed<<sp(3)<<ans1<<" "<<ans2<<endl;
    }
    system("pause");
    return 0;
}
