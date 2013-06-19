#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int dist;
	int fule;
}data[100100];
bool cmp (const node & a,const node & b){  return a.dist < b.dist;}
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
		if(heap[j]>temp){heap[i]=heap[j];i=j;j*=2;}
		else{heap[i]=temp;return ;}
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
		data[0].dist=0;
		data[0].fule=0;
		for(i=1;i<=n;i++) scanf("%d%d",&data[i].dist,&data[i].fule);
		sort(data,data+n+1,cmp);
		for(i=0;i<n;i++)
		{
			if(data[i].dist==data[i+1].dist) data[i+1].fule+=data[i].fule,data[i].fule=0;
		}
		
		scanf("%d%d",&l,&p);
		for(i=n;data[i].dist==l&&i>=0;i++) p+=data[i].fule;
		cnt=0;
		j=1;
		heap[1]=-1;
		m=2;
		flag=1;
		for(;i>=0&&p<l;i--)
		{
			while(p<l-data[i].dist)
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
			heap[m]=data[i].fule;
			shiftup(m);
			m++;
		}
line:;
	 if(flag==0) printf("-1\n");
	 else printf("%d\n",cnt);
	}
	return 0;
}