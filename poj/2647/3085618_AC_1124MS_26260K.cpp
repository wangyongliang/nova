#include<stdio.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
//#include<time.h>
#define mmax 159451
using namespace std;
struct node
{
	string key;
	int data;
	int next,cnt;
}hash[mmax],q[mmax];
int hashl;
#define  maxn 10009
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
void insert(int i,string key,int data)
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
int find(int i,string key)
{
	while(hash[i].next)
	{
		if(key>hash[hash[i].next].key) break;
		else if(key==hash[hash[i].next].key)
		{
			return hash[hash[i].next].data;
		}
		i=hash[i].next;
	}
	return -1;
}
bool flag[mmax],flg[mmax];
string str[mmax];
vector <int> a[mmax];
void print(int st)
{
	if(q[st].next==-1)
	{
		cout<<q[st].key<<endl;
	}
	else
	{
		print(q[st].next);
		cout<<q[st].key<<endl;
	}
}
int main()
{
	char s1[100],s2[100],s[100];
	string str1,str2,str3;
	int i,j,k,n,m,st,en,num,l;
	//freopen("B.1.dat","r",stdin);
	m=0;
	hashl=maxn;
	for(i=0;i<maxn;i++) hash[i].next=0;
	for(i=0;;i++)
	{
		gets(s);
		if(s[0]=='\0') break;
		else
		{
			str[i]=s;
			for(j=0;j<str[i].size();j++)
			{
				str1=str[i];
				str1[j]=' ';
				k=find(f(str1),str1);
				if(k==-1)
				{
					insert(f(str1),str1,m);
					a[m].push_back(i);
					m++;
				}
				else a[k].push_back(i);
			}
		}
	}
	n=i;
	while(gets(s))
	{
		str2=str1="";
		for(i=0;s[i]!=' ';i++) str1=str1+s[i];
		for(i++;s[i];i++) str2=str2+s[i];
		for(i=0;i<m;i++) flag[i]=flg[i]=1;
		str3=str1;
		if(str1.size()!=str2.size()) cout<<"No solution.\n"<<endl;
		else
		{
			num=str1.size();
			st=0;
			en=1;
			q[0].key=str1;
			q[0].next=-1;
			while(st<en)
			{
				if(q[st].key==str2) break;
				else
				{
					for(j=0;j<num;j++)
					{
						str1=q[st].key;
						str1[j]=' ';
						k=find(f(str1),str1);
						if(flag[k])
						{
							flag[k]=0;
							for(i=0;i<a[k].size();i++)
							{
								if(flg[a[k][i]])
								{
									l=a[k][i];
									flg[a[k][i]]=0;
									q[en].key=str[a[k][i]];
									q[en].next=st;
									en++;
								}
							}
						}
					}
				}
				st++;
			}
			if(q[st].key==str2)
			{
				print(st);
				cout<<endl;
			}
			else cout<<"No solution.\n"<<endl;
		}
	}
	return 0;
}

