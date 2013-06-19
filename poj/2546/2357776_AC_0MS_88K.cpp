#include<iostream.h>
#include<math.h>
#include<iomanip.h>
int main()
{
    double x1,y1,a,x2,y2,b,c,s,A,B,area;
    while(cin>>x1>>y1>>a>>x2>>y2>>b)
    {
        if(a<b)c=a,a=b,b=c;
        c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(c>=a+b){area=0;goto out;}//外离或相切
        if(c<=a-b){area=3.1415926*b*b;goto out;}//内含
        A=acos((b*b+c*c-a*a)/2/b/c);//相交
        B=acos((a*a+c*c-b*b)/2/a/c);
        s=(a+b+c)/2;
        s=sqrt(s*(s-a)*(s-b)*(s-c));
        area=a*a*B+b*b*A-2*s;
out:    area=floor(area*1000+0.5)/1000;//加上这一句
cout<<setiosflags(ios::fixed)<<setprecision(3)<<area<<endl;
    }
    return 1;
}