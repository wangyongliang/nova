#include<stdio.h>
typedef __int64 int64;
int main()
{
	int64 a[20],n;
	int i;
	a[0]=1;
	for(i=1;i<20;i++) a[i]=a[i-1]*3;
	int b[20];
	bool r[20];
	bool l[20];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		for(i=0;i<20;i++) r[i]=l[i]=b[i]=0;
		for(i=0;i<20;i++,n/=3) b[i]=n%3;
		for(i=0;i<20;i++)
		{

			if(b[i]==1) r[i]=1;
			else if(b[i]==2)
			{
				b[i+1]++;
				l[i]=1;
			}
			else if(b[i]==3)
			{
				b[i+1]++;
			}
		}
		for(i=0;i<20;i++)
		{
			if(l[i]) break;
		}
		if(i==20) printf("empty");
		else printf("%I64d",a[i]);
		for(i++;i<20;i++)
		{
			if(l[i]) printf(",%I64d",a[i]);
		}
		for(i=0;i<20;i++)
		{

			if(r[i]) break;
		}
		printf(" %I64d",a[i]);
		for(i++;i<20;i++)
		{
			if(r[i]) printf(",%I64d",a[i]);
		}
		printf("\n");
	}
	return 0;
}