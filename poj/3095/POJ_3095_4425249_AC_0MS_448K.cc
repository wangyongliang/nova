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
#define maxn 1000
double p[maxn];
string str;
int after(int i){
    for(int j=i;j>=0;j--){
        if(str[j]=='|'||str[j]=='\\') return 0;
        else if(str[j]=='.') return 1;
    }
    return 1;
}
int before(int i){
    for(int j=i;j<str.size();j++)
    {
        if(str[j]=='|'||str[j]=='/') return 0;
        else if(str[j]=='.') return 1;
    }
    return 1;
}
int  main()
{
    int i,j;
    while(cin>>str){
        if(str=="#") break;
        for(i=0;i<str.size();i++){
            p[i]=0.0;
        }
        for(i=0;i<str.size();i++){
            if(str[i]=='.') p[i]=100;
            else if(str[i]=='|'){
                if(after(i-1)) p[i]+=50;
                if(before(i+1)) p[i]+=50.0;
            }
            else if(str[i]=='/'){
                if(after(i-1)) p[i]=100.0;
            }
            else  if(str[i]=='\\'){
                if(before(i+1)) p[i]+=100.0;
            }
            else {
                p[i]=0.0;
//                if(after(i-1)||before(i+1)) p[i]=100.0;
            }
        }
        double ave=0.0;
        for(i=0;i<str.size();i++){
             ave+=p[i];
        //     cout<<p[i]<<endl;
            }
        ave/=(double)str.size();
        printf("%d\n",(int)ave);
    }
    system("pause");
    return 0;
}
