#include<iostream>
using namespace std;
#define maxn 1010
int a[maxn][4];
int b[maxn][4];
double eps=1e-6;
int main()
{
    __int64 ans[4]={0};
    int n,m;
    
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
            a[i][3]=1;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<3;j++) scanf("%d",&b[i][j]);
            b[i][3]=1;
        }
        int flag=1;
        for(int i=0;i<100000;i++)
        {
            flag=1;
            __int64 tp_ans[4];
            for(int j=0;j<4;j++) tp_ans[j]=ans[j];
            for(int j=0;j<n;j++)
            {
                __int64 tq=0;
                for(int k=0;k<4;k++) tq+=a[j][k]*ans[k];
                if(tq>0)
                {
                    for(int k=0;k<4;k++) tp_ans[k]-=a[j][k];
                    flag=0;
                }                
            }
            
            for(int j=0;j<m;j++)
            {
                __int64 tq=0;
                for(int k=0;k<4;k++) tq+=b[j][k]*ans[k];
                if(tq<=0)
                {
                    for(int k=0;k<4;k++) tp_ans[k]+=b[j][k];
                    flag=0;
                }                
            }            
            if(flag) break;  
            for(int k=0;k<4;k++)    ans[k]=tp_ans[k];
        }
        if(flag) 
        {
            for(int i=0;i<4;i++)
            {
                if(i) printf(" ");
                printf("%I64d",ans[i]);
            }
            printf("\n");
        }
        else printf("NO ans!");
    }
    return 0;
}
