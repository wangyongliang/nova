#include<iostream>
#include<algorithm>
using namespace std;

int a[10000];
int main()
{
    int n,p,c;
    int i,j,st,en;
    int cnt;
    int ans;
    while(scanf("%d%d%d",&n,&p,&c)!=EOF)
    {
		if(p==1) while(1);
		for(i=0;i<p;i++) a[i]=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&j);
			a[j]++;
		}
		st=1;
		ans=0;
		cnt=0;
		for(i=1;i<p;i++)
		{
			cnt+=a[i];
	//		printf("cnt1= %d\n",cnt);
			while(cnt>c)
			{
				cnt-=a[st];
				st++;
			}
	//		printf("cnt2 =%d  st =%d\n",cnt,st);
			if(i-st+1>ans)
			{
				 ans=i-st+1;
		//		 printf("%d\n",ans);
				}
		}	
		if(i-st>ans) ans=i-st;
	printf("%d\n",ans);
	}

	return 0;                                    
}
