#include<stdio.h>
#define maxn 2000000
int a[maxn];
int main()
{
	int b[40],i,j,min,t;
	int c[40];
	int cnt,max,flag;
	scanf("%d",&t);
	while(t--)
	{

		flag=1;
		for(i=0;i<4;i++) 
		{
			scanf("%d",b+i);
			c[i]=0;
		}
		a[0]=0;
		j=1;
		cnt=0;
		max=0;
		while(a[j-1]<=1000000)
		{
			min=0;
			for(i=0;i<4;i++)
			{
				if(a[c[i]]+b[i]<a[c[min]]+b[min]) min=i;
			}
			a[j++]=a[c[min]]+b[min];
			for(i=0;i<4;i++)
			{
				if(a[c[i]]+b[i]==a[j-1])c[i]++;
			}
			if(a[j-1]>1000000) cnt+=1000000-a[j-2];
			else cnt+=a[j-1]-a[j-2]-1;
			if(a[j-1]-a[j-2]>1) max=a[j-1]-1;
		}
		if(cnt<maxn/4) printf("%d\n%d\n",cnt,max);
		else printf("%d\n-1\n",cnt);
	}
	return 0;
}