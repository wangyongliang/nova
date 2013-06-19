#include<stdio.h>
#include<string>
#include<map>
#include<vector>
using namespace std;
string str[10000];
map<string ,int > mp;
int fa[10000],k=1;
vector<int> a[10000],tp1,tp2;
void fire(int x)
{
	int i;
	tp2.clear();
	int j=-1;
	if(a[x].size())
	{
		j=a[x][0];
		for(i=1;i<a[x].size();i++) 
		{
			if(a[x][i]>0)tp2.push_back(a[x][i]);
		}
	}
	a[x].clear();
	if(j>0) a[x].push_back(j);
	for(i=0;i<tp1.size();i++) a[x].push_back(tp1[i]);
	tp1=tp2;
	if(j>0) fire(j);

}
int n;
void print(int x,int deep)
{
	int i,j=deep;
	while(j--) printf("+");
	printf("%s\n",str[x].c_str());
	for(i=0;i<a[x].size();i++) 
	{
		if(a[x][i]>0)
			print(a[x][i],deep+1);
	}
}
vector<int> ::iterator it;
bool flag[10000];
void init_fa()
{
	int i,j;
	for(i=0;i<k;i++)
	{
		for(it=a[i].begin();it!=a[i].end();)
		{
			if(*it==-1) 
			{
				it=a[i].erase(it);
					//it--;
			}
			else it++;
		}
	}
	
	for(i=0;i<k;i++)
	{
		fa[i]=i;
	}
	for(i=1;i<k;i++)
	{
		for(j=0;j<a[i].size();j++) 
		{
			if(a[i][j]>0)fa[a[i][j]]=i;
		}
	}
}

char s[100];
int main()
{
	char s1[100],s2[100];
	int i,j,l,ii;
	string str1,str2;
	for(i=0;i<2000;i++) 
	{
		a[i].clear(),fa[i]=i;
		flag[i]=0;
	}
	scanf("%s",s);
	str[k++]=s;
	mp[str[k-1]]=k-1;
	flag[1]=1;
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"print")==0)
		{
			for(i=1;i<k;i++)
			{
				if(i==fa[i]&&flag[i]) break;
			}
			print(i,0);
			printf("------------------------------------------------------------\n");
		}
		else if(strcmp(s,"fire")==0)
		{
			scanf("%s",s1);
			str1=s1;
			j=fa[mp[str1]];
			l=mp[str1];
			flag[l]=0;
			if(j!=l)
			{
				for(ii=0;ii<a[j].size();ii++)
				{
					if(a[j][ii]==l) break;
				}
				a[j][ii]=-1;
				if(a[l].size())
				{
					int tpp=a[l][0];
					a[j][ii]=a[l][0];
				}
			}
			tp1.clear(),tp2.clear();
			for(ii=1;ii<a[l].size();ii++) 
			{
				int tpp=a[l][ii];
				tp1.push_back(a[l][ii]);
			}
			if(a[l].size()) 	fire(a[l][0]);
			a[l].clear();
			mp[str1]=0;
			init_fa();
		}
		else
		{
			scanf("%s%s",s1,s2);
			str1=s;
			str[k++]=s2;
			mp[str[k-1]]=k-1;
			flag[k-1]=1;
			a[mp[str1]].push_back(k-1);
			a[k-1].clear();
			init_fa();
		}
	}
	return 0;
}