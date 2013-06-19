#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int flag[300];
int ans[300],index[300];
int a[30][30];
int b[30];
int m,nn;
int abs(int x)
{
	return x>=0?x:-x;
}
bool flg[11]={0};
int dfs(int n1,int n2)
{
	int i,j,k1,k2;
	if(n2==-1)  return 1;
	else if(n2>n1)
	{
		if(n2>=nn)
		{
			for(i=0;i<=1;i++)
			{
				ans[n2]=i;
				if(dfs(n1,n2-1))  return 1;
			}
		}
		else
		{
			for(i=0;i<10;i++)
			{
				if(flg[i]==0){
				ans[n2]=i;
				flg[i]=1;
				if(dfs(n1,n2-1))
					return 1;
				flg[i]=0;
				}
			}
		}
	}
	else
	{
		j=0;
		for(i=n1+1;i<m;i++) j+=a[n1][i]*ans[i];
		j=b[n1]-j;
		k1=abs(j);
		k2=abs(a[n1][n1]);
		if(a[n1][n1]==0)
		{
			if(j==0)
			{
				if(dfs(n1-1,n2)) return 1;
				else return 0;
			}
			else return 0;
		}
		else if(k1%k2) return 0;
		else ans[n1]=j/a[n1][n1];
		if(n1<nn&&(ans[n1]<0||ans[n1]>9||flg[ans[n1]])) return 0;
		else 
		{
			flg[ans[n1]]=1;
			if(dfs(n1-1,n2-1))
				return 1;
			flg[ans[n1]]=0;
			return 0;
		}
		if(n1>=nn&&(ans[n1]<0||ans[n1]>1)) return 0;
		else return dfs(n1-1,n2-1);
	}
	return 0;
}
void run(char s1[],char s2[],char s3[])
{
	int i,j,k,n;
	n=strlen(s1);
	reverse(s1,s1+n);
	j=strlen(s2);
	reverse(s2,s2+j);
	if(n<j) n=j;
	k=strlen(s3);	
	if(n<k) n=k;
	reverse(s3,s3+k);
	for(i=strlen(s1);i<n;i++) s1[i]='0';	
	for(i=strlen(s2);i<n;i++) s2[i]='0';
	for(i=strlen(s3);i<n;i++) s3[i]='0';
	for(i=0;i<n;i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z') a[i][flag[s1[i]]-1]++;
		else b[i]-=s1[i]-'0';
		if(s2[i]>='A'&&s2[i]<='Z') a[i][flag[s2[i]]-1]++;
		else b[i]-=s2[i]-'0';
		if(s3[i]>='A'&&s3[i]<='Z') a[i][flag[s3[i]]-1]--;
		else b[i]+=s3[i]-'0';
	}
	for(i=0;i<n;i++) a[i][m+i]=1,a[i][m+i+1]=-10;
	a[0][m]=0;
	nn=m;
	m+=n;
	int k1,k2;
	int kk=0;
	for(i=0;i<n;i++)
	{
		for(;kk<m;kk++)
		{
			for(j=i;j<n&&a[j][kk]==0;j++);
			if(a[j][kk]!=0)
			{
				for(k=kk;k<m;k++) swap(a[i][k],a[j][k]);
				swap(b[i],b[j]);
				break;
			}
		}
		if(a[i][kk]!=0)
		{
			for(j=i+1;j<m;j++)
			{
				if(a[j][kk]==0) continue;
				k1=a[i][kk];
				k2=a[j][kk];
				for(k=i;k<m;k++)
				{
					a[j][k]=a[i][k]*k2-a[j][k]*k1;
				}
				b[j]=b[i]*k2-b[j]*k1;
			}
		}
	}
	for(i=0;i<10;i++) flg[i]=0;
	dfs(n-1,m-1);
	for(i='A';i<='Z';i++)
	{
		if(flag[i])
		{
			printf("%c %d\n",i,ans[flag[i]-1]);
		}
	}

}
int main()
{
	char s[1000];
	char s1[30],s2[30],s3[30];
	int i,j,k;
	while(scanf("%s",s)!=EOF)
	{
		for(i=0;i<300;i++) flag[i]=0;
		j=1;
		for(i=0;s[i];i++)
		{
			if(s[i]>='A'&&s[i]<='Z'&&flag[s[i]]==0) flag[s[i]]=j++;
		}
		m=j-1;
		for(i=0;;i++)
		{
			if(s[i]=='+'||s[i]=='-') break;
			s1[i]=s[i];
		}
		s1[i]=0;
		if(s[i]=='-') k=0;
		else k=1;
		for(j=0,i++;s[i]!='=';i++,j++) s2[j]=s[i];
		s2[j]=0;
		for(j=0,i++;s[i];i++,j++) s3[j]=s[i];
		s3[j]=0;
		for(i=0;i<30;i++)
		{
			for(j=0;j<30;j++) a[i][j]=0;
			b[i]=0;
		}
		if(k) run(s1,s2,s3);
		else run(s2,s3,s1);
	}
	return 0;
}
