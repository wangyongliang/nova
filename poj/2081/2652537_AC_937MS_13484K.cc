#include<stdio.h>
#include<set>
using namespace std;
set<int> mp;
	int a[500009];
int main()
{
	int i,j;
	a[0]=0;
	mp.clear();
	mp.insert(0);
	for(i=1;i<=500000;i++)
	{
		j=a[i-1]-i;
		if(j>0)
		{
			if(mp.find(j)==mp.end())
			{
				a[i]=j;
				mp.insert(j);
			}
			else
			{
				a[i]=a[i-1]+i;
				mp.insert(a[i]);
			}
		}
		else
		{
			a[i]=a[i-1]+i;
			mp.insert(a[i]);
		}
	}
	while(scanf("%d",&i)&&i!=-1)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
