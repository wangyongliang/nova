#include<stdio.h>
void main()
{
	char s[15][51];
	int n,a[15],j,i,l,k=0;
	scanf("%d",&n);
	while(n)
	{
		k++;
		for(j=i=0,l=n-1;i<n;i++)
		{
			if(i&1)
				a[l--]=i;
			else
				a[j++]=i;
		}
		i=0;
		j=n;
		while(j--)
		{
			scanf("%s",s[i++]);
		}
		printf("SET %d\n",k);
		for(i=0;i<n;i++)
			puts(s[a[i]]);
		scanf("%d",&n);
	}
}