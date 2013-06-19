#include<stdio.h>
#define maxn 500
struct node
{
	int len;
	int a[maxn];
};
typedef __int64 int64;
int64 c[100][100];
node add(node a,node b)
{
	node ans;
	int i,j;
	for(i=0;i<maxn;i++) ans.a[i]=0;
	j=a.len>b.len?a.len:b.len;
	for(i=0;i<j;i++) ans.a[i]=a.a[i]+b.a[i];
	for(i=0;i<maxn-1;i++) ans.a[i+1]+=ans.a[i]/10,ans.a[i]%=10;
	for(j=maxn-1;ans.a[j]==0;j--);
	ans.len=j+1;
	return ans;
}
node muti(node a,node b)
{
	node ans;
	int i,j;
	for(i=0;i<maxn;i++) ans.a[i]=0;
	for(i=0;i<a.len;i++)
	{
		for(j=0;j<b.len;j++)
		{
			ans.a[i+j]+=a.a[i]*b.a[j];
		}
	}
	for(i=0;i<maxn-1;i++) ans.a[i+1]+=ans.a[i]/10,ans.a[i]%=10;
	for(i=maxn-1;ans.a[i]==0;i--);
	ans.len=i+1;
	return ans;
}
node itonode(int64 num)
{
	int i;
	node ans;
	for(i=0;i<maxn;i++) ans.a[i]=0;
	for(i=0;num;i++,num/=10) ans.a[i]=num%10;
	ans.len=i;
	return ans;
}
node ans[55];
int main()
{
	int i,j,n;
	int64 p;
	c[0][0]=1;
	for(i=0;i<51;i++) c[i][0]=c[i][i]=1;
	for(i=1;i<51;i++)
	{
		for(j=0;j<i;j++) c[i+1][j+1]=c[i][j+1]+c[i][j];
	}
	ans[1].len=1;
	ans[1].a[0]=1;
	node tp1;
	for(i=2;i<51;i++)
	{
		ans[i].len=0;
		ans[i].a[0]=0;
		for(j=1;j<i;j++)
		{
			tp1=itonode(c[i-2][j-1]);
			tp1=muti(tp1,ans[j]);
			tp1=muti(tp1,ans[i-j]);
			p=1;
			p<<=j;
			p--;
			tp1=muti(tp1,itonode(p));
			ans[i]=add(ans[i],tp1);
		}
	}
	while(scanf("%d",&n)&&n)
	{
		for(i=ans[n].len-1;i>=0;i--) printf("%d",ans[n].a[i]);
		printf("\n");
	}
	return 0;
}