#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
#define max 1000000
char a[110][10000][30];
vector<string> tp;
struct node
{
	int next[26];
	int num;
}hash[max];
int cnt,m,flag,ct[110];
bool b[110][110];
void insert(char  str[],int num)
{
	int i,j,k;
	j=0;
	for(i=0;str[i];i++)
	{
		if(hash[j].next[str[i]-'a']==-1)
		{
			for(k=0;k<26;k++) hash[m].next[k]=-1;
			hash[m].num=-1;
			hash[j].next[str[i]-'a']=m;
			m++;
		}
		j=hash[j].next[str[i]-'a'];
	}
	hash[j].num=num;
}
int get(char str[])
{
	int i,j;
	j=0;
	for(i=0;str[i];i++)
	{
		if(hash[j].next[str[i]-'a']==-1) return -1;
		j=hash[j].next[str[i]-'a'];
	}
	return hash[j].num;
}
//char s[2000000];
void init()
{
	int i;
	for(i=0;i<26;i++) hash[0].next[i]=-1;
	hash[0].num=-1;
	m=1;
}
char str2[100],str1[100];
void print(int i,int k)
{
	int j;
	char ch;
	if(hash[i].num==1) 
	{
		if(flag) printf("%s",str2),flag=0;
		printf(" ");
		for(j=0;j<k;j++) printf("%c",str1[j]);
	}
	for(j=0;j<26;j++)
	{
		ch=j+'a';
		str1[k]=ch;
		if(hash[i].next[j]>=0) print(hash[i].next[j],k+1);
	}
}
int main()
{
	int n,i,j,k,l,c[110];
	int t=1;
	char ch;
	string str;
	while(scanf("%d%d",&k,&n)&&(n+k))
	{
		ch=getchar();
		cnt=0;
		tp.clear();
		for(i=0;i<110;i++)  ct[i]=0;
		init();
		for(j=0;j<n;j++)
		{
			for(i=0;;str1[i++]=ch)
			{
				ch=getchar();
				if(ch==' ') break;
			}
			str1[i]='\0';
			insert(str1,cnt);
			ch=getchar();
			while(ch==' ')ch=getchar();
			str=str1;
			str1[0]=ch;
			cnt++;
			tp.push_back(str);
			for(i=1;;)
			{
				ch=getchar();
				if(ch==' ')
				{
					str1[i]='\0';
				//	a[cnt-1].push_back(str1);
					strcpy(a[cnt-1][ct[cnt-1]],str1);
					ct[cnt-1]++;
					ch=getchar();
					while(ch==' ') ch=getchar();
					str1[0]=ch;
					i=1;
				}
				else if(ch=='\n')
				{
					str1[i]='\0';
					//a[cnt-1].push_back(str1);
					strcpy(a[cnt-1][ct[cnt-1]],str1);
					ct[cnt-1]++;
					break;
				}
				else str1[i++]=ch;
			}
		}
		printf("--- CASE %d\n",t++);
	
		for(i=0;i<100;i++) 
		{
			for(j=0;j<100;j++) b[i][j]=0;
			b[i][i]=1;
		}
		for(i=0;i<cnt;i++)
		{
			for(j=0;j<ct[i];j++)
			{
			//	str1=a[i][j];
				k=get(a[i][j]);
				if(k!=-1) b[k][i]=1;
			}
		}
		for(j=0;j<cnt;j++)
		{
			for(i=0;i<cnt;i++)
			{
				if(b[i][j])
				{
					for(k=0;k<cnt;k++)
					{
						if(b[j][k]) b[i][k]=1;
					}
				}
			}
		}
		sort(tp.begin(),tp.end());
		for(i=0;i<tp.size();i++) 
		{
			strcpy(str1,tp[i].c_str());
			c[i]=get(str1);
		}
		for(i=0;i<tp.size();i++)
		{
			init();
			k=c[i];
			for(j=0;j<cnt;j++)
			{
				if(b[j][k])
				{
					for(l=0;l<ct[j];l++) insert(a[j][l],1);
				}
			}
			flag=1;
			for(j=0;j<ct[k];j++) insert(a[k][j],-1);
			strcpy(str2,tp[i].c_str());
			insert(str2,-1);
			print(0,0);
			if(flag==0)	printf("\n");
		}
	}
	return 0;
}
