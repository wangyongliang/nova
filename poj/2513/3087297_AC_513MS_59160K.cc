#include<stdio.h>
#define maxn 5000000
struct node
{
	int index[26];
	int data;
}a[maxn];
int n,m,cnt[maxn],flag[maxn];
void build()
{
	int i,j;
	n=0;
	m=27;
	for(i=0;i<26;i++) a[0].index[i]=i+1;
	for(i=1;i<27;i++)
	{
		a[i].data=-1;
		for(j=0;j<26;j++) a[i].index[j]=-1;
	}
}
int insert(char s[],int j,int i)
{
	if(s[j+1])
	{
		if(a[i].index[s[j+1]-'a']==-1)
		{
			for(int k=0;k<26;k++) a[m].index[k]=-1;
			a[m].data=-1;
			a[i].index[s[j+1]-'a']=m++;
		}
		return insert(s,j+1,a[i].index[s[j+1]-'a']);
	}
	else
	{
		if(a[i].data==-1) 
		{
			a[i].data=n;
			cnt[n]=1;
			flag[n]=n++;
		}
		else cnt[a[i].data]++;
		return a[i].data;
	}
}
int find(int x)
{
	int y=x,z;
	while(flag[x]!=x) x=flag[x];
	while(flag[y]!=y)
	{
		z=y;
		y=flag[y];
		flag[z]=x;
	}
	return x;
}
int main()
{
	int i,j;
	char s1[100],s2[100];
	build();
	int x,y;
	//freopen("H.6.dat","r",stdin);
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		x=insert(s1,0,a[0].index[s1[0]-'a']);
		y=insert(s2,0,a[0].index[s2[0]-'a']);
		x=find(x);
		y=find(y);
		flag[y]=x;
	}
	x=find(0);
	for(j=i=0;i<n;i++)
	{
		if(find(i)!=x) break;
		if(cnt[i]&1) j++;
	}
	if((j==0||j==2)&&i==n)  printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}