#include<stdio.h>
#include<algorithm>
using namespace std;
#define size 20
int a[size][size],b[size],c[size];
bool cmp(const int &i,const int &j)
{ 
	return b[i]>b[j];
}
int main()
{
	int n,i,j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			c[i]=i;
			scanf("%d",&b[i]);
			for(j=0;j<n;j++) a[i][j]=0;
		}
		int flag;
		while(1)
		{
			sort(c,c+n,cmp);
			if(b[c[0]]==0) 
			{
				flag=1;
				break;
			}
			for(i=1;i<n&&b[c[0]];i++)
			{
				if(a[c[0]][c[i]]==0&&b[c[i]])
				{
					b[c[0]]--;
					b[c[i]]--;
					a[c[i]][c[0]]=a[c[0]][c[i]]=1;
				}
			}
			if(b[c[0]])
			{
				flag=0;
				break;
			}
		}
		if(flag) 
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			{
				printf("%d",a[i][0]);
				for(j=1;j<n;j++) printf(" %d",a[i][j]);
				printf("\n");
			}
		}
		else
			printf("NO\n");
		printf("\n");
	}
	return 0;
}