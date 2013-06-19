#include<stdio.h>
int b[110][110][110];
int c[110][110][110];
int a[1000010];
int temp[1000010];
int n;
int ans;
int abs(int x)
{
	if(x>0) return x;
	else return -x;
}
void megresort(int x,int y)
{
	int mid;
	
	if(x==y) return ;
	mid=(x+y)/2;
	megresort(x,mid);
	megresort(mid+1,y);
	int k=y,i=mid,j=y;
	while(i>=x&&j>=mid+1)
	{			
		if(a[i]>a[j])  temp[k--]=a[j--];
		else
		{
			temp[k--]=a[i--];
			ans+=y-j;
			ans%=2;
		}
	}
	while(i>=x)
	{
		temp[k--]=a[i--];
		ans+=y-mid;
	}
	while(j>=mid+1) temp[k--]=a[j--];
	for(i=x;i<=y;i++) a[i]=temp[i];
}

int main()
{
	int t;
	scanf("%d",&t);
	int cnt,i,j,k,m;
	while(t--)
	{
		scanf("%d",&m);
		cnt=1;
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				for(k=0;k<m;k++)
				{
					c[i][j][k]=k*m*m+j*m+i+1;
				}
			}
		}
		c[m-1][m-1][m-1]=0;
		for(k=0;k<=m-1;k++)
		{
			for(i=0;i<m*m;i++)
			{
				scanf("%d",&b[i%m][i/m][k]);
				if(b[i%m][i/m][k]==0)
				{
					ans=abs(i%m-m+1)+abs(i/m-m+1)+abs(k-m+1);
				}
			}
		}
		ans%=2;
		n=0;
		for(k=m-1;k>=0;k--)
		{
			for(j=m-1;j>=0;j--)
			{
				for(i=m-1;i>=0;i--) a[n++]=b[i][j][k];
			}
		}
		megresort(0,n-1);
		
		n=0;
		for(k=m-1;k>=0;k--)
		{
			for(j=m-1;j>=0;j--)
			{
				for(i=m-1;i>=0;i--) a[n++]=c[i][j][k];
			}
		}
		megresort(0,n-1);
		if(ans%2) printf("Puzzle is unsolvable.\n");
		else printf("Puzzle can be solved.\n");
		
	}
	return 0;
}