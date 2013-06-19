#include<stdio.h>
#define maxn 200000
int a[maxn], b[maxn];
int heap[maxn],m;
void shiftdown(int l)
{
	heap[0]=heap[l];
	int i,j;
	i=l;
	j=l*2;
	while(j<m)
	{
		if(j+1<m&&heap[j]<heap[j+1]) j++;
		if(heap[0]<heap[j])
		{
			heap[i]=heap[j];
			i=j;
			j*=2;
		}
		else break;
	}
	heap[i]=heap[0];
}
void shiftup(int l)
{
	int i,j;
	heap[0]=heap[l];
	i=l;
	j=i/2;
	while(j>=1)
	{
		if(heap[0]>heap[j])
		{
			heap[i]=heap[j];
			i=j;
			j=i/2;
		}
		else
		{
			heap[i]=heap[0];
			return ;
		}
	}
	heap[i]=heap[0];
}
void main()
{
	int i,n,t=1;
	int h1,h2,max,temp,x,y;
	while(scanf("%d%d%d%d%d",&n,&x,&y,&h1,&h2)!=EOF)
	{
		m=1;
		temp=h2;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=h2;
		}
		for(i=0;i<n;i++)
		{
			if(y>a[i]) max=y;
			else max=a[i];
			heap[m]=max;
			shiftup(m);
			m++;
			h2-=x;
			b[i]=h2;
			if(h2>0) h1-=a[i];
			else break;
			while(h1<=0)
			{
				h1+=heap[1];
				heap[1]=0;
				shiftdown(1);
				h2+=x;
			}
		}
		if(h2<=0) printf("Win\n%d\n",i+1);
		else 
		{
			for(i=0,max=b[0];i<n;i++)
			{
				if(max>b[i])max=b[i];
			}
			printf("Lose\n%d\n",temp-max);
		}
	}
	//return 0;
}