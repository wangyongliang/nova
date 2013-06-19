#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

#define maxn 1100
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

char str[100];
string ans[maxn];
int n;
int m;
void dfs(int deep)
{
    if(deep==n)
    {
        ans[m]="";
        ans[m++]=str;
//        printf("%s\n",str);
       // PS;
    }
    else
    {
        int i;
        dfs(deep+1);
        for(i=deep+1;i<n;i++)
        {
            if(str[deep]==str[i]) continue;
            else
            {
                swap(str[deep],str[i]);
                dfs(deep+1);
                swap(str[i],str[deep]);
            }
        }
    }
}
/*
bool cmp(char ch1,char ch2)
{
    int tp1,tp2;
    if(ch1>='A'&&ch1<='Z') tp1=ch1-'A';
    else tp1=ch1-'a';
    
    if(ch2>='A'&&ch2<='Z') tp2=ch2-'A';
    else tp2=ch2-'a';
    if(tp1!=tp2) return tp1<tp2;
    else return ch1<ch2;
}
*/

bool cmp(char a,char b)
{  int t='a'-'A';
    if(isupper(b)&&islower(a))
    {
        b+=t;   
        if(a==b) return false;
        return a<b;  
    }
    else if(isupper(a)&&islower(b))
    {
        a+=t; 
        if(a==b )return  true;
        return a<b;
    }
    else return a<b; 
}


int main()
{
    
    int t;
    scanf("%d",&t);
    int index[13];
    int i;
    while(t--)
    {
        scanf("%s",str);
        n=strlen(str);        
        sort(str,str+n,cmp);
        for(i=0;i<n;i++) index[i]=i;
        char pre[13]="";
        do
        {
            printf("%s\n",str);
            /*
            char now[13]            ;
            for(i=0;i<n;i++) now[i]=str[index[i]];
            now[n]=0;
            if(strcmp(now,pre)!=0) printf("%s\n",now);
            strcpy(pre,now);
            */
        }
        while(next_permutation(str,str+n,cmp));
        continue;

     
        m=0;
        dfs(0);
        sort(ans,ans+m);
        for(int i=0;i<m;i++) cout<<ans[i]<<endl;
    }
    return 0;
}
