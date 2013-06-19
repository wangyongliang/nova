#include<stdio.h>
#include<map>
#include<string>
#include<vector >
using namespace std;
map<string,int> mp;
int m,b;
struct node
{
	int x,y;
};
vector <node> a[10000];
int f(int mid)
{
	int ans=0,min,i,j;
	for(i=1;i<m;i++)
	{
		for(min=0;min<a[i].size();min++)
		{
			if(a[i][min].y>=mid) break;
		}
		for(j=min;j<a[i].size();j++)
		{
			if(a[i][j].y>=mid&&a[i][j].x<a[i][min].x) min=j;
		}
		if(min==a[i].size()) return 0;
		else ans+=a[i][min].x;
		if(ans>b) return 0;
	}
	return 1;
}
int main()
{
	char s[1000];
	int t,n,i,j,ans;
	scanf("%d",&t);
	node temp;
	while(t--)
	{
		scanf("%d%d",&n,&b);
		mp.clear();
		for(i=1;i<n;i++) a[i].clear();
		m=1;
		int min,max,mid;
		for(i=0;i<n;i++)
		{
			scanf("%s%*s%d%d",s,&temp.x,&temp.y);
			if(!i) min=max=temp.y;
			else
			{
				min=min<temp.y?min:temp.y;
				max=max<temp.y?temp.y:max;
			}
			string str(s);
			if(mp[str]==0) mp[str]=m++;
			a[mp[str]].push_back(temp);
		}
		ans=0;
		while(min<max)
		{
			mid=(min+max)/2;
			if(f(mid))
			{
				min=mid+1;
				ans=ans<mid?mid:ans;
			}
			else max=mid;
		}
		if(f(min)) ans=ans<min?min:ans;
		printf("%d\n",ans);
	}
	return 0;
}

