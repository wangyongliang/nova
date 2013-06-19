#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int num;
	char name[30];
	char ch;
	int year;
}a[100];
bool cmp(const node &n,const node &m)
{
	return n.num<m.num;
}
int b[27];
int main()
{
	char s[300];
	bool flag[22];
	int i,j,k;
	int temp1,flag1,temp2;
	while(1)
	{
		for(i=0;i<22;i++)
		{
			gets(s);
			if(strlen(s)==1&&s[0]=='0') goto line;
			a[i].num=0;
			for(j=0;s[j]!=' ';j++) a[i].num=a[i].num*10+s[j]-'0';
			for(j++,k=0;s[j]!=' ';j++)	a[i].name[k++]=s[j];
			a[i].name[k]='\0';
			a[i].ch=s[++j];
			for(j+=2,temp2=flag1=temp1=a[i].year=0;s[j];j++)
			{
				if(s[j]=='-')
				{
					flag1=1;
					continue;
				}
				if(s[j]==' ') 
				{
					if(flag1) 
					{
						a[i].year+=temp2-temp1+1;
						temp1=temp2=0;
					}
					flag1=0;
					continue;
				}
				if(!flag1) temp1=temp1*10+s[j]-'0';
				else temp2=temp2*10+s[j]-'0';
			}
			a[i].year+=temp2-temp1+1;
		}
		sort(a,a+22,cmp);
		scanf("%s",s);
		getchar();
		for(i=0;i<22;i++) flag[i]=0;
		b['G'-'A']=1;
		b['D'-'A']=s[0]-'0';
		b['M'-'A']=s[2]-'0';
		b['S'-'A']=s[4]-'0';
		for(i=0;i<22;i++)
		{
			if(b[a[i].ch-'A']>0)
			{
				flag[i]=1;
				b[a[i].ch-'A']--;
			}
		}
		if(b['G'-'A']||b['D'-'A']||b['M'-'A']||b['S'-'A'])
			printf("IMPOSSIBLE TO ARRANGE\n");
		else
		{
			for(i=0;flag[i]==0;i++);
			for(j=i;i<22;i++)
			{
				if(flag[i])
				{
					if(a[i].year>a[j].year) j=i;
					if(a[i].year==a[j].year&&a[i].num>a[j].num) j=i;
				}
			}
			printf("%d %s %c\n",a[j].num,a[j].name,a[j].ch);
			flag[j]=0;
			for(i=0;i<22;i++)
			{
				if(flag[i]&&a[i].ch=='G') printf("%d %s %c\n",a[i].num,a[i].name,a[i].ch);
			}
			for(i=0;i<22;i++)
			{
				if(flag[i]&&a[i].ch=='D') printf("%d %s %c\n",a[i].num,a[i].name,a[i].ch);
			}
			for(i=0;i<22;i++)
			{
				if(flag[i]&&a[i].ch=='M') printf("%d %s %c\n",a[i].num,a[i].name,a[i].ch);
			}
			for(i=0;i<22;i++)
			{
				if(flag[i]&&a[i].ch=='S') printf("%d %s %c\n",a[i].num,a[i].name,a[i].ch);
			}
		}
		
	}
line:
	return 0;
}
