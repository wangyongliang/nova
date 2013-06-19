#include<stdio.h>
int map[1510];
int b[60];
int a[60];
int f(int x,int y)
{
	if(a[x]>=a[y])
		return b[x]+2*a[y];
	else
		return b[x]+2*a[x];
}
bool flag[60];
int main()
{
	int n,i,max,j,temp;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<1600;i++) map[i]=-1;
		scanf("%d",a); b[0]=a[0];
		flag[0]=0;
		for(i=1;i<n;i++)
		{
			flag[i]=0;
			scanf("%d",a+i); max=a[i];
			for(j=0;j<i;j++)
			{
temp=f(j,i);
				max=temp>max?temp:max;
			}
			b[i]=max;
		}
		for(i=0;i<b[0]+a[0];i++) map[i]=0;
		for(i=1;i<n;i++)
		{
			for(j=b[i]-a[i];j<b[i]+a[i];j++)
			{
				if(map[j]==-1) map[j]=i;
				else
				{
					if(a[map[j]]<a[i]) map[j]=i;
				}
			}
		}
		for(i=0;map[i]!=-1;i++)
		{
			flag[map[i]]=1;
		}
		for(i=0;flag[i]==0;i++);
		printf("%d",i+1);
		for(i++;i<n;i++)
		{
			if(flag[i]) printf(" %d",i+1);
		}
		printf("\n");
	}
	return 0;
}

