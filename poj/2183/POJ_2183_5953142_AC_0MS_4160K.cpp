#include<iostream>
using namespace std;
#define maxn 1001000
int flag[maxn];
int main()
{
    int n;
    int i;
    while(cin>>n)
    {
        for(i=0;i<maxn;i++) flag[i]=0;
        int cnt=1;
        while(flag[n]==0)
        {
            flag[n]=cnt++;
            n/=10;
            n%=10000;
            n*=n;
            n%=1000000;
        }
        int ans1=cnt-flag[n];
       // if(ans1==1) ans1=0;
        int ans2=cnt-1;
      //  if(ans2==1) ans2=0;
        cout<<n<<" "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
