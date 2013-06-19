#include<stdio.h>
#include<math.h>
#define size 1000100
int a[size];
int temp[size];
__int64 ans;
int n,m,flag;
int b[1000][1000];
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
	int i,j,k,temp;
	int flag;
	while(scanf("%d%d",&n,&m)&&(m+n))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) 
			{
				if(flag) scanf("%d",&b[i][j]);
				else scanf("%d",&b[j][i]);
			}
		}
		for(k=0,i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(b[i][j]==0) temp=abs(n-1-i)+abs(m-1-j)+n*m-1;
				a[k++]=b[i][j];
			}
		}
		ans=0;
		megresort(0,k-1);
		if((ans+temp)%2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
