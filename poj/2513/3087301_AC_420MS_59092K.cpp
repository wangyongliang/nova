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
int insert(char s[])
{
	int i,j,l;
	j=a[0].index[s[0]-'a'];
	for(i=1;s[i];i++)
	{
		if(a[j].index[s[i]-'a']==-1)
		{
			for(l=0;l<26;l++) a[m].index[l]=-1;
			a[m].data=-1;
			a[j].index[s[i]-'a']=m++;
		}
		j=a[j].index[s[i]-'a'];
	}
	if(a[j].data==-1) 
	{
		a[j].data=n++;
		flag[a[j].data]=n-1;
		cnt[n-1]=1;
	}
	else cnt[a[j].data]++;
	return a[j].data;
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
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		x=insert(s1);
		y=insert(s2);
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