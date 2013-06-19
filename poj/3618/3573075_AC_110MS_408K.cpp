#include<stdio.h>
#include<algorithm>
using namespace std;
//int abs(int x){return x>0?x:-x;};
bool cmp(const int &x,const int &y) 
{
	return abs(x)<abs(y);
}
int a[51000];
int main()
{
	int n,i,j,ans,tm;
	int t;
	while(scanf("%d%d",&tm,&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		t=0;
		j=0;
		for(i=0;i<n;i++)
		{
			t+=abs(a[i]-j);
			j=a[i];
			if(t>tm) break;
		}
		printf("%d\n",i);
	}
	return 0;
}
