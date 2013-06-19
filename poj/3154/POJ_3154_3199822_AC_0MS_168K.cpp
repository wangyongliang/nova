#include<stdio.h>
#include<math.h>
int main()
{
    double dx,dy,ans,x,y;
    int n,m,i,flag[2010],j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<2010;i++) flag[i]=0;
        ans=0.0;
        dx=10000.0/n;
        dy=10000.0/(m+n);
     //  printf("%.3lf\n",dy);
        j=0;
        flag[j]=1;
        x=y=0.0;
        for(i=1;i<n;i++)
        {
            x+=dx;
            for(;x-y>=-1e-6;j++,y+=dy);
            y-=dy;
          //  printf("%.2lf %.2lf\n",x,y);
            j--;
            if(fabs(x-y)<fabs(x-y-dy))
            {
                if(flag[j]) flag[j+1]=1,ans+=fabs(x-y-dy);
                else flag[j]=1,ans+=fabs(x-y);
            }
            else flag[j+1]=1,ans+=fabs(x-y-dy);
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}
