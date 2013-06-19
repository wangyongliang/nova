#include "stdio.h"
#include "string.h"

struct test
{
    char a[10];
}t[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

void main()
{
    int n,i,j,y1,y2,d,r,s;
    long k;
    char m[10];
    struct test te[20]={"ahau","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac"};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d. %s%d",&d,m,&y1);
        for(j=0;j<19;j++)
            if(strcmp(m,t[j].a)==0)
                k=365*y1+j*20+d+1;
        y2=k/260;
        r=k%260;
        if(r==0)
            y2--;
        s=r%13;
        if(s==0)
            s=13;
        if(i==0)
            printf("%d\n",n);
        printf("%d %s %d\n",s,te[r%20].a,y2);
    }
}