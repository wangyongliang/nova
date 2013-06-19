//PKU 3374 Cake Share
//用vector时MLE，估算数据量后用静态数组AC
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
struct inf
{
    int a,b;
    friend ostream & operator << (ostream & os, const inf & rhs)
    {
        os<<rhs.a<<"/"<<rhs.b<<endl;
        return os;
    }
}temp;
//vector<inf> v;
inf v[7700000];
int count;
void solve(int a,int b,int c,int d)//0,1,1,1
{ 
    if (b+d>n) return;
    solve(a,b,a+c,b+d);
//    cout<<a+c<<"/"<<b+d<<endl;
    temp.a=a+c;temp.b=b+d;
    v[count++]=temp;
    solve(a+c,b+d,c,d);
};

int main()
{
    while(cin>>n>>m)
    {    
        count=0;
        temp.a=0;temp.b=0;
        v[count++]=temp;
        temp.a=0;temp.b=1;
        v[count++]=temp;
        solve(0,1,1,1);
        temp.a=1;temp.b=1;
        v[count++]=temp;
        while(m--)
        {
            cin>>k;
            if(k>=count)cout<<"No Solution"<<endl;
            else cout<<v[k];
        }
    }
    return 0;
}
