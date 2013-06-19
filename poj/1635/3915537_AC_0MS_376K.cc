#include <stdio.h>
#include<stdlib.h>
int h[9999];
char s[9999],t[9999],*p;
int hash(int j)
{
   int sum=h[j+5000];
   while (*p && *p++=='0')
        sum=(sum+h[j]*hash(j+1)) % 19001;
    return ((sum*sum) % 19001);
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<9999;i++)
        h[i]=rand()%19001;
    while (n--)
    {
        scanf("%s%s",s,t);
        p=s;
        i=hash(0);
        p=t;
        printf("%s\n",i==hash(0)?"same":"different");
        //可以多次hash，避免冲突      
    }
     return 0;
}