#include<stdio.h>
int p;
int f(int n,int m)
{
    __int64 mod;
    if(m==0) return 1;
    else if(m==1) return n;
    else
    {
        mod=f(n,m/2);
        mod*=mod;
        mod%=p;
        if(m%2==1) mod*=n;
        return mod%p;
    }
}
int main()
{
    int n,i;
    while(scanf("%d%d",&p,&n)&&(n+p))
    {
        for(i=2;i*i<=p;i++)
        {
            if(p%i==0) break;
        }
        if(i*i>p) printf("no\n");
        else{
        if(f(n,p)==n) printf("yes\n");
        else printf("no\n");}
    }
    return 0;
}
