#include<stdio.h>
#define  maxn 1000010
int a[maxn]={0};
void init()
{
    int i,j;
    for(i=2;i<maxn;i++)
    {
        if(a[i]==0)
        {
            a[i]=i;
            if(i<10000)
            {
                for(j=i*i;j<maxn;j+=i) a[j]=i;
            }
            
        }
    }
}
int p[20],n;
long long ck(long long mid)
{
    long long ans=mid;
    int i,j,k;
    long long tp;
    for(i=1;i<(1<<n);i++)
    {
        k=0;
        tp=1;
        for(j=0;j<n;j++)
        {
            if((1<<j)&i)
            {
                k++;
                tp*=p[j];
            }
        }
        if(k%2) ans-=mid/tp;
        else ans+=mid/tp;
    }
    return ans;
}
int main()
{
    long long min,max,mid,kk;
    int m,k;
    init();
    while(scanf("%d%d",&m,&k)!=EOF)
    {
        int tp=m;
        for(n=0;tp>1;n++)
        {
            p[n]=a[tp];
            while(tp%p[n]==0)     tp/=p[n];
        }
        min=1;
        max=0xffffffffffffLL;
       // k++;
        kk=k;
     //   printf("%lld\n",max);
        while(min<max)
        {
             mid=(min+max)/2;
            long long tpp=ck(mid);
            if(tpp<kk) min=mid+1;
            else max=mid;
        }
        printf("%I64d\n",min);
    }    
    return 0;
}
