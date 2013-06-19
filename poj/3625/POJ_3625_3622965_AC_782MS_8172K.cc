#include<stdio.h>
#include<math.h>
double a[1001][1001];
double b[1001][2],d[1001];
double dis(int i,int j)
{
	double ans=pow(b[i][0]-b[j][0],2)+pow(b[i][1]-b[j][1],2);
	return sqrt(ans);
}
int main()
{
	int i,j,k;
	int n,m;
	double ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%lf%lf",&b[i][0],&b[i][1]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++) a[j][i]=a[i][j]=dis(i,j);
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			i--;
			j--;
			a[j][i]=a[i][j]=0.0;
		}
		for(i=0;i<n;i++) d[i]=1e20;
		ans=d[0]=0.0;
		for(i=0;i<n;i++)
		{
			for(k=0;k<n&&d[k]<0;k++);
			for(j=k;j<n;j++)
			{
				if(d[j]>-1e-6&&d[j]<d[k]) k=j;
			}
			ans+=d[k];
			for(j=0;j<n;j++)
			{
				if(d[j]>a[k][j]) d[j]=a[k][j];
			}
			d[k]=-1.0;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}