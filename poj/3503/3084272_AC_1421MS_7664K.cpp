#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 600
int flag[maxn][maxn],flg[maxn][maxn];
int h[maxn][maxn];
struct node
{
	int min,x,y;
}heap[1000000],a[maxn*maxn];
bool cmp(const node &A,const node &B)
{
	return A.min>B.min;
}
int st,en;
void shiftdown(int l)
{
	int i,j;
	i=l;
	j=2*i;
	heap[0]=heap[i];
	while(j<en)
	{
		if(j+1<en&&heap[j].min<heap[j+1].min) j++;
		if(heap[j].min>heap[0].min)
		{
			heap[i]=heap[j];
			i=j;
			j=2*i;
		}
		else  break;
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
		if(heap[j].min<heap[0].min)
		{
			heap[i]=heap[j];
			i=j;
			j=i/2;
		}
		else break;
	}
	heap[i]=heap[0];
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
	int n,x,y,i,j,d,m,k,ans,min;
	int t;
	node temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&d);
		k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				flag[i][j]=flg[i][j]=-1;
				scanf("%d",&h[i][j]);
				a[k].min=h[i][j];
				a[k].x=i;
				a[k].y=j;
				k++;
			}
		}
		sort(a,a+k,cmp);
		ans=0;
		for(i=0;i<k;i++)
		{
			if(a[i].min<a[k-1].min+d&&a[i].min!=a[0].min) break;
			en=2;
			heap[1]=a[i];
			if(a[i].min-flag[a[i].x][a[i].y]>=d) ans++;
			if(i+1<k&&a[i+1].min==a[i].min)
			{
				for(j=i+1;a[j].min==a[j-1].min;j++)
				{
					heap[en]=a[j];
					shiftup(en);
					en++;
					if(a[j].min-flag[a[j].x][a[j].y]>=d) ans++;
				}
				i=j-1;
			}
			while(en>=2)
			{
				temp=heap[1];
			//	heap[1].min=-1;
			//	shiftdown(1);
				for(j=0;j<4;j++)
				{
					x=temp.x+dx[j];
					y=temp.y+dy[j];
					if(x>=0&&x<n&&y>=0&&y<m&&flag[x][y]<temp.min&&h[x][y]<h[a[i].x][a[i].y])
					{
						flag[x][y]=temp.min;
						min=temp.min>h[x][y]?h[x][y]:temp.min;
						if(flg[x][y]<min)
						{
							flg[x][y]=min;
							heap[en].min=min;
							heap[en].x=x;
							heap[en].y=y;
							shiftup(en);
							en++;
						}
					}
				}
				if(en==2) break;
				heap[1]=heap[en-1];
				en--;
				shiftdown(1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}