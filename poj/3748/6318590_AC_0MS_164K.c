#include<stdio.h>
#include<string.h>
void print(long long ans)
{
    if(ans==0) return;
    else
    {
        int x=ans%16;
        print(ans/16);
        
        if(x>=0&&x<10) printf("%c",x+'0');
        else printf("%c",x-10+'a');
    }
}
void main()
{
    unsigned long  ans;
    char str[100];
    int x,y;
    int i,j;
    unsigned long  tp;
    while(scanf("%s",str)!=EOF)
    {
        ans=0;
//        puts(str);
        for(i=0;str[i]!=',';i++)
        {
            ans=ans*16;
            if(str[i]>='0'&&str[i]<='9') ans+=str[i]-'0';
            else ans+=str[i]-'a'+10;
        }
        x=0;
        for(i++;str[i]!=',';i++)
        {
            x=x*10+str[i]-'0';
        }
        y=0;
        for(i++;str[i];i++)
        {
            y=y*10+str[i]-'0';
        }
  //      printf("%I64d\n",ans);
        tp=1;
        tp<<=x;
        if(ans&tp) ans-=tp;
        tp=1;
        tp<<=y;
        ans|=tp;
        tp=1;
        tp<<=(y-1);
        ans|=tp;
        tp=1;
        tp<<=(y-2);
        
        if(ans&tp) ans-=tp;
        printf("%x\n",ans);
  //      if(ans==0) printf("0");
//        else    print(ans);
        
    }
}
