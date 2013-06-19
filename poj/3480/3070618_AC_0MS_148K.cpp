#include<stdio.h>
int main()
{
	int ans,cnt,i,n,x;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>1) cnt++;
			ans^=x;
		}
		if(cnt==1) printf("John\n");
		else if(cnt==0)
		{
			if(n%2) printf("Brother\n");
			else printf("John\n");
		}
		else
		{
			if(ans==0) printf("Brother\n");
			else printf("John\n");
		}
	}
	return 0;
}
