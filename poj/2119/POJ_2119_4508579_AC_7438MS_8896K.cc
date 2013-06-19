#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)>0?(x):-(x))
#define SP(x) setprecision(x)
using namespace std;
#define maxn 1810000
struct node
{
	int x,y;
};
bool operator <(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
set<node> st;
char s[100];
char str[maxn];
int m;
set<node> ::iterator it;
int hash(int mod)
{
	int i;
	int p=1;
	int ans=0;
	for(i=0;s[i];i++)
	{
		ans=ans*26+s[i]-'a';
		ans%=mod;
	}
	return ans;
}
int hash_m[2000003][2];
int insert(node tp)
{
	int i,j;
	i=tp.x;
	j=tp.y;
	while(hash_m[i][1]!=-1&&hash_m[i][0]<j) i=hash_m[i][1];
	if(hash_m[i][0]==j) return 1;
	int k=hash_m[i][1];
	hash_m[i][1]=m;
	hash_m[m][0]=j;
	hash_m[m][1]=k;
	m++;
	return 0;
}
int  main()
{
    int k,i,j;
    char ch1,ch2;
//	freopen("g.in","r",stdin);
//	freopen("G.out","w",stdout);
    while(scanf("%d",&k)&&k){
        getchar();
        gets(str);
		st.clear();
		for(i=0;i<1000003;i++)
		{
			hash_m[i][0]=-1;
			hash_m[i][1]=-1;
		}
		m=1000003;
	//	cout<<strlen(str)<<endl;

		int len=0;
		j=0;
		s[0]=0;
		for(i=0;str[i];i++)
		{
			str[i]=tolower(str[i]);
			if(isalpha(str[i]))
			{
				s[len++]=str[i];
				s[len+1]=0;
				if(len==k)
				{				
					sort(s,s+len);
					node tp;
					tp.x=hash(1000003);
					tp.y=hash(9999997);
					if(insert(tp)) break;
				//	it=st.find(tp);
					
				//	if(it!=st.end()) break;
				//	if(hash_m[tp.x]==1&&it==st.end()) cout<<"bad"<<endl;
				//	if(hash_m[tp.x]) break;
				//	hash_m[tp.x]=1;
				//	st.insert(tp);
					for(;j<i;j++)
					{
						if(isalpha(str[j])) break;
					}
					for(k=0;s[k]!=str[j];k++);
					j++;
					for(;s[k];k++) s[k]=s[k+1];
					len--;
				}
				if(len>k) while(1);
			}
		}
		printf("%d\n",i);
	//	maxsize=max(maxsize,m);
    }
//	cout<<"maxsize ="<< maxsize<<endl;
 //   system("pause");
    return 0;
}
