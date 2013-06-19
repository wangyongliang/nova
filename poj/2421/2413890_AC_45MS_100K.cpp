#include<stdio.h>
#include<stdlib.h>

struct g
{
	int v1,v2,i;
};
struct g a[5109];
int b[109];
int cmp(const void *n,const void *m)
{
    return (*(g *)n).i>(*(g *)m).i?1:-1 ;
}
int father(int x)
{
	int t,temp;
	t=x;
	while(b[t]!=-1) t=b[t];
	while(x!=t) {
		temp=b[x];
		b[x]=t;
		x=temp;
	}
	return t;
}
int main()
{
	int n,i,j,k=0,t,p1,p2,sum;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&sum);
			if(j>i)
			{
				a[k].i=sum;
				a[k].v1=i;
				a[k++].v2=j;
			}
		}

	}
	for(i=1;i<=n;i++) b[i]=-1;
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		scanf("%d%d",&i,&j);
		p1=father(i);
		p2=father(j);
		if(p1!=p2) b[p1]=p2;
	}
	qsort(a,k,sizeof(a[0]),cmp);
	sum=0;
	for(i=0;i<k;i++)
	{
		p1=father(a[i].v1);
		p2=father(a[i].v2);
		if(p1!=p2)
		{
			b[p1]=p2;
			sum+=a[i].i;
		}
	}
	printf("%d\n",sum);
	return 0;
}
