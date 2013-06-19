#include<stdio.h>
int a[100][100];
int b[100];
int p;
typedef __int64 int64;
int64 gcd(int64 m,int64 n,int64 & x,int64 & y)  // Extend Euclid 
{	int64 x1,y1,x0,y0;
	x0=1;y0=0;
	x1=0;y1=1;
          int64 r=(m%n+n)%n;
	int64 q=(m-r)/n;
	x=0;y=1;
	while(r)
	{  x=x0-q*x1;y=y0-q*y1; x0=x1;y0=y1;
	    x1=x;y1=y;
	    m=n;n=r;r=m%n;
	   q=(m-r)/n;
	}
	return n;
}
int main()
{
	int t;
	char s[100];
	scanf("%d",&t);
	int i,j,k,q1,q2,n;
	int ans[100];
	int64 nn,mm,x,y,pp;
	while(t--)
	{
		scanf("%d%s",&p,s);
		for(i=0;s[i];i++) 
		{
			if(s[i]>='a'&&s[i]<='z') b[i]=s[i]-'a'+1;
			else b[i]=0;
		}
		n=i;
		for(i=0;i<n;i++)
		{
			a[i][0]=1;
			for(j=1;j<n;j++)
			{
				a[i][j]=a[i][j-1]*(i+1);
				a[i][j]%=p;
			}
		}
		for(i=0;i<n;i++)
		{
			q1=a[i][i];
			for(j=i+1;j<n;j++)
			{
				q2=a[j][i];
				for(k=i;k<n;k++)
				{
					a[j][k]=((a[j][k]*q1-a[i][k]*q2)%p+p)%p;
				}
				b[j]=((b[j]*q1-b[i]*q2)%p+p)%p;
			}
		}
		pp=p;
		for(i=n-1;i>=0;i--)
		{
			nn=a[i][i];
			mm=0;
			for(j=i+1;j<n;j++) mm+=a[i][j]*ans[j];
			mm=b[i]-mm;
			mm/=gcd(nn,pp,x,y);
			x*=mm;
			ans[i]=(x%p+p)%p;
		}
		for(i=0;i<n;i++)
		{
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}