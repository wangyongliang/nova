#include<stdio.h>
int main()
{
	char s1[110],s2[110],s3[110];
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",s1,s2,s3);
		for(i=0,j=0;s2[j]&&s1[i];j++)
		{
			if(s2[j]==s1[i]||s3[j]==s1[i]||s2[j]=='*') i++;
		}
		if(s1[i]=='\0') printf("win\n");
		else printf("lose\n");
	}
	return 0;
}