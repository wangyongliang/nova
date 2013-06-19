#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define ABS(x) (x)>0?(x):-(x)
#define SP(x) setprecision(x)
using namespace std;
#define maxn 101000
int n,m,l;
int a[maxn],p[maxn];
int cnt1[maxn][26],cnt2[maxn][26];
int next[maxn];
int check(int x,int y,int tp1[][26],int tp2[][26],int s1[],int s2[])
{
	if((tp1[x-1][s1[x]]==-1||x-tp1[x-1][s1[x]]>y)&&(y==0||tp2[y-1][s2[y]]==-1));
	else
	{
		if(x-tp1[x-1][s1[x]]!=y-tp2[y-1][s2[y]]) return 0;
	}
	int xx,yy;
	for(xx=s1[x]-1;xx>=0&&(tp1[x][xx]==-1||x-tp1[x][xx]>y);xx--);
	for(yy=s2[y]-1;yy>=0&&(tp2[y][yy]==-1);yy--)
		;
	if(xx==-1&&yy==-1);
	else 
	{
		if(x-tp1[x][xx]!=y-tp2[y][yy]) return 0;
	}
	for(xx=s1[x]+1;xx<=l&&(tp1[x][xx]==-1||x-tp1[x][xx]>y);xx++);
	for(yy=s2[y]+1;yy<=l&&(tp2[y][yy]==-1);yy++);
	if(xx==l+1&&yy==l+1) return 1;
	else
	{
		if(x-tp1[x][xx]!=y-tp2[y][yy]) return 0;
		else return 1;
	}
}
void getnext()
{
	int i,j;
	for(j=0;j<=l;j++) cnt2[0][j]=cnt1[0][j]=-1;
	for(i=0;i<m;i++)
	{
		cnt1[i][p[i]]=i;
		for(j=0;j<=l;j++) cnt1[i+1][j]=cnt1[i][j];
	}
	next[0]=-1;
	i=0;
	j=-1;
	while(i<m)
	{
		if(j<1||check(i,j,cnt1,cnt1,p,p))
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
vector<int> ans;
void kmp()
{
	
	int i,j;
	for(i=0;i<=l;i++) cnt2[0][i]=-1;
	for(i=0;i<n;i++)
	{
		cnt2[i][a[i]]=i;
		for(j=0;j<=l;j++) cnt2[i+1][j]=cnt2[i][j];
	}
	i=j=0;
	ans.clear();
	while(i<n)
	{
		if(j==-1||check(i,j,cnt2,cnt1,a,p))
		{
			i++;
			j++;
		}
		else j=next[j];
		if(j==m)
		{
			ans.push_back(i-m);
			i--;
			j=next[m-1];
		}
	}
}
int main()
{
	int i;
//	freopen("cpattern6.in","r",stdin);
	//freopen("1.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&l)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<m;i++) scanf("%d",&p[i]);
		getnext();
		kmp();
	//	for(i=0;i<m;i++) printf("%d ",next[i]);
	//	printf("\n");
	//	printf("----------------\n");
		printf("%d\n",ans.size());
		for(i=0;i<ans.size();i++) printf("%d\n",ans[i]+1);
	//	printf("\n");
	}
	return 0;
}
