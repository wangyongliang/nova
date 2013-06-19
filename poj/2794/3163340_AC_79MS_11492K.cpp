#include<stdio.h>
#define maxn 2000000
bool flag[maxn];
double p[maxn];
char s[10][6];
int g(int a[])
{
	int ans=0;
	for(int i=0;i<9;i++) ans=ans*5+a[i];
	return ans;
}
double f(int n)
{
	if(flag[n]) return p[n];
	flag[n]=1;
	int i,j,m;
	double k=0.0;
	int a[10];
	for(i=8,j=n;i>=0;i--,j/=5)  a[i]=j%5;
	for(i=0;i<9&&a[i]==0;i++);
	if(i==9)
	{
		p[n]=1.0;
		return 1.0;
	}
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(a[i]&&a[j]&&s[i][a[i]-1]==s[j][a[j]-1])
			{
				k+=1.0;
				a[i]--;a[j]--;
				m=g(a);
				p[n]+=f(m);
				a[i]++;
				a[j]++;
			}

		}
	}
	if(k) p[n]=p[n]*1.0/k;
	return p[n];
}
int main()
{
	char ch[10];
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%s",ch);
			s[i][j]=ch[0];
		}
	}
	for(i=0,j=1;i<9;i++)j*=5;
	printf("%.6lf\n",f(j-1));
}