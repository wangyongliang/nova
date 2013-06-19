#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 1000000
int cnt,m;
vector<int> a[maxn];
struct node
{
	int next[26];
	int num;
}hash[maxn];
bool flag[maxn];
int insert(char s1[])
{
	int i,j=0,k;
	for(i=0;s1[i];i++)
	{
		if(hash[j].next[s1[i]-'a']==-1)
		{
			for(k=0;k<26;k++) hash[m].next[k]=-1;
			hash[m].num=-1;
			m++;
			hash[j].next[s1[i]-'a']=m-1;
		}
		j=hash[j].next[s1[i]-'a'];
	}
	if(hash[j].num==-1)
	{
		a[cnt].clear();
		flag[cnt]=1;
		hash[j].num=cnt++;
	}
	return hash[j].num;
}
int p1,p2;
struct NODE
{
	int a[3],b[3];
}ans[maxn];
int min(int x,int y)
{
	if(x>y) return y;
	return x;
}
// a 是没有 b 是有
void dfs(int i)
{
	int j,k,x;
	int b[2][3];
	if(a[i].begin()==a[i].end())
	{
		for(j=0;j<3;j++) ans[i].a[j]=ans[i].b[j]=0;
		if(p1<p2) ans[i].b[0]=1,ans[i].b[2]=p1;
		else ans[i].b[1]=1,ans[i].b[2]=p2;
	}
	else
	{
		for(j=0;j<a[i].size();j++)
		{
			dfs(a[i][j]);
		}
		for(j=0;j<3;j++) ans[i].a[j]=ans[i].b[j]=0;
		for(j=0;j<a[i].size();j++)
		{
			x=a[i][j];
			for(k=0;k<3;k++) ans[i].a[k]+=ans[x].b[k];
			if(ans[x].a[2]<ans[x].b[2]||(ans[x].a[2]==ans[x].b[2]&&
				ans[x].a[0]+ans[x].a[1]<ans[x].b[0]+ans[x].b[1]))
			{
				for(k=0;k<3;k++) ans[i].b[k]+=ans[x].a[k];
			}
			else
			{
				for(k=0;k<3;k++) ans[i].b[k]+=ans[x].b[k];
			}
		}
		if(ans[i].a[2]+p1<ans[i].b[2]+p2||(ans[i].a[2]+p1==ans[i].b[2]+p2&&
			ans[i].a[0]+ans[i].a[1]<=ans[i].b[0]+ans[i].b[1]))
		{
			for(k=0;k<3;k++) ans[i].b[k]=ans[i].a[k];
			ans[i].b[0]++;
			ans[i].b[2]+=p1;
		}
		else 
		{
			ans[i].b[1]++;
			ans[i].b[2]+=p2;
		}
	}
}
int main()
{
	char ss[1000],tp[1000];
	int i,j,k,n;
	gets(ss);
	int t=1;
	sscanf(ss,"%d%d",&p1,&p2);
	while(1)
	{
		if(p1==0&&p2==0) break;
		cnt=0;
		for(i=0;i<26;i++) hash[0].next[i]=-1;
		hash[0].num=-1;
		m=1;
		while(1)
		{
			gets(ss);
			if(ss[0]>=0&&ss[0]<='9') break;
			for(i=0;ss[i]>='a'&&ss[i]<='z';i++) tp[i]=ss[i];
			tp[i]='\0';
			j=insert(tp);
			while(ss[i]&&ss[i]==' ')i++;
			if(ss[i]){
			for(k=0,tp[0]=ss[i];ss[i];i++)
			{
				if(ss[i]==' '&&k)
				{
					tp[k]='\0';
					k=insert(tp);
					flag[k]=0;
					a[j].push_back(k);
					k=0;
				}
				else tp[k++]=ss[i];
			}
			tp[k]='\0';
			k=insert(tp);
			a[j].push_back(k);
			flag[k]=0;
			}
		}
		int c[3]={0};
		for(i=0;i<cnt;i++)
		{
			if(flag[i]){
			dfs(i);
			for(j=0;j<3;j++) c[j]+=ans[i].b[j];
			}
		}
		printf("%d. %d",t++,c[0]);
		for(k=1;k<3;k++) printf(" %d",c[k]);
		printf("\n");
		sscanf(ss,"%d%d",&p1,&p2);
	}
	return 0;
}