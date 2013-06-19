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
using namespace std;

typedef long long lld;
lld gcd(lld a,lld b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

string f(lld cnt){
    string ans="";
    if(cnt==0) ans+='0';
    else{
        while(cnt)
        {
            char ch='0'+cnt%10;
            ans+=ch;
            cnt/=10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//char str1[100],str2[100],str3[100];
int  main()
{
    lld ans1,ans2,tp1,tp2;
    int n;
    int i;


    while(scanf("%d",&n)!=EOF)
    {
        ans1=0;ans2=1;
        for(i=1;i<=n;i++){
            tp2=ans2*i;
            tp1=ans2+ans1*i;
            lld r=gcd(tp1,tp2);
            tp1/=r;
            tp2/=r;
            ans1=tp1;
            ans2=tp2;
        }
        ans1*=n;
        lld r=gcd(ans1,ans2);
        ans1/=r;
        ans2/=r;
  //      cout<<"the ans is"<<endl;
    //    cout<<ans1<<" "<<ans2<<endl;
        lld q=ans1/ans2;
        ans1%=ans2;
        if(ans1==0) printf("%I64d\n",q);
        else{
            int size;
            tp1=q;
            for(size=1;tp1;tp1/=10) size++;
            while(size--) cout<<" ";
            cout<<ans1<<endl;
            cout<<q<<" ";
            tp1=ans1;
            tp2=ans2;            
            for(size=0;tp1||tp2;size++) tp1/=10,tp2/=10;
            while(size--) cout<<"-";
            cout<<endl;
            for(size=1;q;q/=10) size++;
            while(size--) cout<<" ";
            cout<<ans2<<endl;            
        }
    }
    
    system("pause");
    return 0;
}
