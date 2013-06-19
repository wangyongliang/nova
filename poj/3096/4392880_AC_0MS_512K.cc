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


string str[10000];
int  main()
{
    string str1;
    int i,j,cnt;
    while(cin>>str1){
        if(str1=="*") break;
        for(i=1;i<str1.size();i++){
            cnt=0;
            for(j=0;j+i<str1.size();j++)  {
                str[cnt]="";
                str[cnt]+=str1[j];
                str[cnt]+=str1[j+i];
                cnt++;
            }
            sort(str,str+cnt);
            for(j=0;j+1<cnt;j++)
            {
                if(str[j]==str[j+1]) break;
            }
            if(j+1<cnt) break;
        }
        if(i==str1.size()) cout<<str1<<" is surprising."<<endl;
        else cout<<str1<<" is NOT surprising."<<endl;
    }
    system("pause");
    return 0;
}

