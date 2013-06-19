#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int ans[300];
int b[300];
char s1[300],s2[300];
bool cmp(const int &i,const int &j)
{
	return strcmp(s1+i,s1+j)<0;
}
void f(int x,int y)
{
	int i,a[300];
	for(i=0;i<300;i++)a[i]=0;
	i=x;
	if(s1[x]==s2[y]) a[x]=1;
	for(x++,y++;s1[x]&&s2[y];x++,y++)
	{
		if(s1[x]==s2[y])
			a[x]=a[x-1]+1;
		else a[x]=0;
	}
	for(;s1[i];i++)
		b[i]=b[i]>a[i]?b[i]:a[i];
}
int main()
{
	int t;
	int i,j;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		scanf("%s",s1);
		for(i=0;s1[i];i++) ans[i]=1000000;
		while(--t)
		{
			scanf("%s",s2);
			for(i=0;s1[i];i++) b[i]=0;
			for(i=0;s1[i];i++) f(i,0);
			for(i=0;s2[i];i++) f(0,i);
			for(i=0;s1[i];i++)
			{
				ans[i]=ans[i]<b[i]?ans[i]:b[i];
			}
		}
		for(j=i=0;s1[i];i++) j=ans[i]>j?ans[i]:j;
		if(j<3) printf("no significant commonalities\n");
		else
		{
			int k=0;
			for(i=0;s1[i];i++)
			{
				if(ans[i]==j) b[k++]=i-j+1;
			}
			sort(b,b+k,cmp);
			for(i=b[0];i<j+b[0];i++) printf("%c",s1[i]);
			printf("\n");
		}
	}
	return 0;
}