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
#define ABS(x) (x)>0?(x):-(x)
#define ps system("pause")

int a[1010][1010];
using namespace std;
int x[1010],y[1010];
int f(int x1,int y1,int x2,int y2)
{
    int ans=a[x2][y2];
    if(x1-1>=0) ans-=a[x1-1][y2];
    if(y1-1>=0) ans-=a[x2][y1-1];
    if(x1>=1&&y1>=1) ans+=a[x1-1][y1-1];
    return ans;
}
struct node
{
    int x,y;
}b[10101010];
bool cmp(node x,node y)
{
    if(x.x-x.y==y.x-y.y) return x.x<y.x;
    else return x.x-x.y<y.x-y.y;
}
int c[10101010];
int d[10101010];
int main()
{
    int i,j,k;
    int n1,n2,n3;
    int min,max,mid;
    while(scanf("%d%d%d",&n2,&n1,&n3)!=EOF)
    {
        for(i=0;i<1010;i++)
        {
            for(j=0;j<1010;j++) a[i][j]=0;
        }
        for(i=0;i<n2;i++)
        {
            scanf("%d",&y[i]);
            if(y[i]<0||y[i]>=1010) while(1);
        }
        for(j=0;j<n1;j++)
        {
             scanf("%d",&x[j]);
             if(x[j]<0||x[j]>=1010) while(1);
        }
    /*    sort(y,y+n2);
        for(i=k=1;i<n2;i++) if(y[i]!=y[i-1]) y[k++]=y[i];
        n2=k;
        sort(x,x+n1);
        for(i=k=1;i<n1;i++) if(x[i]!=x[i-1]) x[k++]=x[i];        
        n1=k;        */
        for(k=0;k<n3;k++) 
        {
            scanf("%d%d",&i,&j);
            if(i>=0&&i<1010&&j>=0&&j<1010)        a[i][j]++;
        }
        for(i=0;i<1010;i++)
        {
            k=0;
            for(j=0;j<1010;j++) 
            {
                k+=a[i][j];
                a[i][j]=k;
                if(i)a[i][j]+=a[i-1][j];
            }
        }
        k=0;
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++) 
            {
                b[k].x=x[i];
                b[k].y=y[j];
                k++;
            }
        }
        sort(b,b+k,cmp);
        c[k-1]=k-1;
        d[k-1]=k;
        for(i=k-2;i>=0;i--)
        {
            if(b[i].x-b[i].y==b[i+1].x-b[i+1].y) c[i]=c[i+1];
            else c[i]=i;
            if(b[i].x==b[i+1].x&&b[i].y==b[i+1].y) d[i]=d[i+1];
            else d[i]=i+1;
        }
        int ans=0;

        for(i=0;i<k;i++)
        {
            min=d[i];
            max=c[i];
            if(min>max) continue;
            while(min<max)
            {
                mid=(min+max)/2;
                int tmp=f(b[i].x,b[i].y,b[mid].x,b[mid].y);
                if(tmp==0) min=mid+1;
                else max=mid;
            }
            if(f(b[i].x,b[i].y,b[min].x,b[min].y)>0) 
            {
          //      printf("%d %d %d %d\n",b[i].x,b[i].y,b[min].x,b[min].y);
                ans+=c[i]-min+1;
            }
        }
        printf("%d\n",ans);
        
    }
 
    return 0;
}
