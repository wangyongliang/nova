#include<stdio.h>
#include<algorithm>
#include<math.h>
#define maxn 50019
using namespace std;
struct node
{
	int x;
	int y;
}a[maxn];
int q[maxn];
bool cmp(const node &x,const node &y)
{
	int dx,dy,dx1,dy1;
	dx=x.x-a[0].x;
	dy=x.y-a[0].y;
	dx1=y.x-a[0].x;
	dy1=y.y-a[0].y;
	if(dx*dy1-dy*dx1==0)
	{
		return dx*dx+dy*dy>dx1*dx1+dy1*dy1;
	}
	return dx*dy1-dy*dx1>0;
} 
int Mu(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[j].x;
	dy1=a[i].y-a[j].y;
	return dx*dy1-dy*dx1;
}
int Mu1(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[k].x;
	dy1=a[i].y-a[k].y;
	return abs(dx*dy1-dy*dx1);
}
int dis(int i,int j)
{
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}
int main()
{
	int n,det;
	int i,j,max,qs,temp,k;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d",&a[0].x,&a[0].y);
		max=0;
		for(i=1;i<n;i++) 
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			if(a[max].y>a[i].y||(a[max].y==a[i].y&&a[max].x>a[i].x)) max=i;
		}
		i=a[max].x;
		j=a[max].y;
		a[max].x=a[0].x;
		a[max].y=a[0].y;
		a[0].x=i;
		a[0].y=j;
		sort(a+1,a+n,cmp);
		a[n].x=a[0].x;
		a[n++].y=a[0].y;
		q[0]=0;
		q[1]=1;
		qs=1;
		for(i=2;i<n;i++)
		{
			while(Mu(i,q[qs],q[qs-1])<0) qs--;
			if(Mu(i,q[qs],q[qs-1])==0)
			{
				if(dis(i,q[qs-1])>dis(q[qs],q[qs-1])) q[qs]=i;
			}
			else q[++qs]=i;
		}
		max=-1;
		if(qs<5)
		{
			for(i=0;i<=qs;i++)
			{
				for(j=0;j<=qs;j++)
				{
					temp=dis(q[i],q[j]);
					max=max<temp?temp:max;
				}
			}
		}
		else
		{
			i=0;
			j=1;
			while(Mu1(q[j+1],q[i+1],q[i])>Mu1(q[j],q[i+1],q[i])) j++;
			k=j;
			i++;
			max=-1;
			while(i<=qs)
			{
				temp=dis(q[i],q[j]);
				max=max<temp?temp:max;
				while(Mu1(q[j+1],q[i+1],q[i])>Mu1(q[j],q[i+1],q[i]))
				{
					j++;
					temp=dis(q[i],q[j]);
					max=max<temp?temp:max;
				}
				if(Mu1(q[j+1],q[i+1],q[i])==Mu1(q[j],q[i+1],q[i]))
				{
					temp=dis(q[i],q[j+1]);
					max=max<temp?temp:max;
				}
				i++;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}