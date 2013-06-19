#include<stdio.h>
#define maxn 100009
int a[maxn][20];
int b[maxn][2];
struct node
{
	int x,y;
}p[maxn];
int n;
int ff(int i,int j,int k)
{
	int m;
	int min,max;
	m=b[i][1];

	min=p[m].x>j?p[m].x:j;
	max=p[m].y>k?k:p[m].y;
	return max-min+1;
}
void f()
{
	int i,j;
	int temp;
	for(i=0;i<n;i++) a[i][0]=1;
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;i+(1<<j)-1<n;i++)
		{
			if(a[i][j-1]>a[i+(1<<(j-1))][j-1])
				a[i][j]=a[i][j-1];
			else
				a[i][j]=a[i+(1<<(j-1))][j-1];
			if(b[i+(1<<(j-1))-1][0]==b[i+(1<<(j-1))][0])
			{
				temp=ff(i+(1<<(j-1))-1,i,i+(1<<j)-1);
				a[i][j]=temp>a[i][j]?temp:a[i][j];
			}
		}
	}
}
int g(int i,int j)
{
	int k=0;
	int temp1=0,temp2=0;
	while((1<<(k+1)) <(j-i+1)) k++;
	if(b[i+(1<<k)-1][0]==b[i+(1<<k)][0])
		temp1=ff(1+(1<<k)-1,i,j);
	if(b[j-(1<<k)+1][0]==b[j-(1<<k)][0])
		temp1=ff(j-(1<<k)+1,i,j);
	temp1=temp1>temp2?temp1:temp2;
	if(a[i][k]>a[j-(1<<k)+1][k]) return temp1>a[i][k]?temp1:a[i][k];
	else return temp1>a[j-(1<<k)+1][k]?temp1:a[j-(1<<k)+1][k];
}
int main()
{
	int q,i,j,k;
	int temp;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&q);
		temp=1000000;
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i][0]);
			if(b[i][0]==temp) 
			{
				b[i][1]=k;
				p[k].y=i;
			}
			else
			{
				temp=b[i][0];
				p[++k].x=i;
				b[i][1]=k;
			}
		}
		f();
		for(temp=0;temp<q;temp++)
		{
			scanf("%d%d",&i,&j);
			printf("%d\n",g(i-1,j-1));
		}
	}
	return 0;
}