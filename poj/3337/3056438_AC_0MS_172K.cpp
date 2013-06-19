#include<stdio.h>
int main()
{
	int a[300],i,j;
	bool flag[300];
	int q[100],qq;
	int t;
	char s[1000];
	scanf("%d",&t);
	int flg,ans,last;
	gets(s);
	while(t--)
	{
		gets(s);
		for(i='a';i<='z';i++) a[i]=i-'a'+1,flag[i]=0;
		qq=0;
		last=0;
		ans=0;
		flg=0;
		for(i=0;s[i];i++)
		{
			if(s[i]=='+')
			{
				q[qq++]=1;
				if(qq==2&&q[0]==q[1])
				{
					if(last)a[last]++;
					else flg=1;
					qq=0;
				}
				else if(qq==3)
				{
					qq=1;
					flg=1;
				}
			}
			else if(s[i]=='-')
			{
				q[qq++]=0;
				if(qq==2&&q[0]==q[1])
				{
					if(last)a[last]--;
					else flg=-1;
					qq=0;
				}
				else if(qq==3)
				{
					qq=1;
					flg=-1;
				}
			}
			else if(s[i]>='a'&&s[i]<='z')
			{
				a[s[i]]+=flg;
				last=s[i];
				flag[s[i]]=1;
				flg=0;
				if(qq==0) ans=a[s[i]];
				else
				{
					if(q[0]==1) ans+=a[s[i]];
					else ans-=a[s[i]];
				}
				qq=0;
			}
			
		}
		printf("Expression: %s\n",s);
		printf("value = %d\n",ans);
		for(i='a';i<='z';i++)
		{
			if(flag[i])
			{
				printf("%c = %d\n",i,a[i]);
			}
		}
	}
	return 0;
}