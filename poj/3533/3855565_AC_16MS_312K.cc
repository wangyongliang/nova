#include<stdio.h>
#include<algorithm>
using namespace std;
int istowpow(int n)
{
	int ans=0;
	while(n%2==0) n/=2,ans++;
	if(n==1) return ans;
	else return -1;
}
int nim_muti(int n,int m)
{
	if(n==1) return m;
	if(m==1) return n;
	if(n<m) swap(n,m);
	int q[30],k,i,j;
	int tp1=istowpow(n),tp2=istowpow(m);
	if(tp1>0&&tp2>0)
	{
		n=tp1;
		m=tp2;
		q[0]=1;
		k=1;
		for(i=0;(1<<i)<=n;i++)
		{	
			if(((1<<i)&n)||((1<<i)&m))
			{
				tp1=1<<(1<<i);
				if(((1<<i)&n)&&((1<<i)&m)) 	q[k++]=tp1/2*3;
				else q[0]*=tp1;
			}
		}
		for(i=1;i<k;i++) q[0]=nim_muti(q[0],q[i]);
		return q[0];
	}
	else//如果两个数字是2^n，那么把他们变成2^k1+2^k2+..+的形式在利用分配律，
	{
		int ans=0;
		for(i=0;(1<<i)<=n;i++)
		{
			for(j=0;(1<<j)<=m;j++)
			{
				if(((1<<i)&n)&&((1<<j)&m))
				{	int tp=nim_muti(1<<i,1<<j);
				ans^=tp;
				}
			}
		}
		return ans;
	}
}
int main()
{
	int n,ans=0,tp1,tp2,i;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&tp1,&tp2);
			tp1=nim_muti(tp1,tp2);
			scanf("%d",&tp2);
			tp1=nim_muti(tp1,tp2);	
		//	printf("%d\n",tp1);
		ans^=tp1;
		}

		if(!ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}