#include<stdio.h>
#include<string.h>
void main()
{
	char s[100];
	int a[100],i,j,k,l;
	while(scanf("%s",s)!=EOF)
	{
		k=strlen(s);
		for(i=j=0;s[i];i++)
			a[i]=s[i]-'0',j+=a[i];
		l=k*(k+1)/2;
		for(i=0;i<k;i++)
			a[i]*=l;
		if(a[0]>l)
		{
			for(i=0;i<k;i++)
			{
				if((a[i]-j)%10==0)
				{
					a[i+1]+=(a[i]-j)*10;
					a[i]-=j;
				}
				else
				{
					printf("%s is not cyclic\n",s);
					goto lin;
				}
			}
		}
		else	
		{
			for(i=k-1;i>=0;i--)
			{
				if((a[i]-j)%10==0)
				{
					a[i-1]+=(a[i]-j)/10;
					a[i]-=j;
				}
				else
				{
					printf("%s is not cyclic\n",s);
					goto lin;
				}
			}
		}
		printf("%s is cyclic\n",s);
lin:;

	}
}