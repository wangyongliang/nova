#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int x,y;
}a[210];
int n;
double distance(int i,int j)
{
	double dis;
	dis=sqrt(pow(abs(a[i].x-a[j].x),2)+pow(abs(a[i].y-a[j].y),2));
	return dis;
}
double dij()
{
	double dis;
	double close[209];
	int i,min;
	for(i=1;i<n;i++) 
	{
		close[i]=distance(i,0);
	}
	close[0]=-1;
	while(1)
	{
		for(i=1;close[i]==-1;i++) ;
		min=i;
		for(;i<n;i++)
		{
			if(close[i]!=-1&&close[min]>close[i]) min=i;
		}
		if(min==1) return close[min];
		else
		{
			for(i=1;i<n;i++)
			{
				if(close[i]!=-1&&i!=min)
				{
					dis=distance(min,i);
					dis=dis>close[min]?dis:close[min];
					if(close[i]>dis) close[i]=dis;
				}
			}
			close[min]=-1;
		}
	}
}
int main()
{
	int t;
	int i;
	int j=1;
	
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",j,dij());
		j++;
	}
	return 0;
}