#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[1000000];
int flag[1100];
__int64 sum(int x)
{
	__int64 ans=0;
	while(x>0) 
	{
		ans+=flag[x];
		x-=(x&(-x));
	}
	return ans;
}
int n,m,p;
void insert(int x)
{
	while(x<=m) 
	{
		flag[x]++;
		x+=(x&(-x));
	}
}
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
int main()
{
	 int t,i,j,k;
	 __int64 ans;
	 while(scanf("%d",&t)!=EOF)
	 {
		 for(k=1;k<=t;k++)
		 {
			 scanf("%d%d%d",&n,&m,&p);
			 ans=0;
			 for(i=1;i<=m;i++) flag[i]=0;
			 for(i=0;i<p;i++) scanf("%d%d",&a[i].x,&a[i].y);
			 sort(a,a+p,cmp);
			 for(i=0;i<p;i++)
			 {
				 ans+=sum(m)-sum(a[i].y);
				 insert(a[i].y);
			 }
			 		 printf("Test case %d: %I64d\n",k,ans);
		 }

	 }
	 return 0;
}