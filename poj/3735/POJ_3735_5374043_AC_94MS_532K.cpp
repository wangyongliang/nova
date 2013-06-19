/*
ID: 05272021
LANG: C++
PROG:
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)>(y)?(x):(y)
#define ps system("pause")
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)

__int64 a[110][110];
__int64 ans[110];
__int64 tp[2][110][110];
__int64 tmp[110][110];
int id[110];

using namespace std;
int main()
{
    int n,m,t;
    char str[100];
    int i,j,k;
    while(scanf("%d%d%d",&n,&m,&t)&&(n+m+t))
    {
        n++;
//        for(i=0;i<=n;i++) ans[i]=0;
//        ans[0]=1;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++) a[i][j]=0;
            a[i][i]=1;
        }
        a[0][0]=1;
        while(t--)
        {
            scanf("%s",str);
            if(str[0]=='e'){
                scanf("%d",&j);
                for(i=0;i<n;i++) a[i][j]=0;
            }
            else if(str[0]=='g'){
                scanf("%d",&j);
                a[0][j]++;
            }
            else{
                scanf("%d%d",&i,&j);
                for(k=0;k<n;k++) swap(a[k][i],a[k][j]);
            }
        }
   /*     for(i=0;i<n;i++){
            for(j=0;j<n;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
        */
        
        int flag=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++) 
            {
                tp[flag][i][j]=tp[1-flag][i][j]=0;
                tp[flag][i][j]=a[i][j];
                a[i][j]=0;
            }
            a[i][i]=1;
        }
        for(;m;m/=2,flag=1-flag)
        {
            for(j=0;j<n;j++)                {
                id[j]=1;
                int cnt=0;
                for(i=1;i<n;i++){
                    if(tp[flag][i][j]!=0) {
                        id[j]=i;
                        cnt++;
                    }
                    if(cnt>=2) while(1);
                }
            }
            if(m%2)
            {
                
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        tmp[i][j]=a[i][id[j]]*tp[flag][id[j]][j]+a[i][0]*tp[flag][0][j];
                    }
                }
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++)a[i][j]=tmp[i][j];
                }
            }
            for(i=0;i<n;i++){
                for(j=0;j<n;j++) tp[1-flag][i][j]=tp[flag][i][id[j]]*tp[flag][id[j]][j]+tp[flag][i][0]*tp[flag][0][j];
            }            
        }
        for(i=1;i<n;i++) {
            if(i>1) printf(" ");
            printf("%I64d",a[0][i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
