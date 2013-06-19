
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;


/*suffix-array*/

#define maxn 51000
char  a[maxn];
int arr[5][maxn],n;
int *sa,*rank,*nsa,*nrank,*h,*height,*Count;
int len;

void suffix_arry()
{
	int i,j,k;
	Count=arr[4];
	for(i=0;i<300;i++) Count[i]=0;
	for(i=0;i<n;i++)
	{
		Count[a[i]]++;
	}
	for(i=0;i<256;i++) Count[i]+=Count[i-1];
	sa=arr[0];
	rank=arr[1];
	nsa=arr[2];
	h=arr[3];
	for(i=0;i<5;i++) arr[i][n]=-1;
	for(i=0;i<n;i++)
	{
		sa[--Count[a[i]]]=i;
	}
	for(rank[sa[0]]=0,i=1;i<n;i++)
	{
		rank[sa[i]]=rank[sa[i-1]];
		rank[sa[i]]+=(a[sa[i]]!=a[sa[i-1]]);
	}
	for(k=1;k<n&&rank[sa[n-1]]<n-1;k<<=1)
	{
		for(i=0;i<n;i++)
		{
			Count[rank[sa[i]]]=i;
		}
		for(i=n-1;i>=0;i--)
		{
			if(sa[i]>=k)
			{
				nsa[Count[rank[sa[i]-k]]--]=sa[i]-k;
			}
		}
		for(i=n-k;i<n;i++) nsa[Count[rank[i]]--]=i;
		nrank=sa;
		sa=nsa;
		for(nrank[sa[0]]=0,i=1;i<n;i++)
		{
			nrank[sa[i]]=nrank[sa[i-1]];
			if(rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+k]!=rank[sa[i-1]+k])
				nrank[sa[i]]++;
		}
		nsa=rank;
		rank=nrank;
	}
	height=nsa;
	for(i=0;i<n;i++)
	{
		if(rank[i]==0) 
		{
			h[i]=0;
			continue;
		}
		if(i==0||h[i-1]<=1) k=0;
		else k=h[i-1]-1;
		j=sa[rank[i]-1];
		for(;i+k<n&&j+k<n;k++)
		{
			if(a[i+k]!=a[j+k]) break;
		}
		h[i]=k;
	}
	for(i=0;i<n;i++) height[rank[i]]=h[i];
}

int b[maxn],cnt,p[maxn];;
void insert(int x,char ch)
{
	int i;
	len++;
	if(cnt==0)
	{
		b[0]=x;
		p[0]=ch;
		b[++cnt]=len*2;
		return ;
	}
	for(i=cnt-1;i>=0;i--)
	{
		if(b[i]>=x)
		{
			b[i+1]=b[i]+1;
			p[i+1]=p[i];
		}
		else
		{
			b[i+1]=x;
			p[i+1]=ch;
			break;
		}
	}
	if(i+1==0) 
	{
		b[0]=x;
		p[0]=ch;
	}
	b[++cnt]=len*2;
}
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}


int M[maxn][32];

void InitRMQ()
{
	int i,j;
	for (i=0; i<n; i++)
		M[i][0] = i;
	for (j=1; (1<<j)<=n; j++)
	{
		for (i=0; i+(1<<j)-1<n; i++)
		{
			if (height[M[i][j-1]] > height[M[i+(1<<(j-1))][j-1]])
				M[i][j] = M[i+(1<<(j-1))][j-1];
			else
				M[i][j] = M[i][j-1];
		}
	}
}

int rmq(int i, int j)
{
	if(i>=len||j>=len) while(1);
	if(i>j) swap(i,j);
	i++;
	int k = 0;
	while ((1<<(k+1)) < (j-i+1)) k++;
	if (height[M[i][k]] > height[M[j-(1<<k)+1][k]])
		return M[j-(1<<k)+1][k];
	else
		return M[i][k];
}

int f(int x)
{
	int i;
	if(x<=b[0]) return x-1;
	else x-=(b[0]);
	for(i=1;i<=cnt&&x;i++)
	{
		if(b[i]-b[i-1]-1>=x)  return b[i-1]+x;
		else x-=(b[i]-b[i-1]-1);
	}
	if(i>cnt) while(1);
}
int Q(int x,int y)
{
	int i,j,k;
	int ans=0;
	int x1,x2,y1,y2,xx,yy;
	x1=f(x+1);
	y1=f(y+1);
	for(i=0;i<=cnt;i++)
		if(b[i]>x1)break;
	for(j=0;j<=cnt;j++)
		if(b[j]>y1) break;
	while(x1<len&&y1<len)
	{
		if(x1>=len||y1>=len) while(1);
		int tp=height[rmq(rank[x],rank[y])];
		x2=f(x+tp+1);
		y2=f(y+tp+1);
		if(b[i]<=x2||b[j]<=y2)
		{
			tp=min(b[i]-x1,b[j]-y1);
			x+=tp;
			y+=tp;
			xx=x1+tp;
			yy=y1+tp;
			ans+=tp;
			x1=xx;
			y1=yy;
			while(x1<len&&y1<len)
			{
				
		if(x1>=len||y1>=len) while(1);
				char ch1,ch2;
				if(b[i]!=x1) ch1=a[x];
				else ch1=p[i];
				if(b[j]!=y1) ch2=a[y];
				else ch2=p[j];
				if(ch1!=ch2) return ans;
				ans++;
				if(b[i]!=x1) x++,x1++;
				else x1++,i++;
				if(b[j]!=y1) y++,y1++;
				else y1++,j++;
				if(b[i]!=x1&&b[j]!=y1) break;
			}
		}
		else
		{
			ans+=tp;
			break;
		}

	}
	return ans;
}

int main()
{
	int i;
	char s[10];
	char str[10],ch;
	int ct;
	while(scanf("%s",a)!=EOF)
	{
		len=strlen(a);
		n=len;
		if(len>=50010) while(1);
		suffix_arry();
		InitRMQ();
		ct=cnt=0;
		b[cnt]=len+1;
		int t;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%s",s);
			if(s[0]=='Q')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				if(x==y)
					printf("%d\n",len-f(x));
				else
					printf("%d\n",Q(x-1,y-1));
			}
			else if(s[0]=='I')
			{
				scanf("%s%d",s,&i);
				if(i>len) i=len+1;
				insert(i-1,s[0]);
			}
		}
	}
	return 0;
}