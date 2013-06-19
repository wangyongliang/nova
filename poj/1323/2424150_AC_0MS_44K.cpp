#include<stdio.h>
#include<stdlib.h>
int cmp(const void * n,const void *m)
{
	return *(int *)n-*(int *)m;
}
int a[1009];
int b[23];
int main()
{
	int n,m,i,j,min,max,flag=1;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<=n*m;i++)a[i]=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
			a[b[i]]=1;
		}
		qsort(b,m,sizeof(b[0]),cmp);
		min=1;
		for(;a[min]&&min<=m*n;min++);
		max=b[0]+1;
		for(max;a[max]&&max<=m*n;max++);
		if(max>m*n) printf("Case %d: %d\n",flag++,m);
		else{
		for(i=0;i<m;i++)
		{
			a[max]=1;
			for(j=n-2;j&&min<=m*n;min++)
			{
				if(!a[min]) j--,a[min]=1;
			}		
						max=b[i+1]+1;
			for(;a[max]&&max<=m*n;max++);
			if(max>n*m) break;
		}
		printf("Case %d: %d\n",flag++,m-i-1);
		}
	}
	return 0;
}