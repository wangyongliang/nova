#include<stdio.h>
int cnt[20][2];
int main()
{
	int a,b,c,s;
	int i,j;
	while(scanf("%d",&a)&&a)
	{
		scanf("%d%d%d",&b,&c,&s);
		for(i=0;i<16;i++) cnt[i][0]=cnt[i][1]=0;
		for(i=0;i<=c;i++)
		{
			for(j=0;j<16;j++)
			{
				if(s&(1<<j)) cnt[j][1]++;
				else cnt[j][0]++;
			}
			s=(a*s+b)%c;
		}
		for(i=15;i>=0;i--)
		{
			if(cnt[i][1]==0) printf("0");
			else if(cnt[i][0]==0) printf("1");
			else printf("?");
		}
		printf("\n");
	}
	return 0;
}
