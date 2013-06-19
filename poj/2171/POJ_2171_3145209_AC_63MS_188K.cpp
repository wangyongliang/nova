#include<stdio.h>
typedef __int64 int64;
int64 pow(int64 n,int cnt)
{
	int64 ans=1;
	while(cnt) ans*=cnt--;
	return ans;
}
int64 bit[20];
int64 f(int64 n,int64 m)
{
	int a[30],b[30],i,j,k,l;
	int64 ans,q,qq;
	int flag=0;
	for(i=0,ans=n;ans;i++,ans/=10) a[i]=ans%10;
	k=i-1;
	for(j=0,ans=m;ans;j++,ans/=10) b[j]=ans%10;
	ans=0;
	l=j-1;
	q=qq=0;
	for(j=1;j<b[l];j++)
	{
		ans++;
		for(i=1;q*bit[i+1]+(j+1)*bit[i]<=n;i++) 
		{
			ans+=bit[i];
		}
		if(q*10+j==qq*10+a[k]) ans+=n%bit[k]+1;
	}
	q=b[l];
	qq=a[k];
	ans++;
	for(l--,k--;l>=0;l--,k--)
	{
		ans++;
		flag=1;
		for(j=0;j<b[l];j++)
		{
			ans++;
			for(i=1;q*bit[i+1]+(j+1)*bit[i]<=n;i++) ans+=bit[i];
			if(q*10+j==qq*10+a[k]) ans+=n%bit[k]+1;
		}
		q=q*10+b[l];
		qq=qq*10+a[k];
	}
	return ans;
}

int main()
{
	int i,j;
	bit[0]=1;
	int64 n,m,min,mid,max,k;
	for(i=1;i<20;i++) bit[i]=bit[i-1]*10;
	while(scanf("%I64d%I64d",&k,&m)!=EOF)
	{
		min=k;
		max=bit[18];
		while(min<max)
		{
			mid=(min+max)/2;
			n=f(mid,k);
			if(n>=m) max=mid;
			else min=mid+1;
		}
		n=f(min,k);
		if(n!=m) printf("0\n");
		else	printf("%I64d\n",min);
	}
	return 0;
}
