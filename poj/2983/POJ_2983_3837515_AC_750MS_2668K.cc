#include<stdio.h>
struct node
{
	int x,y,l;
}a[1000000];
int dis[1010];
int main()
{
	int n,m,i,j,k;
	char s[10];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		k=0;
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			if(s[0]=='P')
			{
				scanf("%d %d %d",&a[k].x,&a[k].y,&a[k].l);
				a[k+1].x=a[k].y;
				a[k+1].y=a[k].x;
				a[k+1].l=-a[k].l;
				k+=2;
			}
			else
			{
				scanf("%d %d",&a[k].y,&a[k].x);
				a[k++].l=-1;
			}
		}
		for(i=0;i<=n;i++) dis[i]=0;
		int flag;
		for(i=0;i<n;i++)
		{
			flag=1;
			for(j=0;j<k;j++)
			{
				if(dis[a[j].x]+a[j].l<dis[a[j].y])
				{
					dis[a[j].y]=dis[a[j].x]+a[j].l;
					flag=0;
				}
			}
			if(flag) break;
		}
		if(flag==0) printf("Unreliable\n");
		else printf("Reliable\n");
	}
	return 0;
}