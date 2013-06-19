#include<stdio.h>
#include<math.h>
long double inf=1e-13;
typedef __int64 int64;
int64 gcd(int64 n,int64 m)
{
	int64 r=n%m;
	while(r)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
int64 p[30][30];
int64 f(int n,int m)
{
	int64 ans;
	int64 tp[30],i,j,k,l;
	for(i=1;i<=n;i++) tp[i]=i;
	for(j=1;j<=m;j++)
	{
		k=j;
		for(i=1;i<=n;i++)
		{
			l=gcd(k,tp[i]);
			k/=l;
			tp[i]/=l;
		}
	}
	for(i=1;i<=n-m;i++)
	{
		k=i;
		for(j=1;j<=n;j++)
		{
			l=gcd(k,tp[j]);
			k/=l;
			tp[j]/=l;
		}
	}
	for(i=ans=1;i<=n;i++) ans*=tp[i];
	return ans;
}

long double  a[300][300],b[300];
void swap(int x,int y,int n)
{
	double tp[300];
	int i;
	for(i=0;i<n;i++) tp[i]=a[x][i];
	for(i=0;i<n;i++) a[x][i]=a[y][i];
	for(i=0;i<n;i++) a[y][i]=tp[i];
	tp[0]=b[x];
	b[x]=b[y];
	b[y]=tp[0];
}

int main()
{
	int64 p[30][30];
	long double ans[30];
	int i,j,k,n,m,x,y;
	int64 xx,yy;
	long double tp1,tp;
	for(i=0;i<=20;i++)
	{
		for(j=0;j<=i;j++) p[i][j]=f(i,j);
	}
//	freopen("J.in","r",stdin);
//	freopen("J.out","w",stdout);
	while(scanf("%d%d%d%d",&x,&n,&y,&m)&&(x+n+y+m))
	{
		for(i=0;i<n*m;i++)
		{
			b[i]=0;
			for(j=0;j<n*m;j++) a[i][j]=0;
		}
		for(i=0;i<n*m;i++)
		{
			for(j=0;j<=i;j++)
			{
				xx=j%n;
				yy=(i-j)%m;
				tp=pow(x,j/n)*pow(y,(i-j)/m);
				a[xx*m+yy][i]+=p[i][j]*tp;
			}
		}
		for(i=0;i<n*m;i++) b[i]=0;
		for(i=0;i<=n*m;i++)
		{
			xx=i%n;
			yy=(n*m-i)%m;
			tp=pow(x,i/n)*pow(y,(n*m-i)/m);
			b[xx*m+yy]-=p[n*m][i]*tp;
		}
		n=n*m;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(fabs(a[j][i])>fabs(a[i][i])) swap(i,j,n);
			}
			for(j=i+1;j<n;j++)
			{
				if(fabs(a[j][i])<inf) continue;
				tp1=a[i][i]/a[j][i];
				for(k=i;k<n;k++)
				{
					a[j][k]=a[i][k]-a[j][k]*tp1;
				}
				b[j]=b[i]-b[j]*tp1;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			tp1=0.0;
			for(j=i+1;j<n;j++) tp1+=ans[j]*a[i][j];
			tp1=b[i]-tp1;
			if(fabs(a[i][i])>inf)	ans[i]=tp1/a[i][i];
			else ans[i]=0.0;
		}
		printf("1");
		for(i=n-1;i>=0;i--)
		{
			if(fabs(ans[i])<0.1) ans[i]=0.0;
			printf(" %.0lf",ans[i]);
		}
		printf("\n");
	}
	return 0;
}


