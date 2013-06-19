#include <stdio.h>
#include <math.h>

typedef __int64 int64;

int pos,len,ph,q,p;

int calc(int n)
{
    int ret = n;
    if (n % 2 == 0)
       ret -= ret / 2;
    while (n%2 == 0)
    {
        n /= 2;
    }
    for (int i=3; i<=n && n>1; i+=2)
    {
        if (n%i == 0)
        {
            ret -= ret/ i;
            while (n%i==0 && n>1) n/=i;
        }
    }
    return ret;
}

int64 pmod(int64 a, int64 b, int64 n)
{
    int64 ret = 1;
    while (b)
    {
        if (b & 0x01) ret = ret * a % n;
        b >>= 1;
        a = a * a % n;
    }
    return ret;
}

void out()
{
     for(int i=0; i<10000; i++)
             printf("%d \n\n\n",i);
 }

int main()
{
    int cas = 0;
    while (scanf("%d/%d",&p,&q) != EOF)
    {
        while (p%2 == 0 && q%2== 0) p/=2,q/=2;
        for (int k=3; k<=p && k<=q; k+=2)
        {
            while (p%k==0 && q%k==0)
                p/=k,q/=k;
        }
        p %= q;
        
        if (p == 0)
        {
              //out();
              printf("Case #%d: 1,0\n",++cas);
              continue;
        }
        
        pos = 0;
        while (!(q & 0x01))
        {
            pos++;
            q >>= 1;
        }
        
        if (q == 1)
        {
              printf("Case #%d: %d,0\n",++cas,pos+1);
              //out();
              continue;
        }
        len = ph = calc(q);
        //printf("%d %d\n",q,ph);
        double k = sqrt(ph);
        for (int i=2; i<=k; i++)
        {
            if (ph % i ==0)
            {
                if (pmod(2,i,q) == 1)
                {
                    if(len > i) len = i;
                }
                if (pmod(2,ph/i,q) == 1)
                {
                    if (len > ph / i)
                       len = ph / i;
                }
            }
        }
        printf("Case #%d: %d,%d\n",++cas,pos+1,len);
    }
    return 0;
}
