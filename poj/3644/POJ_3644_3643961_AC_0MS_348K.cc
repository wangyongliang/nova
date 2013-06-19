#include<stdio.h>
#include<string>
using namespace std;
__int64 c[22],t[22];
int flag;
string f(int n,__int64 m)
{
	string ans="";
	if(n==1) return "ES";
	else if(n==0) return "";
	else
	{
		int i;
		for(i=n;m>=t[i]*c[n-i];i--) m-=t[i]*c[n-i];
		if(n-i<0||n-i>n) while(1);
		ans='E'+f(i-1,m/c[n-i])+'S'+f(n-i,m%c[n-i]);
		return ans;
	}
}
int main()
{
	int i,j,n;
	__int64 m,k;
	string ans;
	c[0]=c[1]=1;
	for(i=2;i<22;i++)
	{
		c[i]=0;
		for(j=0;j<i;j++) c[i]+=c[j]*c[i-1-j];
	}
	t[1]=1;
	for(i=2;i<22;i++)
	{
		t[i]=c[i];
		for(j=1;j<i;j++) t[i]-=t[j]*c[i-j];
	}
	while(scanf("%d%I64d",&n,&m)&&(n+m))
	{
		k=0;
		n--;
		if(n==0)
		{
			if(m==1) printf("\n");
			else printf("ERROR\n");
			continue;
		}
		for(i=1;i<=n;i++)  k+=t[i]*c[n-i];
		if(k<m) printf("ERROR\n");
		else 
		{
			ans=f(n,m-1);
			printf("%s\n",ans.c_str());
		}
	}
	return 0;
}