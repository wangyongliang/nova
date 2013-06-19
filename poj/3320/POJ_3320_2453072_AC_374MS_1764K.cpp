#include <stdio.h>
#include <map>

using namespace std;

#define maxn 1000001

int arr[maxn],Q[maxn],head,tail,ans,n,tot;
int cnt[maxn],index[maxn];
map<int,int> mp;

int main()
{
	int i,num=1,x;
	ans = 0x7FFFFFFF;
	head = tail = 0;
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
		x = mp[arr[i]];
		if (x==0)
		{
			index[i] = num;
			mp[arr[i]] = num++;
		}
		else
		{
			index[i] = x;
		}
	}
	if (num==2)
	{
		printf("1\n");
		return 0;
	}
	Q[tail++] = index[0];
	cnt[index[0]] = 1;
	int cur = 1;
	for (i=1; i<n; i++)
	{
		if (cnt[index[i]])
		{
			Q[tail++] = index[i];
			cnt[index[i]]++;
		}
		else
		{
			cur++;
			Q[tail++] = index[i];
			cnt[index[i]] ++;
		}
		while (cnt[Q[head]]>1)
		{
			cnt[Q[head]]--;
			head++;
		}
		if (cur == num-1 && tail-head<ans)
		{
			ans = tail-head;
		}
	}
	printf("%d\n",ans);
	return 0;
} 


