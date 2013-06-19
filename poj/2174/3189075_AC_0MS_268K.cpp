#include<stdio.h>
#include<string.h>
char s[1000000];
int a[1000010];
int b[1000010],ans[100010];
int f(char ch)
{
    if(ch>='0'&&ch<='9') return ch-'0';
    else return  ch-'A'+10;
}
int main()
{
    int i,j,n;
    while(scanf("%s",s)!=EOF)
    {
        for(j=i=0;s[i];i+=2,j++)
        {
            a[j]=f(s[i]);
            a[j]=a[j]*16+f(s[i+1]);
        }
        scanf("%s",s);
        ans[0]=f(s[0])*16+f(s[1]);
        ans[0]=ans[0]^32;
        a[0]=ans[0]^a[0];
        for(j=1,i=2;s[i];i+=2,j++)
        {
            ans[j]=f(s[i])*16+f(s[i+1]);
            ans[j]=a[j-1]^ans[j];
            a[j]=ans[j]^a[j];
        }
        for(i=0;i<j;i++) printf("%02X",ans[i]);
        printf("\n");
    }
    return 0;
}
