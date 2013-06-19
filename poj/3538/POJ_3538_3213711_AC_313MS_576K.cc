#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 10010
struct node
{
	int x,y,z;
}a[maxn];
int flag[maxn], index[maxn],flg[maxn],ans[maxn],p[maxn];
int n,m;
int find(int x)
{
	int y,z;
	y=x;
	while(y!=flg[y]) y=flg[y];
	while(x!=flg[x])
	{
		z=x;
		x=flg[x];
		flg[z]=y;
	}
	return y;
}
bool cmp(const int &x,const int &y)
{
	node xx=a[x];
	node yy=a[y];
	if(xx.z==yy.z)
	{
		if(xx.x==yy.x) return xx.y<yy.y;
		else return xx.x<yy.x;
	}
	return xx.z<yy.z;
}
int main()
{
	int i,j,k;
	int x,y;
	int sum;
	int p1,q1,p2,q2;
	int f1,f2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		f1=5;f2=6;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			ans[i]=0;
			p[i]=i;
		}
		scanf("%d%d%d%d",&p1,&q1,&p2,&q2);
		for(i=1;i<=n;i++) flg[i]=i;
		sort(p,p+m,cmp);
		if(p1>p2)
		{
			swap(p1,p2);
			swap(q1,q2);
			swap(f1,f2);
		}
		for(i=0;i<=q1;i++) flag[i]=0;
		flag[0]=1;
		for(sum=i=k=0;i<m&&k<n-1;i++)
		{
			x=find(a[p[i]].x);
			y=find(a[p[i]].y);
			if(x!=y)
			{
				k++;
				flg[x]=y;
				sum+=a[p[i]].z;
				ans[p[i]]=f2;
				for(j=q1;j>=a[p[i]].z;j--)
				{
					if(flag[j]==0&&flag[j-a[p[i]].z])
					{
						index[j]=p[i];
						flag[j]=1;
					}
				}
			}
		}
		if(k<n-1) printf("Impossible\n");
		else
		{
			for(j=q1;flag[j]==0;j--);
			if(sum-j>q2) 
			{
				printf("Impossible\n");
				continue;
			}
			sum=j*p1;
			while(j)
			{
				ans[index[j]]=f1;
				j-=a[index[j]].z;
			}
			for(i=0;i<m;i++)
			{
				if(ans[i]==f2) sum+=p2*a[i].z;
			}
			printf("%d\n",sum);
			for(i=0;i<m;i++) 
			{
				if(ans[i]) printf("%d %d\n",i+1,ans[i]);
			}
		}
	}
	return 0;
}
