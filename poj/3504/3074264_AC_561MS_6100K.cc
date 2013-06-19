#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
bool flag[1200];
int cnt[2000],hashl;
string s,ss[11000],c,ans[2000],tp;
struct node
{
	string key,data;
	int next,cnt;
}hash[200000];
#define  maxn 10009
int  insert(string key,string data,string &ans,int flag)
{
	ans="";
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
    h%=maxn;
	while(hash[h].next)
	{
		if(key>hash[hash[h].next].key) break;
		else if(key==hash[hash[h].next].key) 
		{
			if(flag) hash[hash[h].next].cnt++;
			ans=hash[hash[h].next].data;
			return hash[hash[h].next].cnt;

		}
		h=hash[h].next;
	}
	if(flag)
	{
		hash[hashl].key=key;
		hash[hashl].data=data;
		hash[hashl].cnt=1;
		hash[hashl].next=hash[h].next;
		hash[h].next=hashl++;
	}
	ans="";
	return 0;
}
int main()
{
	int st,en;
	char temp[10000];
	int t,n,i,j,max;
	scanf("%d",&t);
	while(t--)
	{
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
			j=insert(c,ss[i],tp,1);
		}
		c="";
		for(i=1;i<=max;i++)
		{
			c+=s[i-1];
			if(i>2) sort(c.begin()+1,c.end()-1);
			n=insert(c,"",tp,0);
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
						n=insert(c,"",tp,0);
						if(tp!="") cnt[j]+=n+cnt[i]-1,ans[j]=tp;
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
	return 0;
}
