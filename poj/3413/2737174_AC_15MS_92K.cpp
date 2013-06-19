#include<stdio.h>
bool flag[11];
int a[11][3],ans[11],temp[11],n;
double mmm;
double f(int s,int a1,int b1)
{
	if(s<a1) return 0;
	else if(s>=a1&&s<b1)
		return (s-a1)*1.0/(b1-a1);
	else return 1.0;
}
void dfs(int k,int s,double r)
{
	int i;
	double tp;
	if(k==n)
	{
		if(r>mmm)
		{
			mmm=r;
			for(i=0;i<n;i++) ans[i]=temp[i];
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(flag[i])
			{
				tp=r*f(s,a[i][0],a[i][1]);
				if(tp>mmm)
				{
					flag[i]=0;
					temp[k]=i;
					dfs(k+1,s+a[i][2],tp);
					flag[i]=1;
				}
			}
		}
	}
}
int main()
{
	int i,s;
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			flag[i]=1;
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		mmm=0;
		dfs(0,s,1);
		if(mmm<1e-10)
		{
			printf("0.000\n");
			printf("1\n");
			for(i=1;i<n;i++) printf(" %d",i+1);
			printf("\n");
		}
		else
		{
			printf("%.3lf\n",mmm);
			printf("%d",ans[0]+1);
			for(i=1;i<n;i++) printf(" %d",ans[i]+1);
			printf("\n");
		}
	}
	return 0;
}