#include<stdio.h>
#define size 220000
int a[size];
bool b[2000100]={0};
int c[size];
int n,m;
int M[size][32];

void InitRMQ()
{
	int i,j;
	for (j=1; (1<<j)<=n; j++)
	{
		for (i=0; i+(1<<j)-1<n; i++)
		{
			if (M[i][j-1] < M[i+(1<<(j-1))][j-1])
				M[i][j] = M[i+(1<<(j-1))][j-1];
			else
				M[i][j] = M[i][j-1];
		}
	}
}

int RMQ(int i, int j)
{
	int k = 0;
	while ((1<<(k+1)) < (j-i+1)) k++;
	if (M[i][k] < M[j-(1<<k)+1][k])
		return M[j-(1<<k)+1][k];
	else
		return M[i][k];
}
int main()
{
	int i,j;
	int num=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		num=1;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			if(a[i]<0) a[i]=1000000-a[i];
		}
		j=0;
		for(i=0;i<n;i++)
		{
			if(b[a[i]]==1)
			{
				while(a[j]!=a[i])
				{
					b[a[j]]=0;
					M[j][0]=i-j;
					j++;
				}
				M[j][0]=i-j;
				c[i]=++j;
			}
			else
			{
				b[a[i]]=1;
				c[i]=j;
			}
		}
		for(b[a[j-1]]=0;j<n;j++)
		{
			M[j][0]=i-j;
			b[a[j]]=0;
		}
		InitRMQ();
		while(m--)
		{
			scanf("%d%d",&i,&j);
			num=c[j];
			if(num<=i) printf("%d\n",j-i+1);
			else
			{
				i=RMQ(i,num-1);
				num=j-c[j]+1;
				printf("%d\n",i<num?num:i);
			}
		}
	}
	return 0;
}
