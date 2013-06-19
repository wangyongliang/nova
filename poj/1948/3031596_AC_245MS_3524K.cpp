#include<stdio.h>
#include<math.h>
#define maxn 1700
bool flag[maxn][maxn];
struct node
{
	int x,y;
}a[maxn*maxn];
int cnt;
void f(int x,int y)
{
	
	if(flag[x][y]==0){
		flag[x][y]=1;
	a[cnt].x=x;
	a[cnt++].y=y;}
}
int main()
{
	int i,j,k,n,x,sum;
	int b[3];
	node temp;
	double p,s,max;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<maxn;i++)
		{
			for(j=0;j<maxn;j++) flag[i][j]=0;
		}
		sum=a[0].x=a[0].y=0;
		flag[0][0]=1;
		cnt=1;
		while(n--)
		{
			scanf("%d",&x);
			sum+=x;
			for(i=0,j=cnt;i<j;i++)
			{
				b[0]=a[i].x+x;
				b[1]=a[i].y;
				b[2]=sum-b[0]-b[1];
				if(b[0]<=b[1]) f(b[0],b[1]);
				else if(b[0]>=b[1]&&b[0]<=b[2]) f(b[1],b[0]);
				else f(b[1],b[2]);
				b[0]=a[i].x;
				b[1]=a[i].y+x;
				b[2]=sum-b[0]-b[1];
				if(b[1]<=b[2]) f(b[0],b[1]);
				else  f(b[0],b[2]);

			}
		}
		max=-1;
		for(k=0;k<cnt;k++)
		{
			i=a[k].x;
			j=a[k].y;
			if(i&&j&&(i+j<sum)&&(2*(i+j)>sum)&&(sum>2*j)&&(sum>2*i))
			{
				p=sum/2.0;
				s=sqrt(p*(p-i)*(p-j)*(p-sum+i+j));
				max=max<s?s:max;
			}
		}
		max*=100;
		if(max<0) printf("-1\n");
		else printf("%d\n",(int)max);
	}
	return 0;
}

