#include<set>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define maxn 100010
struct node
{
	int x,y;
}a[maxn],b[maxn];
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x>y.x;
}
int c[2*maxn],d[2*maxn],cnt[2*maxn];
set<int> heap;
set<int>::iterator it;
struct tree
{
	int index[10];
	int flag;
}hash[maxn*10];
int kk;
void init()
{
	for(kk=0;kk<10;kk++) hash[0].index[kk]=-1;
	hash[0].flag=-1;
	kk=1;
}
void insert(int num,int key)
{
	char s[10];
	int i,j,k=0;
	for(i=0;num;i++,num/=10) s[i]=num%10+'0';
	s[i]=0;
	reverse(s,s+strlen(s));
	for(i=0;s[i];i++)
	{
		if(hash[k].index[s[i]-'0']==-1) 
		{
			for(j=0;j<10;j++) hash[kk].index[j]=-1;
			hash[kk].flag=-1;
			hash[k].index[s[i]-'0']=kk++;
		}
		k=hash[k].index[s[i]-'0'];
	}
	hash[k].flag=key;
}
int find(int num)
{
	char s[10];
	int i,k=0;
	for(i=0;num;i++,num/=10) s[i]=num%10+'0';
	s[i]=0;
	reverse(s,s+strlen(s));
	for(i=0;s[i];i++) k=hash[k].index[s[i]-'0'];
	return hash[k].flag;
}
int main()
{
	int i,j,k,n,m;
	__int64 ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].y,&a[i].x);
			c[k++]=a[i].y;
		}
		sort(a,a+n,cmp);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&b[i].y,&b[i].x);
			c[k++]=b[i].y;
		}
		sort(b,b+m,cmp);
		sort(c,c+k);
		init();
		j=1;
		for(i=0;i<k;i++)
		{
			if(i==0||c[i]!=c[i-1]) 
			{
				d[j]=c[i];
				insert(c[i],j++);
			}
			else insert(c[i],j);
			c[i]=0;
		}
		ans=j=0;
		for(i=0;i<n;i++)
		{
			for(;b[j].x>=a[i].x&&j<m;j++)
			{
				k=find(b[j].y);
				if(c[k]==0) 	heap.insert(k);
				c[k]++;
			}
			k=find(a[i].y);
			it=heap.lower_bound(k);
			if(it==heap.end()) {ans=-1;break;}
			ans+=d[*it];
			c[*it]--;
			if(c[*it]==0) heap.erase(it);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}