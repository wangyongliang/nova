#include <iostream>
#include <string.h>
using namespace std;
int next[100010];
void getnext(char str[])
{
	int i,j;
	i=-1;
	j=0;
	next[0]=-1;
	int len=strlen(str);
	while(j<=len)
	{
		if(i==-1||str[i]==str[j])
		{
			i++;
			j++;
			next[j]=i;
		}
		else i=next[i];
	}
	
}
int get_num(char str[])
{
	getnext(str);
	int ans;
	int len=strlen(str);
	if(next[len]==0) ans=len-1;
	else if(next[len]*2>=len)
	{
		int i;
		for(i=len;i>=0;i--)
		{
			if(next[i]*2==i) break;
			
		}
		ans=next[i-1];
	}
	else ans=len-next[len]-1;
	return ans;
}
char str[100010];
char a[100010][80];
int b[100010];
int main()
{	
	int n,m;
	int i,j;
//	freopen("mgrid.8.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++) str[i]=a[i][j];
		str[i]=0;
		b[j]=get_num(str)+1;
	}
	int max=b[0];
	for(j=0;j<m;j++) if(max<b[j]) max=b[j];
	int tp=max;
	while(max<=n)
	{
		for(j=0;j<m;j++) if(max%b[j]!=0) break;
		if(j==m) break;
		max+=tp;
	}
	if(max>=n) max=n;
//	printf("%d\n",max);
	int x=max;
	for(i=0;i<n;i++)
	{
		strcpy(str,a[i]);
		b[i]=get_num(str)+1;
	}
	max=b[0];
	for(i=0;i<n;i++) max=max<b[i]?b[i]:max;
	tp=max;
	while(max<=m)
	{
		for(i=0;i<n;i++)if(max%b[i]) break;
		if(i==n) break;
		max+=tp;
	}
	if(max>m) max=m;
	int y=max;
	printf("%d\n",x*y);

	}
	system("pause");
	return 0;
}