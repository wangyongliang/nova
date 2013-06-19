#include<stdio.h>
#include<stdlib.h>
char a[10000]={'\0'};
void prime()
{
	int i,j,k=0;
	a[0]=a[1]=1;
	a[2]='\0';
	for(i=2;i<10000;i++)
	{
		if(a[i]=='\0')
		{
			for(j=i+i;j<10000;j+=i)
			{
				a[j]=1;
			}
		}
	}
}
int bfs(int n,int m)
{
	int b[1100],i,j,start=0,end=2,k,path=0;
	char c[10000]={'\0'};
	b[0]=n;
	b[1]=-1;
	char s[5],ch;
	for(;start!=end;)
	{
		i=b[start++];
		if(i==-1)path++,i=b[start++],b[end++]=-1;
		if(i==m) return path;
		c[i]=1;
		itoa(i,s,10);
		for(i=0;s[i];i++)
		{
			ch=s[i];
			for(k='0';k<='9';k++)
			{
				if((i==0&&k=='0')||k==ch) continue;
				s[i]=k;
				j=atoi(s);
				if(!a[j]&&!c[j]) 
					b[end++]=j,c[j]=1;
			}
			s[i]=ch;
		}
	}
}
void main()
{
	int n,m,k;
	prime();
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",bfs(n,m));
	}
}
