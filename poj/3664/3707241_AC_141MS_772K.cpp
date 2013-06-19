#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
	int id;
};
 
bool cmp(const node &x,const node &y)
{
		if(x.x==y.x) return x.y>y.y;
		else return x.x>y.x;
}
node a[100000];
int main()
{
	int n;
	int i,j,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].id=i;
		}
		sort(a,a+n,cmp);
		for(i=j=0;i<m;i++)
		{
			if(a[i].y>a[j].y) j=i;
		}
		printf("%d\n",a[j].id+1);
	}	
	return 0;
}

