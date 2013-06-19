/*不是自己写的,思路相当清晰*/
#include"iostream"
using namespace std;
long long zeros(long long m)
{
    long long a,s,i;
    a=m;
    if(m<0)return 0;
    s=1;
    a/=10;
    s+=a;
    for(i=10;a>0;i*=10)
    {
        if(a%10)s+=i*(a/10);
        else 
        {
            s+=i*((a/10)-1);
            s+=m%(i*10)+1;
        }
        a/=10;
    }
    return s;
}
int main()
{
    long long m,n;
    cin>>m>>n;
    while(m>=0)
    {
        m=zeros(m-1);
        n=zeros(n);
        cout<<n-m<<endl;
        cin>>m>>n;
    }
    return 0;
}
