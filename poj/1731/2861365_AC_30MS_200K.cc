#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	char s[200];
	char s1[200],s2[200];
	int n;
	while(scanf("%s",s)!=EOF)
	{
		n=strlen(s);
		sort(s,s+n);
		strcpy(s1,s);
		printf("%s\n",s);
		strcpy(s2,s);
		next_permutation(s,s+n);
		while(strcmp(s1,s)!=0)
		{
			if(strcmp(s,s2)!=0) printf("%s\n",s);
			strcpy(s2,s);
			next_permutation(s,s+n);
		}
	}
	return 0;
}