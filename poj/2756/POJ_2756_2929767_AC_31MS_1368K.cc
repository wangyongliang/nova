//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#include<stdio.h>
#include<string.h>
#define maxn 100000
int ans[maxn];
char s1[maxn],s2[maxn];
void f(int a[],int b[])
{
	int i;
	for(i=maxn-1;i>0;i--)
	{
		ans[i]=(a[i]+b[i])%10;
		a[i-1]+=(a[i]+b[i])/10;
	}
}
void g(int a[],int b[])
{
	int i;
	for(i=maxn-1;i>0;i--)
	{
		if(a[i]>=b[i]) ans[i]=a[i]-b[i];
		else 
		{
			ans[i]=a[i]+10-b[i];
			a[i-1]--;
		}
	}
}
int a[maxn],b[maxn];
int check()
{
	int i,j;
	for(i=0;i<maxn;i++)
	{
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}
int main()
{
	int t;
	int i,j;
	int flag1,flag2;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%s %s",s1,s2);
		for(i=0;i<maxn;i++)a[i]=b[i]=0;
		flag1=flag2=1;
		if(s1[0]=='-') flag1=0;
		if(s2[0]=='-') flag2=0;
		for(j=maxn-1,i=strlen(s1)-1;i>=0;i--,j--)
		{
			if(s1[i]=='-'||s1[i]=='+') break;
			a[j]=s1[i]-'0';
		}
		for(j=maxn-1,i=strlen(s2)-1;i>=0;i--,j--)
		{
			if(s2[i]=='-'||s2[i]=='+') break;
			b[j]=s2[i]-'0';
		}
		if(flag1==1&&flag2==1)
		{
			f(a,b);	
			for(i=0;ans[i]==0&&i<maxn;i++) ;
			if(i<maxn)	for(;i<maxn;i++) printf("%d",ans[i]);
			else printf("0");
		}
		else if(flag1==1&&flag2==0)
		{
			flag1=check();
			if(flag1==1)
			{
				g(a,b);
			}
			else if(flag1==0)
			{
				printf("0\n") ;continue;
			}
			else 
			{
				g(b,a);
				printf("-");
			}
			for(i=0;!ans[i];i++);
			for(;i<maxn;i++)
			{
				printf("%d",ans[i]);
			}
		}
		else if(flag1==0&&flag2==1)
		{
			flag1=check();
		//	printf("%d\n",flag1);
			if(flag1==1)
			{
				g(a,b);
				printf("-");
		//		printf("dsf\n");
			//	gets();
			}
			else if(flag1==0)
			{
				printf("0\n") ;continue;
			}
			else 	g(b,a);
			for(i=0;!ans[i];i++);
			for(;i<maxn;i++)
			{
				printf("%d",ans[i]);
			}
		}
		else
		{
			f(a,b);
			printf("-");
			for(i=0;ans[i]==0&&i<maxn;i++) ;
			for(;i<maxn;i++) printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

