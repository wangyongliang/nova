#include<stdio.h>
#define N 400005
char s[N];
int next[N],out[N],n,ans;

int kmp()
{
    int ii,p;
    p=-1,next[0]=-1;
    for(ii=1;s[ii]!='\0';ii++)
    {
        while(p!=-1&&s[ii]!=s[p+1])
            p=next[p];
        if(s[ii]==s[p+1])
            p++;
        next[ii]=p;
    }
    return ii;/*字符串长度*/
}

int main()
{
    int n;
    while(scanf("%s",s)!=EOF)
    {
        n=kmp()-1;
        ans=0;
        out[ans++]=n+1;/*长度用数组存起来*/
        while(next[n]!=-1)
        {
         //   num++;
            n=next[n];
            out[ans++]=n+1;
        }
            
        printf("%d",out[--ans]);
        while(ans--)    
           printf(" %d",out[ans]);
        
        putchar('\n');
    }
}

