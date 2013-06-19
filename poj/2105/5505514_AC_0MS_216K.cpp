#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    string str;
    cin>>t;
    bool flag;
    int i,j;
    while(t--)
    {
        cin>>str;
        flag=1;
        for(i=7;i<str.size();i+=8)
        {
            int ans=0;
            for(j=0;j<8;j++)
            {
                if(str[i-j]=='1') ans+=(1<<j);                
                
            }if(!flag) cout<<".";
                else flag=0;
                cout<<ans;
            
            
        }
        cout<<endl;
    }
    return 0;
}
