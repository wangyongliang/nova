#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node
{
	int x,y;
};
int cross(node p1,node p2 ,node p3)
{
	int dx1,dy1,dx2,dy2;
	dx1=p2.x-p1.x;
	dy1=p2.y-p1.y;
	dx2=p3.x-p1.x;
	dy2=p3.y-p1.y;
	int ans=dx1*dy2-dy1*dx2;
	return ans;
}
node a[1000],b[1000];
bool cmp(const node &p1,const node &p2)
{
	int ans=cross(a[0],p1,p2);
	if(ans==0)
	{
		if(p1.x==p2.x) return p1.y<p2.y;
		return p1.x<p2.x;
	}
	return ans>0;
}
double  f(node i,node j,node k)  
{  
	double  x1,x2,x3,y1,y2,y3; 
	double x,y,r;
//	double pi=acos(-1);
	x1  =  i.x;  
	x2  =  j.x;  
	x3  =  k.x;  
	y1  =  i.y;  
	y2  =  j.y;  
	y3  =  k.y;  
	x=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2*(x3-x1)*(y2-y1)-2*((x2-x1)*(y3-y1)));  
	y=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2*(y3-y1)*(x2-x1)-2*((y2-y1)*(x3-x1)));  
	r=(x1-x)*(x1-x)+(y1-y)*(y1-y);  
	return sqrt(r);
}
int main()
{
	int t;
	scanf("%d",&t);
	int n,i,j,k,l,m;
	double ans,tp;
	int c[1000][2];
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&b[i].x,&b[i].y);
			a[i]=b[i];
		}
		ans=0.0;
		for(i=0;i<n;i++)
		{
			a[0]=b[i];
			for(j=0;j<i;j++)  a[j+1]=b[j];
			for(j=i+1;j<n;j++) a[j]=b[j];
			sort(a+1,a+n,cmp);
			a[n]=a[1];
			k=0;
			c[k][0]=c[k][1]=1;
			for(j=2;j<=n;j++)
			{
				if(cross(a[0],a[j-1],a[j])==0) c[k][1]=j;
				else
				{
					c[++k][0]=j;
					c[k][1]=j;
				}
			}
			for(j=0;j+1<=k;j++)
			{
				for(l=c[j][0];l<=c[j][1];l++)
				{
					for(m=c[j+1][0];m<=c[j+1][1];m++)
					{
						tp=f(a[0],a[l],a[m]);
						if(ans<tp) ans=tp;
					}
				}
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}