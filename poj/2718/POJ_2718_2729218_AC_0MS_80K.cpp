#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int ans[11];
int n,min;
void f(int t1,int t2)
{
	int flag[12]={0};
	int i,j;
	flag[t1]=flag[t2]=1;
	t1=ans[t1];
	t2=ans[t2];
	j=n/2+n%2-1;
	for(i=0;j;i++)
	{
		if(!flag[i])
		{
			t1=t1*10+ans[i];
			flag[i]=1;
			j--;
		}
	}
	for(i=n-1,j=n/2+n%2-1;j;i--)
	{
		if(!flag[i])
		{
			t2=t2*10+ans[i];
			flag[i]=1;
			j--;
		}
	}
	min=abs(t1-t2)<min?abs(t1-t2):min;
}
int main()
{
	char s[30];
	int t,i,j,k;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		n=0;
		for(j=i=0;s[i];i++)
		{
			if(s[i]>='0'&&s[i]<='9') 
			{
				ans[j++]=s[i]-'0';
				n++;
			}
		}
		if(n==2)
		{
			printf("%d\n",ans[1]-ans[0]);
			continue;
		} 
		if(ans[0]) i=1;
		else i=2;
		min=999999;
		if(n&1)
		{
			j=k=0;
			if(ans[0]) j=ans[0]*10+ans[1];
			else j=ans[1]*10;
			for(i=2;i<=n/2;i++) j=j*10+ans[i];
			for(i=n-1;i>n/2;i--) k=k*10+ans[i];
			min=j-k;
		}
		else
		{
			for(j=10;i<n;i++)
			{
				if(ans[i]-ans[i-1]<j) j=ans[i]-ans[i-1];
			}
			if(ans[0]) i=0;
			else i=1;
			for(;i<n-1;i++)
			{
				if(ans[i+1]-ans[i]==j)
				{
					f(i+1,i);
				}
			}
		}
		printf("%d\n",min);
	//	printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
