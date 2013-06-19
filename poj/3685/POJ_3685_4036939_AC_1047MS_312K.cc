#include<stdio.h>
#include <math.h>
typedef __int64 lld;
int n;
lld f(lld b,lld c)
{
	if(b*b-4*c<0) return 0;

		double ans=(-b+sqrt((double)(b*b-4*c)))/2;
	lld cnt;
	cnt=(lld) ans;
	cnt-=10;
	do
	{
		cnt++;
	}
	while(cnt*cnt+b*cnt+c<=0);
	cnt--;
	if(cnt>n) cnt=n;
	if(cnt<0) return 0;
	return cnt;
}
lld ck(lld mid)
{
	lld cnt;
	lld i;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		lld tp=i*i-100000*i;
		cnt+=f(100000+i,tp-mid);
	}
	return cnt;
}
int main()
{
	lld tpp=100000;
	lld min,max,mid,tp,i,m,j;
	lld big,small;
	n=50000;
	min=0x7ffffffffffffffLL;
	max=-1;	
	for(j=1;j<=50010;j++)
	{
		i=1;
		tp=i*i + 100000 * i + j*j - 100000 * j + i * j;
		if(max<tp) max=tp;
		if(min>tp) min=tp;
		i=100000;            
		tp=i*i + 100000 * i + j*j - 100000 * j + i * j;
		if(max<tp) max=tp;
		if(min>tp) min=tp;            
	}
	big=max;
	small=min;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%I64d",&n,&m);
		max=tpp*tpp*10;
		min=-max;
		while(min+1<max)
		{
			mid=(min+max)/2;
			tp=ck(mid);
			if(tp<m) min=mid+1;
			else max=mid;
		}
		if(ck(min)==m)	printf("%I64d\n",min);
		else printf("%I64d\n",max);
	}
	return 0;
}