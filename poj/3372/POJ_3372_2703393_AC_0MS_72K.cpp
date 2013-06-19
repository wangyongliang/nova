#include<stdio.h>
void main()
{
	__int64 a,b;
	while(scanf("%I64d",&a)!=EOF)
	{
		b=a-1;
		if((b^a)==(b+a))
			printf("YES\n");
		else printf("NO\n");
	}
}