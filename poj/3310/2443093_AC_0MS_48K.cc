
#include<stdio.h>
#include<stdlib.h>
typedef struct Edge
{
	struct Edge *p;
	int i;
}edge;
typedef struct Node
{
	int i;
	edge *head;
	edge *end;
}Node;
Node a[110];
int b[110];
int n;
int dfs(int x,int deep)
{
	edge *p,*q;
	int i=1;
	p=a[x].head;
	for(;p!=NULL;p=p->p)
	{
		if(b[p->i]>=1&&b[p->i]<deep-2) return 0;
		if(b[p->i]==0)
		{
			i=0;
			b[p->i]=1;
		}
	}
	if(i) 
	{
		b[x]=1;
		return 1;
	}
	for(p=a[x].head;p!=NULL;p=p->p)
	{
		if(b[p->i]==1)
		{
			b[p->i]=deep;
			if(dfs(p->i,deep+1))
			{
				for(i=1;i<=n&&b[i];i++) ;
				if(i>n) return 1;
			}
			b[p->i]=1;
		}
	}
	b[x]=1;
	for(p=a[x].head;p!=NULL;p=p->p)
	{
		if(b[p->i]==1) b[p->i]=0;
	}
	return 0;
}
void creat(int i,int k)
{
	edge *p;
	if(a[i].head==NULL)
	{
		a[i].head=(edge *)malloc(sizeof(edge));
		a[i].head->i=k;
		a[i].head->p=NULL;
		a[i].end=a[i].head;
	}
	else
	{
		p=(edge *)malloc(sizeof(edge));
		p->i=k;
		p->p=NULL;
		a[i].end->p=p;
		a[i].end=a[i].end->p;
	}
}
int main()
{
	int i,j,e,k,flag=1;
	edge *p,*q;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&e);
		for(i=1;i<=n;i++) 
		{
			b[i]=0;
			p=a[i].head;
			a[i].head=NULL;
			while(p!=NULL)
			{
				q=p;
				p=p->p;
				free(q);
			}
		}
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&j,&k);
			b[j]++;
			b[k]++;
			creat(j,k);
			creat(k,j);
		}
		j=0;
		for(i=1;i<=n;i++)
		{
			if(b[i]==1&&!j) j=i;
			b[i]=0;
		}
		if(j)
		{
			b[j]=3;
			if(dfs(j,4)) printf("Graph %d is a caterpillar.\n",flag);
			else printf("Graph %d is not a caterpillar.\n",flag);
		}
		else
			printf("Graph %d is not a caterpillar.\n",flag);
		flag++;

	}
	return 0;
}



