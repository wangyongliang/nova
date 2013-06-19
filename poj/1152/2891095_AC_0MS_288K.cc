//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

#include<stdio.h>
int flag[356];
int main()
{
	char s[100000];
	int i,j;
	for(j=10,i='A';i<='Z';i++,j++) flag[i]=j;
	for(i='a';i<='z';i++,j++) flag[i]=j;
	for(i='0';i<='9';i++) flag[i]=i-'0';
	__int64 sum;
	int max;
	while(scanf("%s",s)!=EOF)
	{
		sum=0;
		max=2;
		for(i=0;s[i];i++) sum+=flag[s[i]],max=max<flag[s[i]]+1?flag[s[i]]+1:max;
		for(i=max-1;i<62;i++)
		{
			if(sum%i==0) break;
		}
		if(i<62) printf("%d\n",i+1);
		else printf("such number is impossible!\n");
	}
	return 0;
}