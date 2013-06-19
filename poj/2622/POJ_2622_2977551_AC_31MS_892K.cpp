#include<stdio.h>
struct node
{
int x,y;
}a[1000000+100];
int min(int x,int y)
{
if(x>y) return y;
return x;
}
int max(int x,int y)
{
if(x<y) return y;
return x;
}
int main(){
    int n,i,j,k1,k2,k3,k4,x1,x2,y1,y2;
    while(scanf("%d",&n)!=EOF)
    {
    for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    x1=x2=a[0].x;
    y1=y2=a[0].y;
    k1=k2=a[0].y-a[0].x;
    k3=k4=a[0].y+a[0].x;
 //   printf("%d %d %d %d %d %d %d %d\n",x1,x2,y1,y2,k1,k2,k3,k4);
    for(i=1;i<n;i++)
    {
    x1=min(x1,a[i].x);
    x2=max(x2,a[i].x);
    y1=min(y1,a[i].y);
    y2=max(y2,a[i].y);
    k1=min(k1,a[i].y-a[i].x);
    k2=max(k2,a[i].y-a[i].x);
    k3=min(k3,a[i].y+a[i].x);
    k4=max(k4,a[i].x+a[i].y);
    }
//    printf("%d %d %d %d %d %d %d %d\n",x1,x2,y1,y2,k1,k2,k3,k4);
    int ans[8][2];
    ans[0][1]=y1;
    ans[0][0]=k3-y1;
    ans[1][1]=y1;
    ans[1][0]=y1-k1;
    ans[2][0]=x2;
    ans[2][1]=x2+k1;
    ans[3][0]=x2;
    ans[3][1]=k4-x2;
    ans[4][1]=y2;
    ans[4][0]=k4-y2;
    ans[5][1]=y2;
    ans[5][0]=y2-k2;
    ans[6][0]=x1;
    ans[6][1]=x1+k2;
    ans[7][0]=x1;
    ans[7][1]=k3-x1;
    for(i=0;i<8;i++)
    {
 //   printf("%d  %d\n",ans[i][0],ans[i][1]);
    }
//    printf("\n\nthe ans is:\n");
    for(i=0;i<8;i++)
    {
    for( j=0;j<i;j++)
    {
    if(ans[j][0]==ans[i][0]&&ans[j][1]==ans[i][1]) break;
    }
    if(j==i) printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    }
    return 0;
}