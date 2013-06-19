#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[1000];
int main()
{
	int i,j;
	int cnt;
	int a[10]={0};
	while(scanf("%s",s)!=EOF)
	{
		for(i=0;i<10;i++) a[i]=0;
		for(i=0;s[i];i++) a[s[i]-'0']++;
		if(a[0]||a[5])
		{
			cnt=0;
			for(i=0;i<10;i++) cnt+=i*a[i];
			if(cnt%3==1)
			{
				j=0;
				for(i=1;i<10;i+=3)if(a[i]) {a[i]--;j=1;break;}
				if(!j)
				{
					j=2;
					for(i=2;i<10;i+=3)
					{
						if(i==5)
						{
							if(a[0]) 	while(a[i]&&j){	a[i]--;j--;	}
							else while(a[i]>1&&j){	a[i]--;j--;	}
						}
						else{while(a[i]&&j)	{a[i]--;j--;}}
					}
					if(j) goto line;
				}
			}
			else if(cnt%3==2)
			{
				j=0;
				for(i=2;i<10;i+=3)
				{
					if(i==5)
					{
						if(a[5]&&(a[5]>1||a[0])) {a[5]--;j=1;break;}
					}
					else	{if(a[i]) {a[i]--;j=1;break;}}
				}
				if(!j)
				{
					j=2;
					for(i=1;i<10;i+=3)
					{
						while(a[i]&&j)
						{
							a[i]--;j--;
						}
					}
					if(j) goto line;
				}
			}
			if(a[0])
			{
				for(i=9,cnt=0;i>=1;i--) 
				{
					while(a[i]){printf("%d",i);a[i]--;cnt++;};
				}
				if(cnt) 
				{
					while(a[0]){printf("0");a[0]--;};
				}
				else printf("0");
				printf("\n");
			}
			else if(a[5])
			{
				a[5]--;
				for(i=9;i>=0;i--) while(a[i]){printf("%d",i);a[i]--;};
				printf("5\n");
			}
			else printf("impossible\n");
		}
		else
		{
line:;
	 printf("impossible\n");
		}
	}
	return 0;
}