#include<stdio.h>
#include<math.h>
double pi=3.141592653;
struct node
{
	int x,y,n;
}a[100];
int mu(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[j].x;
	dy1=a[i].y-a[j].y;
	return dx*dy1-dy*dx1;
}
int mu1(int i,int j,int k)
{
	int dx,dy,dx1,dy1;
	dx=a[j].x-a[k].x;
	dy=a[j].y-a[k].y;
	dx1=a[i].x-a[k].x;
	dy1=a[i].y-a[k].y;
	return dx*dy1-dy*dx1;
}
int dis(int i,int j)
{
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}
int main()
{
	int stack[100];
	int flag[100];
	int i,j,k,n,t;
	double max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		j=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].n,&a[i].x,&a[i].y);
			if(a[i].y<a[j].y) j=i;
			flag[i]=1;
		}
		a[0].x=0;
		a[0].y=a[j].y;
		stack[0]=0;
		stack[1]=j;
		flag[0]=flag[j]=0;
		k=1;
		while(1)
		{
			for(i=1;i<=n&&!flag[i];i++);
			if(i>n) break;
			for(j=0;i<=n;i++)
			{
				if(flag[i])
				{
					if(mu(i,stack[k],stack[k-1])>=0)
					{
						if(!j) j=i;
						else
						{
							if(mu1(i,j,stack[k])<0) j=i;
							else if(mu1(i,j,stack[k])==0)
							{
								if(dis(i,stack[k])<dis(j,stack[k])) j=i;
							}
						}
					}
				}
			}
			flag[j]=0;
			stack[++k]=j;
		}
		printf("%d",n);
		for(i=1;i<=k;i++) printf(" %d",stack[i]);
		printf("\n");
	}
	return 0;
}
