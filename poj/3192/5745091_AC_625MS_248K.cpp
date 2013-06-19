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

string str[10];
string com(string str1,string str2)

{
    int i,j,k;
    string ans="";
    for(i=0;i<str1.size();i++)
    {
        for(j=0;j<str2.size()&&i+j<str1.size();j++)
        {
            if(str1[i+j]!=str2[j]) break;
        }
        if(j==str2.size()||i+j==str1.size())            
        {
            for(k=0;k<i+j;k++) ans+=str1[k];
            if(j==str2.size())
            {
                for(;k<str1.size();k++) ans+=str1[k];
            }
            else
            {
                for(;j<str2.size();j++) ans+=str2[j];
            }
            return ans;
        }
    }
    return str1+str2;
}
int main()
{
    int a[10];
    int n,i,j;
    /*
    string str1,str2;
    while(cin>>str1>>str2)
    {
        cout<<com(str1,str2)<<endl;
    }
    */
    while(cin>>n)
    {
        int ans=0;
        for(i=0;i<n;i++) 
        {
            a[i]=i;
            cin>>str[i];
            ans+=str[i].size();
        }
        
        string tmp="";
        do
        {
            tmp=com(str[a[0]],str[a[1]]);
            for(i=2;i<n;i++) tmp=com(tmp,str[a[i]]);
            if(ans>tmp.size()) ans=tmp.size();
        //    cout<<"============="<<endl;
          //  cout<<tmp<<endl;
        }
        while(next_permutation(a,a+n));
        cout<<ans<<endl;
        
            }
    
    return 0;
}
