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

using namespace std;
int  main()
{

    string str1,str2;
    string ans;
    int i,j;
    int flag1[300],flag2[300];
    char str[1000];
    while(gets(str))
    {
        str1=str;
        gets(str);
        str2=str;
      //  cout<<str1<<endl;
        
        for(i=0;i<300;i++) flag1[i]=flag2[i]=0;
        for(i=0;i<str1.size();i++) flag1[str1[i]]++;
        for(i=0;i<str2.size();i++) flag2[str2[i]]++;
        ans="";
        for(i=0;i<300;i++)
        {
            char ch=i;
            j=MIN(flag1[i],flag2[i]);
            while(j--) ans+=ch;;
            
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
//    while(1);
    return 0;
}
