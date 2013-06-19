#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define size 50119
struct node
{
	int x;
	int y;
}a[size];
int q[size +10];
bool cmp(const node &x,const node &y)
{
	if(x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}
int Mu(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx1=a[i].x-a[j].x;
	dy1=a[i].y-a[j].y;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	return dx*dy1-dy*dx1;
}
int Mu1(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[i].x-a[k].x;
	dy=a[i].y-a[k].y;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	return abs(dx*dy1-dy*dx1);
}
int dis(int i,int j)
{
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}
int main()
{
	int n;
	int i,j,qq,max,k,temp1,temp2;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		q[0]=0;
		q[1]=1;
		qq=1;
		for(i=2;i<n;i++)
		{
			while(Mu(i,q[qq],q[qq-1])<0) qq--;
	//		if(Mu(i,q[qq],q[qq-1])==0) q[qq]=i;
	//		else 
				q[++qq]=i;
		}
		q[++qq]=n-2;
		for(i=n-3;i>=0;i--)
		{
			while(Mu(i,q[qq],q[qq-1])<0) qq--;
	//		if(Mu(i,q[qq],q[qq-1])==0) q[qq]=i;
	//		else 
				q[++qq]=i;
		}
//		if(qq<10) 
		{
			max=-1;
			for(i=0;i<=qq;i++)
			{
				for(j=i+1;j<=qq;j++)
				{
					temp1=dis(q[i],q[j]);
					max=max<temp1?temp1:max;
				}
			}
			printf("%d\n",max);
			continue;
		}
	/*	i=2;
		while(Mu1(q[i+1],q[1],q[0])>Mu1(q[i],q[1],q[0]))
			i++;
		k=i;
		max=dis(q[i],0);
		for(j=1;j<=k;j++)
		{
			while(Mu1(q[i+1],q[j+1],q[j])>Mu1(q[i],q[j+1],q[j])) 
			{
				i++;
				if(i==qq) i=0;
			}
			temp1=dis(q[i],q[j]);
			max=max<temp1?temp1:max;
		}
		printf("%d\n",max);  */
	}
	return 0;
}
