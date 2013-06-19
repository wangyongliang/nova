#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
//#include<time.h>
using namespace std;
bool flag[1200];
int cnt[2000],hashl;
string s,ss[11000],c,ans[2000],tp;
//map <string ,string> a;
//map<string ,int>b;
struct node
{
	string key,data;
	int next,cnt;
}hash[200000];
#define  maxn 99991
int f(string key)
{
	unsigned long h=0;
	int i,j;
	j=key.size();
	for(i=0;i<j;i++)
	{
		h=(h<<4)+key[i];
		unsigned long g=h&0xf0000000L;
		if(g)h^=g>>24;
		h&=~g;
	}
    return h%maxn;
}
void insert(int i,string key,string data)
{
	while(hash[i].next)
	{
		if(key>hash[hash[i].next].key) break;
		else if(key==hash[hash[i].next].key) 
		{
			hash[hash[i].next].cnt++;
			return ;
		}
		i=hash[i].next;
	}
	hash[hashl].key=key;
	hash[hashl].data=data;
	hash[hashl].cnt=1;
	hash[hashl].next=hash[i].next;
	hash[i].next=hashl++;
}
string find(int i,string key,int &cnt)
{
	while(hash[i].next)
	{
		if(key>hash[hash[i].next].key) break;
		else if(key==hash[hash[i].next].key)
		{
			cnt=hash[hash[i].next].cnt;
			return hash[hash[i].next].data;
		}
		i=hash[i].next;
	}
	cnt=0;
	return "";
}
int main()
{
	int st,en;
	char temp[10000];
	int t,n,i,j,max;
//	st=clock();
//	freopen("testdata.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
	//	a.clear();
	//	b.clear();
		hashl=maxn;
		for(i=0;i<=maxn;i++) hash[i].next=0;
		max=0;
		scanf("%s",temp);
		for(i=0;i<1010;i++) cnt[i]=flag[i]=0;
		s=temp;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",temp);
			ss[i]=temp;
			j=ss[i].size();
			c=ss[i];
			max=max<j?j:max;
			flag[j]=1;
			if(j>2) sort(c.begin()+1,c.end()-1);
			j=f(c);
			insert(j,c,ss[i]);
		//	a[c]=ss[i];
		//	b[c]++;
		}
		c="";
		for(i=1;i<=max;i++)
		{
			c+=s[i-1];
			if(i>2) sort(c.begin()+1,c.end()-1);
		//	n=b[c];
			tp=find(f(c),c,n);
			if(tp!="") cnt[i]=n,ans[i]=tp;
		}
		int k=s.size();
		for(i=1;i<k;i++)
		{
			if(cnt[i])
			{
				c="";
				for(j=i+1;j<=i+max;j++)
				{
					c+=s[j-1];
					if(flag[j-i])
					{
						if(j-i>2) sort(c.begin()+1,c.end()-1);
						tp=find(f(c),c,n);
						if(tp!="") cnt[j]+=n+cnt[i]-1,ans[j]=tp;
					//	if(a[c]!="") ans[j]=a[c],cnt[j]+=cnt[i]+b[c]-1;
					}
				}
			}
		}
		if(cnt[k]>1) cout<<"ambiguous"<<endl;
		else if(cnt[k]==1)
		{
			c="";
			for(i=k;i;i-=ans[i].size())
			{
				if(c=="") c=ans[i];
				else 	c=ans[i]+' '+c;
			}
			cout<<c<<endl;
		}
		else cout<<"impossible"<<endl;
	}
//	en=clock();
//	printf("time is %d\n",en-st);
	return 0;
}
