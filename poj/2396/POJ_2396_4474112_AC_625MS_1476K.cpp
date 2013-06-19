#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define maxn 300
int a[maxn][maxn],b[maxn][maxn];
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)>(y)?(x):(y))
int tp[maxn][maxn][2];
int row[maxn],con[maxn];
int check(int x,int y,string str,int z)
{
	if(str[0]=='=')
		if(z<tp[x][y][1]||z>tp[x][y][0]) return 0;
	else if(str[0]=='<')
		if(z<tp[x][y][1]) return 0;
	else
		if(z>tp[x][y][0]) return 0;
	return 1;
}
void update(int x,int y,string str,int z)
{
	if(str[0]=='=')
		tp[x][y][0]=tp[x][y][1]=z;
	else if(str[0]=='<')
		tp[x][y][0]=MIN(z,tp[x][y][0]);
	else 
		tp[x][y][1]=MAX(z,tp[x][y][1]);
}


int bfs(int s,int t,int pre[],int flg[])
{
	int flag[maxn]={0},q[2*maxn];
	int st,en,i;
	st=0;en=1;	q[st]=s;	flag[s]=1;
	pre[q[st]]=-maxn;
	for(i=0;i<=maxn;i++) flg[i]=0;
	while(st<en)
	{
		int x=q[st];
		if(x==t) return 1;
		for(i=0;i<=s;i++)		
		{
			if(flag[i]==0&&(b[x][i]<a[x][i]||b[i][x]>0))
			{
				q[en++]=i;
				flag[i]=1;
				pre[i]=x;
				if(b[x][i]<a[x][i])	flg[i]=1;
				else flg[i]=0;
			}
		}
		st++;
	}
	return 0;
}
int flag[maxn],pre[maxn];
int solve(int n,int m)
{
	int i,j;
	int s,t;
	s=0;
	t=n+m+1;
	for(i=0;i<maxn;i++)
	{
		for(j=0;j<maxn;j++)
		{
			b[i][j]=a[i][j]=0;
		}
	}
	int ss=t+1,tt=t+2;
	for(i=1;i<=n;i++) 	{
		a[0][ss]+=row[i];
		a[tt][i]+=row[i];
	}
	for(i=1;i<=m;i++) 	{
		a[i+n][ss]+=con[i];
		a[tt][t]+=con[i];
	}	
	for(i=1;i<=n;i++)	{
		for(j=1;j<=m;j++)		{
			a[i][ss]+=tp[i][j][1];
			a[i][j+n]=tp[i][j][0]-tp[i][j][1];
			a[tt][j+n]+=tp[i][j][1];
		}
	}
	a[t][ss]=0;	a[tt][s]=0;
	a[t][s]=0x7fffffff;
	s=tt;	t=ss;
	int ans=0;
	for(i=0;i<tt;i++) ans+=a[tt][i];
	while(bfs(s,t,pre,flag))	{
		int min=0x7fffffff;
		for(i=t;i!=s;i=pre[i])		{
			if(flag[i]>0)	min=MIN(min,a[pre[i]][i]-b[pre[i]][i]);
			else 	min=MIN(min,b[i][pre[i]]);			
		}
		ans-=min;
		for(i=t;i!=s;i=pre[i])
		{
			if(flag[i]>0) b[pre[i]][i]+=min;
			else b[i][pre[i]]-=min;
		}
	}
	if(ans==0) return 1;
	else return 0;
}
int main()
{
	int t;
	cin>>t;
	int n,m,i,j;
	string str;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>row[i];
		for(j=1;j<=m;j++) cin>>con[j];
		int tt;
		cin>>tt;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				tp[i][j][1]=0;
				tp[i][j][0]=0x7fffffff;
			}
		}
		int ok=1;
		while(tt--)
		{
			int x,y,z;
			cin>>x>>y>>str>>z;
			if(str[0]=='<') z--;
			else if(str[0]=='>') z++;
			if(x==0&&y==0)
			{
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=m;j++)
					{
						if(check(i,j,str,z)==0) ok=0;
						update(i,j,str,z);
					}
				}

			}
			else if(x==0)
			{
				for(i=1;i<=n;i++)
				{
					if(check(i,y,str,z)==0) ok=0;
					update(i,y,str,z);
				}
			}
			else if(y==0)
			{
				for(i=1;i<=m;i++)
				{
					if(check(x,i,str,z)==0) ok=0;
					update(x,i,str,z);
				}
			}
			else 
			{
				if(check(x,y,str,z)==0)  ok=0;
				else update(x,y,str,z);
			}
		}
		if(!ok) goto line;		
		if(solve(n,m))
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if(j>1) cout<<" ";
					cout<<tp[i][j][1]+b[i][j+n];

				}
				cout<<endl;
			}
		}
		else
		{
line:
			cout<<"IMPOSSIBLE"<<endl;
		}
		cout<<endl;
	}
	return 0;
}

