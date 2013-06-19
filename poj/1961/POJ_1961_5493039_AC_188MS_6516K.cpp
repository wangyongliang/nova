#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char str[2000000];
int next[2000000];
void get_next()
{
	int i,j;
	next[0]=-1;
	j=-1;
	i=0;
	int n=strlen(str);
	while(i<n)
	{
		if(j==-1||str[j]==str[i])
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
		
	}
}

vector<pair<int,int> >ans;
int main()
{
	int t;
	int n;
	int i;
	int j;
	t=1;
	while(scanf("%d",&n)&&n)
	{
		scanf("%s",str);
		str[n]=96;
		str[n+1]=0;
		get_next();
		ans.clear();
		for(i=1;i<n;i++)
		{
			if(next[i+1]*2==i+1)
			{
				int k=next[i+1];
				for(j=0;j*k+i<n;j++)
				{
					if(next[j*k+i+1]==next[i+1]+j*k)
					{
						pair<int,int> tmp;
						tmp.first=j*k+1+i;
						tmp.second=j+2;
		
						ans.push_back(tmp);
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		printf("Test case #%d\n",t++);
		for(i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
		printf("\n");

	}
	return 0;
}
