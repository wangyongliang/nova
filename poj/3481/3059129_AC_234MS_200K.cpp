#include<stdio.h>
#include<set>
using namespace std;
struct node
{
	int x,y;
};
bool operator <(const node &x,const node &y)
{
	return x.y<y.y;
}
set<node> a;
set<node> ::iterator it;
int main()
{
	int i,n,j;
	node temp;
	int cnt=0;
	a.clear();
	while(scanf("%d",&n)&&n)
	{
		if(n==1)
		{
			scanf("%d%d",&temp.x,&temp.y);
			a.insert(temp);
			cnt++;
		}
		else if(n==3)
		{
			it=a.begin();
			if(cnt==0) printf("0\n");
			else 
			{
				printf("%d\n",it->x);;
				a.erase(it);
				cnt--;
			}
		}
		else
		{
			if(cnt)
			{
				it=a.end();
				it--;
				printf("%d\n",it->x);
				a.erase(it);
				cnt--;
			}
			else printf("0\n");
		}
	}
	return 0;
}