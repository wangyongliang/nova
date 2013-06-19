#include<stdio.h>
#define  maxn 51000


int A[maxn];
int M[maxn][32],N[maxn][32],n;

void InitRMQ()
{
	int i,j;
	for (i=0; i<n; i++)
		N[i][0]=M[i][0] = i;
	for (j=1; (1<<j)<=n; j++)
	{
		for (i=0; i+(1<<j)-1<n; i++)
		{
			if (A[M[i][j-1]] > A[M[i+(1<<(j-1))][j-1]])
				M[i][j] = M[i+(1<<(j-1))][j-1];
			else
				M[i][j] = M[i][j-1];
			if (A[N[i][j-1]] < A[N[i+(1<<(j-1))][j-1]])
				N[i][j] = N[i+(1<<(j-1))][j-1];
			else
				N[i][j] = N[i][j-1];
		}
	}
}

void  RMQ(int i, int j,int &indexmin,int &indexmax)
{
	int k = 0;
	while ((1<<(k+1)) < (j-i+1)) k++;
	if (A[M[i][k]] > A[M[j-(1<<k)+1][k]])
		indexmin= M[j-(1<<k)+1][k];
	else
		indexmin= M[i][k];
	if (A[N[i][k]] < A[N[j-(1<<k)+1][k]])
		indexmax= N[j-(1<<k)+1][k];
	else
		indexmax= N[i][k];
}
int find(int min,int max)
{
	if(max<0) return -1;
	if(min>=n) return -1;
	if(min>=max) return -1;
	else
	{
		int indexmin,indexmax;
		RMQ(min,max,indexmin,indexmax);
		int ans=-1,tp;
		if(indexmin<indexmax) 
		{
			tp=find(min,indexmin-1);
			ans=ans<tp?tp:ans;
			tp=indexmax-indexmin;
			ans=ans<tp?tp:ans;
			tp=find(indexmax+1,max);
			ans=ans<tp?tp:ans;
		}
		else
		{
			tp=find(min,indexmax);
			ans=ans<tp?tp:ans;
			tp=find(indexmax+1,indexmin-1);
			ans=ans<tp?tp:ans;
			tp=find(indexmin,max);
			ans=ans<tp?tp:ans;
		}
		return ans;
	}
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&A[i]);
		for(i=0;i+1<n;i++)
		{
			if(A[i]<A[i+1]) break;
		}
		if(i+1==n) printf("-1\n");
		else{
		InitRMQ();
		printf("%d\n",find(0,n-1));
		}
	}
	return 0;
}