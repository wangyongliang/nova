#include<stdio.h>
int a[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
void main()
{
	char s[21];
	int i;
	while(scanf("%s",s)!=EOF)
	{
		if(a[s[0]-'A'])printf("%d",a[s[0]-'A']);
		for(i=1;s[i];i++)
		
		{
			if(a[s[i]-'A'])
			{
//				if(s[i-1]==s[i])printf("%d",a[s[i]-'A']);
				if(a[s[i]-'A']!=a[s[i-1]-'A'])printf("%d",a[s[i]-'A']);
			}
		}
		printf("\n");
	}
}
