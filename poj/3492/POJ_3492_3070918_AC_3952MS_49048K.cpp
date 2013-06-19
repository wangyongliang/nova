#include<stdio.h>
//#include<time.h>
#include<algorithm>
using namespace std;
int index[25000001];
int gcd(int n,int m)
{
	int r=n%m;
	while(r)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
int a[1000][2];
int c[1000];
void shiftdown(int l,int m)
{
	int i,j;
	i=l;
	j=2*i;
	a[0][0]=a[l][0];
	a[0][1]=a[l][1];
	while(j<=m)
	{
		if(j<m&&index[a[j][1]]+a[j][0]>index[a[j+1][1]]+a[j+1][0]) j++;
		if(index[a[j][1]]+a[j][0]<index[a[0][1]]+a[0][0])
		{
			a[i][1]=a[j][1];
			a[i][0]=a[j][0];
			i=j;
			j=2*i;
		}
		else  break;
	}
	a[i][0]=a[0][0];
	a[i][1]=a[0][1];
}
int main()
{
	int n,m,min,i,j,k;
	index[0]=0;
	index[0]=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&c[i]);
		sort(c,c+n);
		min=k=a[1][0]=c[0];
		a[1][1]=0;
		for(i=1,j=2;i<n;i++) 
		{
			if(c[i]!=c[i-1])
			{
				a[j][0]=c[i];
				a[j][1]=0;
				k=gcd(a[j][0],k);
				j++;
			}
			min=min>c[i]?c[i]:min;
		}
		n=j-1;
		j=min;
		if(k!=1)
		{
			printf("INF\n");
			continue;
		}
		for(i=n/2;i>=1;i--) shiftdown(i,n);
		m=0;
		while(1)
		{
			while(index[a[1][1]]+a[1][0]==index[k-1])
			{
				a[1][1]++;
				shiftdown(1,n);
			}
			index[k]=index[a[1][1]]+a[1][0];
			if(index[k]!=index[k-1]+1) m=index[k];
			if(index[k]-m>=j) break;
			k++;
		}
		if(m) m--;
		printf("%d\n",m);
	}
	return 0;
}