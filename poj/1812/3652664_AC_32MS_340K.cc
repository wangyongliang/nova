#include<stdio.h>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
map<string,int> mp;
struct node
{
	char ch;
	int cnt;
};
void ck(node b[30] ,int &n,int k)
{
	int i;
	for(i=k;i+1<n;i++) b[i]=b[i+1];
	n--;
	if(k&&b[k-1].ch==b[k].ch) 
	{
		b[k-1].cnt+=b[k].cnt;
		for(i=k;i+1<n;i++) b[i]=b[i+1];
		n--;
	}
	for(i=0;i<n&&b[i].cnt<3;i++);
	if(i==n) return;
	else ck(b,n,i);
}
int flag[30],ans;
char s[30];
void dfs(int deep,node a[30],int n)
{
	int i,j;
	node tp[30];
	if(n==0)
	{
		j=0;
		for(i=0;s[i];i++) j+=flag[i];
		if(ans>j)
		{
			for(i=0;s[i];i++) 
			{
	//			if(flag[i]) printf("%c",s[i]);
			}
	//		printf("\n");
		}
		ans=ans>j?j:ans;
	}
	else
	{
		int nn;
		if(s[deep])
		{
			flag[deep]=0;
			dfs(deep+1,a,n);
			for(i=0;i<n;i++)
			{
				if(a[i].ch==s[deep])
				{
					for(j=0;j<n;j++) tp[j]=a[j];
					tp[i].cnt++;
					nn=n;
					if(tp[i].cnt>=3)	ck(tp,nn,i);
					flag[deep]=1;
					dfs(deep+1,tp,nn);
					flag[deep]=0;
				}
			}
		}
	}
}
int main()
{
	int t,i,j,len;
	node a[30];
	scanf("%d",&t);
	mp.clear();
	int c[30];
	char ss[30];
	while(t--)
	{
		scanf("%d%d",&i,&len);
		if(i==0) while(1);
		scanf("%s%s",ss,s);
		len=strlen(s);
		for(i=0;s[i];i++) c[i]=i,flag[i]=0;
		a[0].ch=ss[0];
		a[0].cnt=1;
		j=0;
		for(i=1;ss[i];i++)
		{
			if(ss[i]==a[j].ch) a[j].cnt++;
			else
			{
				a[++j].ch=ss[i];
				a[j].cnt=1;
			}
		}
		ans=10;
		j++;
		strcpy(ss,s);
		mp.clear();
		do
		{
			string str="";
			for(i=0;i<len;i++) 
			{
				s[i]=ss[c[i]];
				str+=s[i];
			}
			dfs(0,a,j);
			/*if(mp[str]==0)
			{
				mp[str]=1;
				dfs(0,a,j);
			} */
		}while(next_permutation(c,c+len));
		if(ans==10) printf("lose\n");
		else printf("%d\n",ans);
	}
	return 0;
}