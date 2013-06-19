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
#include <sstream>
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)>0?(x):-(x))
#define SP(x) setprecision(x)
using namespace std;
map<int,string> mp;
map<string,int> mp1;
void init(){
mp[0]="zero";mp[1]="one";mp[2]="two"; mp[3]="three"; mp[4]="four";
 mp[5]="five"; mp[6]="six"; mp[7]="seven"; mp[8]="eight"; 
 mp[9]="nine"; mp[10]="ten";mp[11]="eleven"; mp[12]="twelve";
mp[13]="thirteen";mp[14]="fourteen";mp[15]="fifteen";mp[16]= "sixteen";
mp[17]="seventeen";mp[18]="eighteen";mp[19]="nineteen";mp[20]="twenty";
 mp[30]="thirty"; mp[40]="forty"; mp[50]="fifty";mp[60] ="sixty";
 mp[70] ="seventy"; mp[80]="eighty"; mp[90]="ninety"; mp[100]="hundred"; mp[1000]="thousand";
 map<int,string>::iterator it;
 
 for(it=mp.begin();it!=mp.end();it++){
        mp1[it->second]=it->first;
    }
}

string to(int n){
    string ans="";
    if(n<=20) return mp[n];
    else{
        if(n>=100) {
            ans+=" "+mp[n/100]+" "+mp[100];
            n%=100;
        }
        if(n>20){
            ans+=" "+mp[n/10*10];
            n%=10;
        }
        if(n) ans+=" "+mp[n];        
    }
    return ans;
}
int  main()
{
    string str;
    string ans;
    int n;
    mp.clear();
    init();
    int flag=0;
    string a[100];
    int i,j;

    while(getline(cin,str)){
      //  cout<<str<<endl;
      if(str=="")break;
        istringstream scin(str);
        n=0;
        while(scin>>a[n]){
            n++;
        }
        int num=0;
        if(a[0]=="negative")
        {
             flag=1;
             j=1;
        }
        else
        {
            flag=0;
            j=0;
        }
        int tp=1,tp1=0;
        for(i=n-1;i>=j;i--){
        //    cout<<a[i]<<endl;
            if(a[i]=="hundred") {
                tp1+=mp1[a[i-1]]*100;
                i--;
            }
            else if(a[i]=="thousand"){
                num+=tp1*tp;
                tp=1000;
                tp1=0;
            }
            else if(a[i]=="million"){
                num+=tp1*tp;
                tp=1000000;
                tp1=0;
            }
            else tp1+=mp1[a[i]];
        }
        num+=tp1*tp;
        if(flag) num=-num;
        cout<<num<<endl;
    }
   // while(1);
  //  system("pause");
    return 0;
}
