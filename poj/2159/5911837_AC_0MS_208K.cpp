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

int main()
{
    string str1,str2;
    int cnt1[300],cnt2[300];
    int i,j;
    while(cin>>str1>>str2)
    {
        int flag=1;
        if(str1.size()!=str2.size())
        {
            flag=0;
        }
        for(i=0;i<300;i++) cnt1[i]=cnt2[i]=0;
        for(i=0;i<str1.size();i++)
        {
            cnt1[str1[i]]++;
        }
        for(i=0;i<str2.size();i++)
        {
            cnt2[str2[i]]++;
        }
        sort(cnt1+'A',cnt1+'Z'+1);
        sort(cnt2+'A',cnt2+'Z'+1);
        for(i='A';i<='Z';i++)
        {
            if(cnt1[i]!=cnt2[i]) flag=0;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}
