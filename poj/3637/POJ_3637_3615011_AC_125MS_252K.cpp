#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200010];
bool cmp(const int &x,const int &y)
{
    return x>y;
}
int main()
{
    int t,n,i,j,k;
    __int64 sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        sum=0;
        for(i=0;i<n;i++)
        {
            if(i%3==2) sum+=a[i];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}