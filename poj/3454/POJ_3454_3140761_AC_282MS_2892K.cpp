#include<stdio.h>
#define maxn 1100000
int a[30],b[30];
int lab[30],n;
char s[maxn];
char tp[maxn];
bool flag[maxn];
void f(int m)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		lab[i]=m/b[i];
		m%=b[i];
	}
}
int g()
{
	int ans=0,i;
	for(i=0;i<n;i++) ans+=lab[i]*b[i];
	return ans;

}
int q[maxn][2];
int bfs(int beg,int t)
{
	int i,st,en,x,y;
	q[0][0]=beg;
	q[0][1]=0;
	st=0;
	en=1;
	while(st<en)
	{
		if(q[st][0]==t) return q[st][1];
		else
		{
			x=q[st][0];
			f(x);
			for(i=0;i<n;i++)
			{
				if(lab[i]+1<a[i])
				{
					lab[i]++;
					y=g();
					if(s[y]=='.'&&flag[y]==0)
					{
						flag[y]=1;
						q[en][0]=y;
						q[en][1]=q[st][1]+1;
						en++;
					}
					lab[i]--;
				}
				if(lab[i]>0)
				{
					lab[i]--;
					y=g();
					if(s[y]=='.'&&flag[y]==0)
					{
						flag[y]=1;
						q[en][0]=y;
						q[en][1]=q[st][1]+1;
						en++;
					}
					lab[i]++;
				}
			}
		}
		st++;
	}
	return -1;
}
void input()
{
	int i=0,j,k;
	k=b[n-1]*a[n-1];
	while(i<k)
	{
		scanf("%s",tp);
		for(j=0;tp[j];j++,i++)  s[i]=tp[j];
	}
	s[k]=0;	
}
int main()
{
	int i,j,x,y,z,k;
	while (scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i==0) b[i]=1;
			else b[i]=b[i-1]*a[i-1];
		}
		input();
		for(i=0;i<maxn;i++)
		{
			if(s[i]=='T') x=i;
			if(s[i]=='S') y=i;
			if(s[i]=='M') z=i;
		}
		s[z]='#';
		s[x]=s[y]='.';
		for(i=0;i<maxn;i++) flag[i]=0;
		i=bfs(x,y);
		if(i==-1) printf("No solution. Poor Theseus!\n");
		else
		{
			s[z]='.';
			for(k=0;k<maxn;k++) flag[k]=0;
			j=bfs(y,z);
			if(j==-1) printf("No solution. Poor Theseus!\n");
			else 
			{
				for(k=0;k<maxn;k++) flag[k]=0;
				i=i+j+bfs(z,x);
				printf("Theseus needs %d steps.\n",i);
			}
		}
	}
	return 0;
}