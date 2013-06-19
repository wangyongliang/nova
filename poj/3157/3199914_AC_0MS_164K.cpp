#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    string ans;
    char s[200];
    int i,j,flag;
    while(scanf("%s",s)!=EOF)
    {
        flag=-1;
        ans="";
        for(i=0;s[i];i++)
        {
            if(s[i]=='_')
            {
                if(flag==0) break;
                if(i&&s[i-1]=='_') break;
                if(s[i+1]=='_') break;
                flag=1;
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                if(flag==1) break;
                flag=0;
            }
        }
        j=strlen(s)-1;
        if(s[i]||(s[0]>='A'&&s[0]<='Z')||s[0]=='_'||s[j]=='_') 
        {
            printf("Error!\n");
            continue;
        }
        for(i=0;s[i];i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i]=s[i]-'A'+'a';
                ans=ans+'_'+s[i];
            }
            else if(s[i]=='_')
            {
                if(s[i+1])
                {
                    i++;
                    ans+=s[i]-'a'+'A';
                }
            }
            else ans+=s[i];
        }
        if(s[i]) printf("Error!\n");
        else printf("%s\n",ans.c_str());
    }
    return 0;
}
