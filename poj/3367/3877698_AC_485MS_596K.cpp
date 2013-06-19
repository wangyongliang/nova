#include<stdio.h>
#include<string.h>
char s[100000];
struct node
{
	int l,r;
	char ch;
}ans[100000];
int stack[100000][2];
int m;
void build(int st,int en,int n)
{
	ans[n].l=ans[n].r=-1;
	ans[n].ch=s[en];
	if(st==en) return;
	int i,cnt1,cnt2;
	int j=0;
	stack[j][0]=stack[j][1]=st;
	j++;
	for(i=st+1;i<en;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			stack[j][0]=stack[j][1]=i;
			j++;
		}
		else
		{
			stack[j-2][1]=i;
			j--;
		}
	}
	ans[n].l=m++;
	ans[n].r=m++;
	int xx,yy;
	xx=stack[1][0];
	yy=stack[1][1];
	build(stack[0][0],stack[0][1],ans[n].l);
	build(xx,yy,ans[n].r);
}
int len;
int q[100000];
char ss[100000];
void bfs()
{
	int st=0,en=1,i=0;
	q[st]=1;
	while(st<en)
	{
		ss[i++]=ans[q[st]].ch;
		if(ans[q[st]].l!=-1)q[en++]=ans[q[st]].l;
		if(ans[q[st]].r!=-1) q[en++]=ans[q[st]].r;
		st++;
	}
}
int main()
{
	int t;
//	freopen("expressions_in.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		m=2;
		len=strlen(s);
		build(0,len-1,1);
		bfs();
		for(int i=len-1;i>=0;i--) printf("%c",ss[i]);
		printf("\n");
	}
	return 0;
}