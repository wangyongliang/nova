#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <stdio.h>
using namespace std;
double eps=1e-6;
#define  MIN(x,y) ((x)>(y)?(y):(x))
#define  MAX(x,y) ((x)>(y)?(x):(y))

struct node
{
	double x,y;
};
bool cmp(node x,node y)
{
	if(fabs(x.x-y.x)<eps) return x.y<y.y;
	else return x.x<y.x;
}

double f(node tp1,node tp2,int y)
{
	double dx=tp2.x-tp1.x;
	double dy=tp2.y-tp1.y;
	double ans=dx/dy*(y-tp1.y)+tp1.x;
	return ans;
}
int a[200][2];
vector<node> p;
vector<node> seg;

bool check(int k,int y)
{
	if((a[k+1][1]-y)*(y-a[k][1])>=0) 
	{
		y++;
		if((a[k+1][1]-y)*(y-a[k][1])>=0) return 1;
		else return 0;
	}
	else return 0;
}
int main()
{
	int n;
	int i,j;
	int miny,maxy;
	int ans;
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			a[i][0]+=5000;
			a[i][1]+=5000;
		}
		miny=maxy=a[0][1];
		a[n][0]=a[0][0];
		a[n][1]=a[0][1];
		for(i=0;i<n;i++)
		{
			miny=MIN(miny,a[i][1]);
			maxy=MAX(maxy,a[i][1]);
		}
		node now,next;		
		for(i=maxy-1;i>=miny;i--)
		{
			p.clear();
			for(j=0;j<n;j++)
			{
				if(a[j][1]==a[j+1][1]) continue;
				if(check(j,i))
				{
					now.x=a[j][0];
					now.y=a[j][1];
					next.x=a[j+1][0];
					next.y=a[j+1][1];

					node tp;
					tp.x=f(now,next,i+1);
					tp.y=f(now,next,i);
					p.push_back(tp);
				}
			}
			sort(p.begin(),p.end(),cmp);
			seg.clear();
			for(j=0;j<p.size();j+=2)
			{
				now=p[j];
				next=p[j+1];
				node tp;
				tp.x=MIN(now.x,now.y);
				tp.y=MAX(next.x,next.y);
				seg.push_back(tp);
			}
			sort(seg.begin(),seg.end(),cmp);
			int cur=0;
			int cnt=0;
			int last=-1;
			for(j=1;j<seg.size();j++)
			{
				if(seg[j].x<seg[cur].y+eps)
				{
					seg[cur].y=MAX(seg[cur].y,seg[j].y);
				}
				else
				{
					seg[cur].x+=eps;
					int num1=(int) seg[cur].x;
					if(num1==last) num1++;
					int num2=(int) seg[cur].y;
					
					if(fabs(num2-seg[cur].y)<eps) num2--;
					last=num2;
					
					cnt+=num2-num1+1;
					cur=j;
				}
			}
			seg[cur].x+=eps;			
			int num1=(int) seg[cur].x;
			if(num1==last) num1++;
			int num2=(int) seg[cur].y;					
			if(fabs(num2-seg[cur].y)<eps)				
			{
				num2--;
			}
			last=num2;
			cnt+=num2-num1+1;
			ans+=cnt;			
		}
		cout<<ans<<endl;
	}
	return 0;
}
