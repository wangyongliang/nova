

//pku 1468 1470 的其他方法

//pku 2559,3250 的共同点

//pku1690--pku1697

#include<stdio.h>
#include<set>
using namespace std;
set<int> a;
set<int>::iterator it;
int time[500010];
int ans[1000];
int main()
{
	int  n,i,j,t;
	char s[10];
	int x;
	int tt=1;
	while(scanf("%d",&n)&&n)
	{
		printf("Case %d:\n",tt++);
		for(i=0;i<1000;i++) ans[i]=i-1;
		a.clear();
		t=1;
		while(n--)
		{
			scanf("%s%d",s,&x);			
			if(s[0]=='B')
			{
				time[x]=t++;
				for(i=1;i<700;i++)
				{
					if(ans[i]%i>=x%i) ans[i]=x;
				}
				a.insert(x);
			}
			else
			{
				if(t==1) printf("-1\n");
				else
				{
					if(x<700) printf("%d\n",time[ans[x]]);
					else
					{
						it=a.upper_bound(0);
						i=(*it);
						for(j=1;j*x<500100;j++)
						{
							it=a.upper_bound(j*x-1);
							if(it==a.end()) break;
							if((*it)%x<(i%x)||(*it%x==i%x&&time[*it]>time[i])) i=*it;
						}
						printf("%d\n",time[i]);
					}					
				}
			}
		}
		printf("\n");
	}
	return 0;
}