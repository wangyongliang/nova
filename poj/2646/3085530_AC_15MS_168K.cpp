#include "stdio.h"
int main(void)
{
    double   sum,ave,a[1010],s1,s2;
    int     n,i,temp;
    while(scanf("%d",&n)==1&&n)
    {
        sum=0;
        for(i=0;i<n;i++)
           scanf("%lf",&a[i]),sum+=a[i];
        ave=sum/n;
        temp=(int)(ave*100+0.5);
        ave=temp/100.0;
        for(i=0,s1=0,s2=0;i<n;i++)
        {
            if(a[i]>ave)
               s1+=a[i]-ave;
            else
                s2+=ave-a[i];
        }
        sum=s1<s2? s1:s2;           
        printf("$%.2lf\n",sum);
    }
}      