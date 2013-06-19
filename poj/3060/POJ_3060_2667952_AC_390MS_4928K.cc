#include<stdio.h>
struct node
{
	int x;
	int y;
}a[1000080];
int b[1010][1010];
int f1[1010],f2[1010];
int main()
{
	int i,j,k,n,d,t;
	int ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&d,&n);
		scanf("%d%d",&a[0].x,&a[0].y);
		j=a[0].x;
		k=a[0].y;
		for(i=0;i<d;i++)
		{
			f1[i]=f2[i]=0;
			for(j=0;j<d;j++) b[i][j]=0;
		}
		for(i=1;i<n;i++) 
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			if(j>a[i].x) j=a[i].x;
			if(k>a[i].y) k=a[i].y;
		}
		for(i=0;i<n;i++)
		{
			a[i].x-=j;
			a[i].y-=k;
			f1[a[i].x%d]++;
			f2[a[i].y%d]++;
			b[a[i].x%d][a[i].y%d]++;
		}
		ans=2000000;
		for(i=0;i<d;i++)
		{
			for(j=0;j<d;j++)
			{
				k=f1[i]+f2[j]-b[i][j];
				if(ans>k) ans=k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}