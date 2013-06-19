#include<stdio.h>
#include<string.h>
#define maxn 5110
char a[maxn*2],b[maxn],c[maxn];
int n,next[maxn];
void getnext(char s[])
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<n)
	{
		if(j==-1||s[i]==s[j])
		{
			i++,j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
int kmp(char s1[],char s2[])
{
	int i,j;
	int n1,n2;
	n1=strlen(s1);
	n2=strlen(s2);
	getnext(s2);
	for(i=j=0;i<n1&&j<n2;)
	{
		if(j==-1||s1[i]==s2[j]) i++,j++;
		else j=next[j];
	}
	if(j>=n2) return 1;
	else return 0;
}
int main()
{
	int i,j,k;
	while(scanf("%s%s",b,a)!=EOF)
	{
		n=strlen(a);
		for(i=0,j=n;i<n;i++,j++) a[j]=a[i];
		a[j]=0;
		for(i=0;i<n;i++)
		{
			for(j=0,k=i;j<n;j++,k++)
			{
				if(a[k]==b[j]) c[j]='0';
				else c[j]='1';
			}
			c[j]=0;
			if(kmp(a,c)) break;
		}
		if(i==n) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}