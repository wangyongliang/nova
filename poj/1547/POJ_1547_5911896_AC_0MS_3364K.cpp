#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

#define maxn 100010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

struct node
{
    int cnt;
    string str;

}a[maxn];
bool operator <(const node &tp1,const node &tp2)
{
    return tp1.cnt<tp2.cnt;
}
int main()
{
    int n;
    int i,j;
    int x,y,z;
    while(cin>>n)
    {
        if(n<0) break;
        for(i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            a[i].cnt=x*y*z;
            cin>>a[i].str;
        }
        sort(a,a+n);
        cout<<a[n-1].str<<" took clay from "<<a[0].str<<"."<<endl;
    }
    return 0;
}
