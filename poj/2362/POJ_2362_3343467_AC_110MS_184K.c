#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[160];
int status[160];
int ca,M,sum,ave,flag;

int cmp(const void* a,const void* b)
{
	return(*(int*)a-*(int*)b);
}

void DFS(int st,int now,int edge)
{
	if(edge==3)
	{
		flag=1;
		return;
	}
	else if(!flag)
	{
		int i;
		for(i=st;i>=0&&!flag;i--)
		{
			if(!status[i])
			{
				if(now+a[i]==ave)
				{
					status[i]=1;
					DFS(M-1,0,edge+1);
					status[i]=0;
				}
				else if(now+a[i]<ave)
				{
					status[i]=1;
					DFS(i,now+a[i],edge);
					status[i]=0;
				}
			}
		}
	}
}

void main()
{
	scanf("%d",&ca);
	while(ca--)
	{
		int i;
		sum=0;
		memset(status,0,sizeof(status));
		scanf("%d",&M);
		for(i=0;i<M;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%4)
		{
			printf("no\n");
			continue;
		}
		ave=sum/4;
		qsort(a,M,sizeof(int),cmp);
		if(a[M-1]>ave)
		{
			printf("no\n");
			continue;
		}
		flag=0;
		DFS(M-1,0,0);
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}
