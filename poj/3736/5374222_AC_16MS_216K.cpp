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

double a[110][5];
int flag[110];
using namespace std;

int main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            for(j=0;j<5;j++)scanf("%lf",&a[i][j]);
            flag[i]=1;
        }
        double t,h;
        t=h=100.0;
        
        scanf("%lf",&h);
        while(h>1e-6){
            int ok=0;
            for(i=0;i<n;i++){
                if(flag[i]){
                    if(sqrt( pow(100.0-a[i][0],2.0) +pow(a[i][1],2.0) )<a[i][3]+t+1e-6){
                        ok=1;
                        h-=a[i][4];
                        t+=a[i][2];
                        flag[i]=0;
                    }
                }
            }
            if(!ok) break;
        }
        if(h>1e-6) printf("Safe!\n");
        else printf("Danger!\n");
    }
    system("pause");
    return 0;
}
