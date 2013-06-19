#include<stdio.h>
#include<time.h>
int heap[10000];
int size;
void shiftdown(int k)
{
	heap[0]=heap[k];
	int i=k,j;
	j=i*2;
	while(j<size)
	{
		if(j+1<size&&heap[j+1]<heap[j]) j++;
		if(heap[j]<heap[0])
		{
			heap[i]=heap[j];
			i=j;
			j<<=1;
		}
		else break;
	}
	heap[i]=heap[0];
}
void shiftup(int k)
{
	int i=k,j=k/2;
	heap[0]=heap[k];
	while(j>0)
	{
		if(heap[j]>heap[0])
		{
			heap[i]=heap[j];
			i=j;
			j=i/2;
		}
		else break;
	}
	heap[i]=heap[0];
}
void push(int k)
{
	heap[size++]=k;
	shiftup(size-1);
}
void pop()
{
	if(size==1) return;
	heap[1]=heap[size-1];
	size--;
	shiftdown(1);
}
int n;
int b[10000];
int main()
{
	int i,j;
	int k,m;
	char s[10];
	int cnt;
//	freopen("cowturn.9.in","r",stdin);
	int st;
	st=clock();
	while(scanf("%d",&n)!=EOF)
	{
		n++;
		for(i=1;i<n;i++)
		{		
			scanf("%s",s);
			if(s[0]=='F') b[i]=0;
			else b[i]=1;
		}
		m=n*3;
		int tp;
		for(i=1;i<n;i++)
		{
			tp=0;
			size=1;
			for(j=1;j+i<=n;j++)
			{
				while(size>1)
				{
					if(heap[1]<j) pop();
					else break;
				}
				cnt=size-1;
				if((cnt+b[j])%2)
				{
					push(j+i-1);
					tp++;
				}
			}
			for(;j<n;j++)
			{
				while(size>1)
				{
					if(heap[1]<j) pop();
					else break;
				}
				cnt=size-1;
				if((cnt+b[j])%2) tp=n*3;
			}
			if(tp<m)
			{
				k=i;
				m=tp;
			}
		}
		printf("%d %d\n",k,m);
		int en=clock();
//		printf("%d\n",en-st);
	}
	//en=clock();
	return 0;
}