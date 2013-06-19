#include<stdio.h>
#include<string.h>
int a[300];
int f(char s1[],char s2[])
{
    int ans,i,j,n1,n2;
    n1=strlen(s1);
    n2=strlen(s2);
    ans=n1+n2;
       for(i=0;i<=n1;i++)
        {
            ans=0;
            for(j=0;j<300;j++) a[j]=0;
            for(j=0;j<n1;j++)
            {
                 a[j]=s1[j]-'0';
                 ans=ans<j?j:ans;
                }
            for(j=i;s2[j-i];j++)
            { a[j]+=s2[j-i]-'0';
            ans=ans<j?j:ans;
        }
            for(j=0;j<=ans;j++)
            {
                if(a[j]>3) break;
            }
        //    printf("%d %d\n",j,ans);
            if(j==ans+1)     break;
        }
        return ans+1;
}
int main()
{
    int i,j,n1,n2;
    int ans;
    char s1[110],s2[110];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        ans=f(s1,s2)       ;
        i=f(s2,s1);
        printf("%d\n",ans>i?i:ans);
    }
    return 0;
}

