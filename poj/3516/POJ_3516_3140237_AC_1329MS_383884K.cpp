#include<stdio.h>
#include<string.h>
char flag[257][5000000]={0};
char s[300];
struct node
{
	int i,next;
	int num;
	int k;
}q[10000000];
int len,n,t=1;
void print(int i)
{
	if(q[i].next!=-1) print(q[i].next),printf("+");
	printf("%d",q[i].k);
}
void bfs()
{
	int i,j,k,m;
	int st=0,en=0;
	int flg=0;
	j=0;
	for(i=0;i<5&&i<len;i++)
	{
		j=j*10+s[i]-'0';
		if(j>n||j==0) continue;
		flag[i][j]=t;
		q[st].i=i;
		q[st].next=-1;
		q[st].num=j;
		q[st].k=j;
		st++;
	}
	en=st;
	st=0;
	while(st<en)
	{
		k=q[st].i;
		if(q[st].i==len-1&&q[st].num==n) break;
		j=0;
		if(s[k+1]!='0')
		{
			for(i=k+1;i<=k+5&&i<len;i++)
			{
				j=j*10+s[i]-'0';
				m=j+q[st].num;
				if(m>n||j==0) continue;
				if(flag[i][m]!=t)
				{
					flag[i][m]=t;
					q[en].i=i;
					q[en].next=st;
					q[en].num=m;
					q[en].k=j;
					en++;
				}
			}
		}
		st++;
	}
	if(flag[len-1][n]!=t) printf("IMPOSSIBLE\n");
	else
	{
		print(st);
		printf("=%d\n",n);
	}
	t++;
}
int main()
{
	char ss[300];
	int i,j;
	int st,en,sum=0;
	while(scanf("%s",ss))
	{
		if(strlen(ss)==3&&ss[0]=='0'&&ss[2]=='0') break;
		else
		{
			printf("%d. ",t);
			for(i=0;ss[i]!='=';i++)	s[i]=ss[i];
			len=i;			
			for(i++,n=0;ss[i];i++) n=n*10+ss[i]-'0';
			if(n>5000000)
			{
				printf("IMPOSSIBLE\n");
			}
			else 
				bfs();
		}
	}
	return 0;
}

