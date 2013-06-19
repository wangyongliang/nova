#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
int n;
char s[110][30];
struct node
{
	int index;
	int age;
	int diff;
}ans[110];
vector <node> a[110];
map <string,int> mp;
void bfs()
{
	int q[300];
	int i=0,j,k;
	q[0]=1;
	j=1;
	vector<node>::iterator it;
	while(i<j)
	{
		k=q[i];
		for(it=a[k].begin();it!=a[k].end();it++)
		{
			ans[it->index].age=ans[k].age-it->diff;
			q[j++]=it->index;
		}
		i++;
	}
}
bool cmp(const node &x,const node &y)
{
	if(x.age==y.age) return strcmp(s[x.index],s[y.index])<0;
	return x.age>y.age;
}
int main()
{
	int i,j,k,m,tp,t;
	node temp;
	char s1[30],s2[30];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		mp.clear();
		strcpy(s[1],"Ted");
		mp["Ted"]=1;
		ans[1].age=100;
		ans[1].index=1;
		scanf("%d",&n);
		for(i=1;i<=n+1;i++) 
		{
			a[i].clear();
			ans[i].index=i;
		}
		for(i=0,j=2;i<n;i++)
		{
			scanf("%s%s%d",s1,s2,&m);
			string str(s1);
			string st(s2);
			if(mp[str]==0) 
			{
				strcpy(s[j],s1);
				mp[str]=j++;
			}
			if(mp[st]==0) 
			{
				strcpy(s[j],s2);
				mp[st]=j++;
			}
			temp.index=mp[st];
			temp.diff=m;
			a[mp[str]].push_back(temp);
		}
		bfs();
		sort(ans+2,ans+n+2,cmp);
		printf("DATASET %d\n",k);
		for(i=2;i<=n+1;i++)
		{
			printf("%s %d\n",s[ans[i].index],ans[i].age);
		}
	}
	return 0;
}
