#include <stdio.h>
#include <string.h>
int Max(int a,int b)
{
	return a>b?a:b;
}
void main(){
char s1[1010],s2[1010];
int i,j,len1,len2,d[2][1010]={0};
int flag=1;
while(scanf("%d%s%d%s",&len1,s1,&len2,s2)!=EOF)
{
//	for(i=0;i<=len2;i++) d[1][i]=d[0][i]=0;
	d[0][1]=d[1][0]=d[0][0]=0;
	for(i=1;i<=len1;i++)
	{	for(j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				d[flag][j]=d[1-flag][j-1]+1;
			else
			{
				d[flag][j]=Max(d[1-flag][j],d[flag][j-1]);
			}
			if(i==len1) d[1-flag][j-1]=0;
		}
	flag=1-flag;
	}
	d[flag][len2]=0;

	printf("%d\n",len2-d[1-flag][j-1]);
	flag=1-flag;
}
}

