#include<stdio.h>
#include<algorithm>
#define size 50000
#define mm 10000000000000000
using namespace std;
struct node
{
	int a;
	int b;
}a[size],temp[size];
int date[size];
__int64 c[size],f[size];
void sort(int x,int y)
{
	int mid;
	if(x==y) return ;
	mid=(x+y)>>1;
	sort(x,mid);
	sort(mid+1,y);
	int i=x,j=mid+1,k=i;
	__int64 sum=0;
	while(i<=mid&&j<=y)
	{
		if(a[i].a<a[j].a)
		{
			sum+=f[a[i].b];
			temp[k++]=a[i++];
		}
		else
		{
			c[a[j].b]+=sum;
			temp[k++]=a[j++];
		}
	}
	while(i<=mid) temp[k++]=a[i++];
	while(j<=y) c[a[j].b]+=sum,temp[k++]=a[j++];
	for(i=x;i<=y;i++) a[i]=temp[i];

}
int main()
{
	int n,i,j,k;
	__int64 ans[2];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&date[i]),c[i]=1;
		for(i=0;i<4;i++)
		{
			for(j=0;j<n;j++)
			{
				f[j]=c[j];
				a[j].a=date[j];
				a[j].b=j;
				c[j]=0;
			}
			sort(0,n-1);
		}
		for(ans[0]=i=ans[1]=0;i<n;i++)
		{
			ans[1]+=c[i];
			ans[0]+=ans[1]/mm;
			ans[1]%=mm;
		}
		if(ans[0]) printf("%I64d%016I64d\n",ans[0],ans[1]);
		else printf("%I64d\n",ans[1]);
	}
	return 0;
}


//http://acm.pku.edu.cn/JudgeOnline/problem?id=2309
