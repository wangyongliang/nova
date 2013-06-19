#include <stdio.h>
#include <string.h>
int Max(int a,int b)
{
	return a>b?a:b;
}
void main(){
char s1[300],s2[300];
int i,j,len1,len2,d[300][300]={0};
while(scanf("%s %s",s1,s2)!=EOF)
{
	d[0][0]=0;
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=1;i<=len1;i++)
		for(j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				d[i][j]=d[i-1][j-1]+1;
			else
			{
				d[i][j]=Max(d[i-1][j],d[i][j-1]);
			}
		}

	printf("%d\n",d[i-1][j-1]);
}
}