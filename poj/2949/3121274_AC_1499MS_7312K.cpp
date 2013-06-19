#include <iostream>
#include <string>
using namespace std;
const int n=676;
int e[n][n],d[n][n],co[n][n],nu[n],a[n+1][n];
inline void max(int &i,int j)
{
	if (i<j) i=j;
}
inline void maxd(double &i,double j)
{
	if (i<j) i=j;
}
void work()
{
	int i,j,l,*l0,*l1;
	double ans,r;
	memset(a,0,sizeof(a));
	for (l=0;l<n;l++)
	{
		l0=a[l]; l1=a[l+1];
		for (i=0;i<n;i++)
			for (j=0;j<nu[i];j++) max(l1[d[i][j]],l0[i]+co[i][j]);
	}
	l0=a[l-1]; l1=a[l];
	for (i=0;i<n;i++)
		if (l0[i]<l1[i]) break; 
	if (i==n) {printf("No solution.\n"); return;}
	ans=1e10;
	for (i=0;i<n;i++)
		if (a[n-1][i]<a[n][i])
		{
			r=-1e10;
			for (j=0;j<n;j++)
				maxd(r,double(a[j][i]-a[n][i])/(n-j));
			if (r<ans) ans=r;
		}
	ans=2-ans;
	printf("%.2lf\n",ans);
}
int main()
{
	char *s=new char[1001];
	int i,len,j,m;
	scanf("%d",&m);
	while (m)
	{
		memset(e,0,sizeof(e));
		memset(nu,0,sizeof(nu));
		for (i=0;i<m;i++) 
		{
			scanf("%s",s);
			len=strlen(s);
			//if (len>2)
				max(e[(s[0]-97)*26+s[1]-97][(s[len-2]-97)*26+s[len-1]-97],len-2);
		}
		for (i=0;i<n;i++)
			for(j=0;j<n;j++)
				if (e[i][j]) {co[i][nu[i]]=e[i][j]; d[i][nu[i]++]=j;}
		work();
		scanf("%d",&m);
	}
	return 0;
}