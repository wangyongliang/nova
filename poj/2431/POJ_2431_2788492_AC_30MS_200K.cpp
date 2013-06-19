#include<stdio.h>
#include<algorithm>
using namespace std;
struct Stop
{
	int dist;
	int fule;
}stop[100100];
bool cmp (const Stop & a,const Stop & b)
{
    return a.dist < b.dist;
}
int heap[100100],m;
void shiftup(int l)
{
	int i,j,temp;
	temp=heap[l];
	i=l;
	j=i/2;
	while(j>=1)
	{
		if(heap[j]<temp)
		{
			heap[i]=heap[j];
			i=j;
			j/=2;
		}
		else
		{
			heap[i]=temp;
			return ;
		}
	}
	heap[i]=temp;
}
void shiftdown(int l)
{
	int i,j,temp;
	temp=heap[l];
	i=l;
	j=i*2;
	while(j<m)
	{
		if(j+1<m&&heap[j+1]>heap[j]) j++;
		if(heap[j]>temp)
		{
			heap[i]=heap[j];
			i=j;
			j*=2;
		}
		else 
		{
			heap[i]=temp;
			return ;
		}
	}
	heap[i]=temp;
}
int main()
{
	int n,i,j,k;
	int l,p;
	int cnt;
	int flag;
	while(scanf("%d",&n)!=EOF)
	{
		stop[0].dist=0;
		stop[0].fule=0;
		for(i=1;i<=n;i++) scanf("%d%d",&stop[i].dist,&stop[i].fule);
		sort(stop,stop+n+1,cmp);
		for(i=0;i<n;i++)
		{
			if(stop[i].dist==stop[i+1].dist) stop[i+1].fule+=stop[i].fule,stop[i].fule=0;
		}
		
		scanf("%d%d",&l,&p);
		for(i=n;stop[i].dist==l&&i>=0;i++) p+=stop[i].fule;
		cnt=0;
		j=1;
		heap[1]=-1;
		m=2;
		flag=1;
		for(;i>=0;i--)
		{
			while(p<l-stop[i].dist)
			{
				if(heap[1]==-1)
				{
					flag=0;
					goto line;
				}
				p+=heap[1];
				heap[1]=-1;
				shiftdown(1);
				cnt++;
			}
			heap[m]=stop[i].fule;
			shiftup(m);
			m++;
		}
line:;
	 if(flag==0) printf("-1\n");
	 else printf("%d\n",cnt);
	}
	return 0;
}