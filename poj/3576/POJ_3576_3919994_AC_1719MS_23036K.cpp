/*
#include <iostream>
using namespace std;
#define MAXN 150002
#define MAX_RANGE 26
#define FAIL 0
#define hsize 997001

int trans[MAXN][MAX_RANGE];
bool terminal[MAXN];
int vexnum = 1;
int nodes[MAXN];
int hashValue[MAXN];
int hash[hsize];

int ans;

void Trie(char *p) {
	int cur = 1;
	while (*p != '\0') {
		*p -= 'a';
		if (trans[cur][*p] == FAIL) trans[cur][*p] = ++vexnum;
		cur = trans[cur][*p++];
	}
	terminal[cur] = 1;
}

inline bool Equal(int a, int b) { //a和b是否相同
	if (terminal[a] != terminal[b]) return false;

	for (int i = 0; i < MAX_RANGE; i++)
		if (hashValue[trans[a][i]] != hashValue[trans[b][i]]) return false;
	return true;
}

bool Put(int cur, int value) { // true表示hash成功，否则与以有元素重复
	while (hash[value]) {
		if (Equal(cur, hash[value])) {
			hashValue[cur] = value;
			return false;
		} else value++;
	}
	hashValue[cur] = value;
	hash[value] = cur;
	return true;
}

void dfs(int cur) {
	int i, next;
	int p = 0;
	nodes[cur] = 1;

	for (i = 0; i < MAX_RANGE; i++) {
		next = trans[cur][i];
		if (next != FAIL) {
			dfs(next);
			nodes[cur] += nodes[next];
			p += hashValue[next] * 27 + i + 1;
		}
	}
	p %= hsize;
	if(p == 0) p += nodes[cur];
	if (Put(cur, p)) ans++;
}

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int i, n;
	char buf[31];

	scanf("%d\n", &n);

	for (i = 0; i < n; i++) {
		gets(buf);
		Trie(buf);
	}
	ans = 0;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
*/

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