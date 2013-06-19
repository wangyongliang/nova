/*
ID: 05272021
LANG: C++
PROG: ditch
*/
#include<stdio.h>
#define maxn 300
struct node
{
	int c,f;
}a[maxn][maxn];
int s,t,n;
int max_flow()
{
	int flag[maxn][3],i,j,ans,q[maxn*2],st,en;
	ans=0;
	while(1)
	{
		for(i=1;i<=n;i++) flag[i][0]=0;
		st=en=0;
		q[en++]=1;
		flag[1][0]=1;
		flag[1][1]=0;
		flag[1][2]=0x7fffffff;
		while(st<en)
		{
			i=q[st++];
			for(j=1;j<=n;j++)
			{
				if(flag[j][0]==0&&(a[i][j].c>a[i][j].f||a[j][i].f))
				{
					flag[j][0]=1,q[en++]=j;
					if(a[i][j].c>a[i][j].f)
					{
						flag[j][1]=i;
						flag[j][2]=flag[i][2]>a[i][j].c-a[i][j].f?a[i][j].c-a[i][j].f:flag[i][2];
					}
					else
					{
						flag[j][1]=-i;
						flag[j][2]=flag[i][2]>a[j][i].f?a[j][i].f:flag[i][2];
					}
				}
			}
			if(flag[t][0]) break;
		}
		if(flag[t][0])
		{
			i=flag[t][1];
			ans+=flag[t][2];
			j=t;
			while(j!=s)
			{
				if(i>0)  a[i][j].f+=flag[t][2];
				else i=-i,a[j][-i].f-=flag[t][2];
				j=i;
				i=flag[i][1];
			}
		}
		else return ans;
	}
}
int main()
{
	int i,j,m,k;
//	freopen("ditch.in","r",stdin);
//	freopen("ditch.out","w",stdout);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) a[i][j].c=a[i][j].f=0;
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			a[i][j].c+=k;
		}
		s=1;
		t=n;
		printf("%d\n",max_flow());
	}
	return 0;
}