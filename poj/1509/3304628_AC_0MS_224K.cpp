#include<stdio.h>
#include<string.h>
char s[30000];
int main()
{
    int i,j,n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(i=0,j=len;i<len;i++,j++) s[j]=s[i];
        int a=0,b=1,k=0;
        while(1)
        {
            if(s[a+k]==s[b+k])
            {
                k++;
                if(k>=len) break;
            }
            else if(s[a+k]>s[b+k])
            {
                a+=k+1;
                if(a<=b) a=b+1;
                if(a>=len) break;
                k=0;
            }
            else 
            {
                b+=k+1;
                if(b<=a) b=a+1;
                if(b>=len) break;
                k=0;
            }
        }
        if(a<=b) printf("%d\n",a+1);
        else printf("%d\n",b+1);
    }
    return 0;
}
