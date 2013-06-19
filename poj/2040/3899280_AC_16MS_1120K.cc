#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
struct node
{
	int x,y;
};
vector<node> a1[300],a2[300],tp;
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
string str1[300],str2[300];
map<string,int> mp1,mp2;
int k1,k2;

int b1[300][300],b2[300][300];
int in1[300],out1[300],in2[300],out2[300];
int index[300];
int m;

struct tra
{
	string s1,s2;
}ans[300];
bool cp(const tra &x,const tra &y)
{
	return x.s1<y.s1;
}
void print(int k)
{
	printf("-----language 1------\n");
	int i,j;
	for(i=1;i<k;i++)
	{
		printf("%s\n",str1[i].c_str());
		for(j=0;j<a1[i].size();j++) 
		{
			printf("(%d %d) ",a1[i][j].x,a1[i][j].y);
		}
		printf("\n");
	}printf("-----language 2------\n");

	for(i=1;i<k;i++)
	{
		printf("%s\n",str2[i].c_str());
		for(j=0;j<a2[i].size();j++) 
		{
			printf("(%d %d) ",a2[i][j].x,a2[i][j].y);
		}
		printf("\n");
	}
}

bool ck()
{
	int  i,j;
	for(i=1;i<m;i++)
	{
		for(j=1;j<m;j++)
		{
			if(index[i]>0&&index[j]>0)
			{
			if(b1[i][j]!=b2[index[i]][index[j]]) return 0;
			}
		}
	}
	return 1;
}
int flag;
int eq(int i,int j)
{
	int k;
	if(a1[i].size()!=a2[j].size()) return 0;
	for(k=0;k<a1[i].size();k++)
	{
		if(a1[i][k].x==a2[j][k].x&&a1[i][k].y==a2[j][k].y) ;
		else return 0;
	}
	return 1;
}
int use[300];
void dfs(int deep)
{
	int i,j;
	if(flag) return;
	if(deep==m)
	{
		flag=ck();
		if(flag) return ;
	}
	else
	{
		for(i=1;i<m;i++)
		{
			if(use[i]&&eq(deep,i))
			{
				index[deep]=i;
				if(ck()){
				use[i]=0;
				index[deep]=i;
				dfs(deep+1);
				if(flag) return ;
				use[i]=1;
				}
				index[deep]=-1;
			}
		}
	}
}

int main()
{
	int n;
	int i,j;
	char s1[100],s2[100];
	node tpp;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<300;i++) 
		{
			a1[i].clear();
			a2[i].clear();
			for(j=0;j<300;j++) b1[i][j]=b2[i][j]=0;
			in1[i]=in2[i]=0;
			out1[i]=out2[i]=0;
		}
		mp1.clear();
		mp2.clear();
		k1=k2=1;
		for(i=0;i<n;i++)
		{
			scanf("%s%s",s1,s2);
			string tps1,tps2;
			tps1=s1;
			tps2=s2;
			if(mp1[tps1]==0) 
			{
				str1[k1]=tps1;
				mp1[tps1]=k1++;
			}
			if(mp1[tps2]==0)
			{
				str1[k1]=tps2;
				mp1[tps2]=k1++;
			}
			int ii=mp1[tps1];
			int jj=mp1[tps2];
			b1[ii][jj]=1;
			in1[jj]++;
			out1[ii]++;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s%s",s1,s2);
			string tps1,tps2;
			tps1=s1;
			tps2=s2;
			if(mp2[tps1]==0) 
			{
				str2[k2]=tps1;
				mp2[tps1]=k2++;
			}
			if(mp2[tps2]==0)
			{
				str2[k2]=tps2;
				mp2[tps2]=k2++;
			}
			int ii=mp2[tps1];
			int jj=mp2[tps2];
			b2[ii][jj]=1;
			in2[jj]++;
			out2[ii]++;
		}
		for(i=1;i<k1;i++)
		{
			tpp.x=in1[i];
			tpp.y=out1[i];
			a1[i].push_back(tpp);
			tp.clear();
			for(j=1;j<k2;j++)
			{
				if(b1[i][j])
				{
					tpp.x=in1[j];
					tpp.y=out1[j];
					tp.push_back(tpp);
				}
			}
			sort(tp.begin(),tp.end(),cmp);
			for(j=0;j<tp.size();j++) a1[i].push_back(tp[j]);
			tpp.x=-1;
			tpp.y=-1;
			a1[i].push_back(tpp);
			tp.clear();
			for(j=1;j<k2;j++)
			{
				if(b1[j][i])
				{
					tpp.x=in1[j];
					tpp.y=out1[j];
					tp.push_back(tpp);
				}
			}
			sort(tp.begin(),tp.end(),cmp);
			for(j=0;j<tp.size();j++) a1[i].push_back(tp[j]);
		}
		
		for(i=1;i<k1;i++)
		{
			tpp.x=in2[i];
			tpp.y=out2[i];
			a2[i].push_back(tpp);
			tp.clear();
			for(j=1;j<k2;j++)
			{
				if(b2[i][j])
				{
					tpp.x=in2[j];
					tpp.y=out2[j];
					tp.push_back(tpp);
				}
			}
			sort(tp.begin(),tp.end(),cmp);
			for(j=0;j<tp.size();j++) a2[i].push_back(tp[j]);
			tpp.x=-1;
			tpp.y=-1;
			a2[i].push_back(tpp);
			tp.clear();
			for(j=1;j<k2;j++)
			{
				if(b2[j][i])
				{
					tpp.x=in2[j];
					tpp.y=out2[j];
					tp.push_back(tpp);
				}
			}
			sort(tp.begin(),tp.end(),cmp);
			for(j=0;j<tp.size();j++) a2[i].push_back(tp[j]);
		}
	//	print(k1);
	/*	for(i=1;i<k1;i++)
		{
			for(j=1;j<k1;j++)
			{
				if(a1[i].size()==a2[j].size())
				{
					for(k=0;k<a1[i].size();k++)
					{
						if(a1[i][k].x!=a2[j][k].x||a1[i][k].y!=a2[j][k].y) break;
					}
					if(k==a1[i].size())
					{
						ans[i].s1=str1[i];
						ans[i].s2=str2[j];
						break;
					}
				}
			}
		}*/
		flag=0;
		m=k1;
		for(i=1;i<m;i++) use[i]=1,index[i]=-1;
		dfs(1);
		for(i=1;i<m;i++)
		{
			ans[i].s1=str1[i];
			ans[i].s2=str2[index[i]];
		}
		sort(ans+1,ans+k1,cp);
		for(i=1;i<k1;i++)
		{
			printf("%s/%s\n",ans[i].s1.c_str(),ans[i].s2.c_str());
		}
		printf("\n");
	}
	return 0;
}