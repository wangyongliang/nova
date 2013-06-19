#include<stdio.h>
#define maxn 10010
int a[maxn];
int main()
{
	int n,t,i,j;
	int min;
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<t;i++)
		{
			min=0;
			for(j=0;j<n;j++)
			{
				if(a[min]<a[j]) min=j;
			}
			printf("%d\n",min+1,a[min]);
			int r=a[min]%(n-1);
			for(j=0;j<n;j++)
			{
				if(j==min) continue;
				a[j]+=a[min]/(n-1);
				if(r) 
				{
					a[j]++;
					r--;
				}
			}
			a[min]=0;
		}
	}
	return 0;
}

