#include<stdio.h>
double a[400][2];
double max(double x,double y)
{
    if(x>y) return x;
    else return y;
}
int main()
{
    int n,i,j;
    int d;
    double p,temp;
    while(scanf("%d",&d)&&d)
    {
        a[0][0]=1000;
        a[0][1]=0;
        for(i=1;i<=d;i++)
        {
            scanf("%lf",&p);
            temp=a[i-1][1]*p*0.97;
            temp=(int)( temp*100);
            temp/=100;
            a[i][0]=max(a[i-1][0],temp);
            temp=a[i-1][0]/p*0.97;
            temp=(int)(temp*100);
            temp/=100;
            a[i][1]=max(a[i-1][1],temp);
        }
        printf("%.2lf\n",a[d][0]);
    }
    return 0;
}
