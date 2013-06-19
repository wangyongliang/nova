#include<stdio.h>
#define maxn 500000009
int flag[maxn];
int main()
{
	int p,q;
	int t=1;
	int i;
	while(scanf("%d/%d",&p,&q)!=EOF)
	{
		for(i=0;i<=q;i++) flag[i]=0;
		flag[p]=1;
		i=1;
		while(1)
		{
			p*=2;
			i++;
			if(p>q) p-=q;
			if(flag[p]) break;
			else flag[p]=i;
		}
		printf("Case #%d: %d,%d\n",t++,flag[p],i-flag[p]);
	}
	return 0;
}
