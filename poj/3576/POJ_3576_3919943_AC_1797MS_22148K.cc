#include<stdio.h>
#include<set>
#include<stdlib.h>
using namespace std;
set<long long > heap;
#define maxn 500000
struct node
{
	int index[26];
	int flag;
}a[maxn];
int m;
long long hash[maxn];
void insert(char s[])
{
	int i,j=0;
	for(i=0;s[i];i++)
	{
		if(a[j].index[s[i]-'a']==-1)
		{
			for(int k=0;k<26;k++) a[m].index[k]=-1;
			a[m].flag=0;
			a[j].index[s[i]-'a']=m++;
			if(m>=maxn)
				printf("very bad\n");
		}

		j=a[j].index[s[i]-'a'];
	}
	a[j].flag=1;
}
int  coef[30];
void calhash(int u)
{
		if (u == -1) {
			return;
		}
		for (int i = 0; i < 26; i++) {
			calhash(a[u].index[i]);
		}
		hash[u] = (a[u].flag) ? 83475835 : 38475835;
		for (int i = 0; i < 26; i++) {
			hash[u] = hash[u] + ((a[u].index[i] == -1) ? 0 : hash[a[u].index[i]] * coef[i]);
		}
	//	if(hash[u]<0) printf("bad\n");
		heap.insert(hash[u]);
}
int main()
{
	int n,i,j;
	char s[100];
	while(scanf("%d",&n)!=EOF)
	{
		m=1;
		heap.clear();
		for(i=0;i<26;i++) a[0].index[i]=-1;
		a[0].flag=0;
		for(i=0;i<n;i++) 
		{
			scanf("%s",s);
			insert(s);
		}
		srand(432758235);
		for(i=0;i<26;i++) coef[i]=rand();
		calhash(0);
		printf("%d\n",heap.size());
	}
	return 0;
}