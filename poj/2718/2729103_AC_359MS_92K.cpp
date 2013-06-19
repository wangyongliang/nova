#include<stdio.h>
#include<math.h>
#include<stdlib.h>
bool flag[10];
int a[11],n,min;
int ans1,ans2;
void dfs(int deep,int t1,int t2)
{
	int i;
	int temp,k,tp;
	k=n/2+n%2;
	if(deep==n)
	{
		if(abs(t1-t2)<min)
		{
			min=abs(t1-t2);
			ans1=t1;
			ans2=t2;
		}
	}
	if(deep<k)
	{
		if(deep==0) i=1;
		else i=0;
		for(;i<10;i++)
		{
			if(flag[i])
			{
				flag[i]=0;
				dfs(deep+1,t1*10+i,t2);
				flag[i]=1;
			}
		}
	}
	else 
	{
		if(deep==k) i=1;
		else i=0;
		for(;i<10;i++)
		{
			if(flag[i])
			{
				tp=pow(10,n-deep-1);
				temp=t2+i*tp;
				if(abs(temp-t1)<min+tp)
				{
					flag[i]=0;
					dfs(deep+1,t1,temp);
					flag[i]=1;
				}
			}
		}
	}
}
int main()
{
	char s[30];
	int t,i,j;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		for(i=0;i<10;i++) flag[i]=0;
		n=0;
		for(j=i=0;s[i];i++)
		{
			if(s[i]>='0'&&s[i]<='9') 
			{
				flag[s[i]-'0']=1;
				n++;
			}
		}
		if(n==2)
		{
			for(i=0;i<10&&flag[i]==0;i++);
			for(j=i+1;!flag[j];j++);
			printf("%d\n",j-i);
			continue;
		} 
		min=999999;
		dfs(0,0,0);
		printf("%d\n",min);
	//	printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
