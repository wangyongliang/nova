#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define inf 1e20
#define maxn 200
#define minf 1e-10
char s[maxn];
double pi;
int  n;
struct node
{
	double x,y;
	char ch;
}a[maxn],b[maxn],c[maxn*200];

double  f(node x,node y)
{
	double dx,dy;
	dx=x.x-y.x;
	dy=x.y-y.y;
	if(fabs(dx)<minf) return x.x;
	else
	{
		dy/=dx;
		if(fabs(dy)<minf) return inf;
		return  (-x.y)/dy+x.x;
	}
}
bool cmp(const node &x,const node &y)
{
	double x1,y1,x2,y2,ans;
	x1=x.x-b[0].x;
	y1=x.y-b[0].y;
	x2=y.x-b[0].x;
	y2=y.y-b[0].y;
	ans=x1*y2-x2*y1;
	if(fabs(ans)<minf) return x.x>y.x;
	return ans>-minf;
}
double q[maxn*100];

int ck(double mid)
{
	int i,j;
	if(n<=1) return 1;
	b[0].x=mid;
	b[0].y=0.0;
	for(i=1;i<=n;i++) b[i]=a[i-1];
	sort(b+1,b+n+1,cmp);
	for(i=0,j=n;i<n;i++,j--)
	{
		if(b[j].ch!=s[i]) return 0;
	}
	return 1;
}
int main()
{
	pi=acos(-1);
	int i,j,k,ans;
	char ch[10],ss[3];
	double mid,min,max;
	int flag;
/*	int ii,jj;
	for(ii=0;ii<=4;ii++)
	{
		for(jj=0;jj<=9;jj++)
		{
			ss[0]=ii+'0';
			ss[1]=jj+'0';
			ss[2]=0;
	freopen(ss,"r",stdin); */
//	freopen("a.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		min=inf;
		max=-inf;
		scanf("%s",s);
		for(j=i=0;i<n;i++)
		{
			scanf("%s%lf%lf",ch,&a[j].x,&a[j].y);
			a[j].ch=ch[0];
			if(a[j].y<minf)
			{
				flag++; 
				min=min>a[j].x?a[j].x:min;
				max=max<a[j].x?a[j].x:max;
			}
			else j++;
		}
		n=j;
		if(flag>2) 
		{
			printf("0\n");
			continue;
		}
		if(flag<2) min=-inf,max=inf;
		q[0]=min;
		q[1]=max;
		k=2;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				q[k]=f(a[i],a[j]);
				if(q[k]>min-minf&&q[k]<max+minf) k++;
			}
		}
		sort(q,q+k);
		ans=0;
		for(i=0;i+1<k;i++)
		{
			if(i==4901)
			{
				printf("");
			}
			if(fabs(q[i+1]-q[i])<minf) continue;
			else
			{
				mid=(q[i+1]+q[i])/2.0;
				if(ck(mid))
				{
					c[ans].x=q[i];
					c[ans].y=q[i+1];
					ans++;
				//	printf("%d\n",ans);
				}
			}
		}
		printf("%d\n",ans);
		for(i=0;i<ans;i++)
		{
			if(i) printf(" ");
			if( c[i].x+inf <minf)
				printf("*");
			else printf("%.9lf",c[i].x);

			if(inf-c[i].y < minf)
				printf(" *");
			else printf(" %.9lf",c[i].y);
		}
		if(ans)		printf("\n");
	}
	//fclose(s);
//	}}
	return 0;
}