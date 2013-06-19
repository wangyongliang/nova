#include<stdio.h>
int main()
{
	int a[1501],b[3];
	int n,i,j;
	a[0]=1;
	b[0]=b[1]=b[2]=0;
	for(i=1;i<1501;i++)
	{
		if(a[b[0]]*2<=a[b[1]]*3&&a[b[0]]*2<=a[b[2]]*5)
		{
			a[i]=a[b[0]]*2;
			b[0]++;
			if(a[b[1]]*3==a[i])b[1]++;
			if(a[b[2]]*5==a[i])b[2]++;
		}	
		else if(a[b[0]]*2>=a[b[1]]*3&&a[b[1]]*3<=a[b[2]]*5)
		{
			a[i]=a[b[1]]*3;
			b[1]++;
			if(a[b[0]]*2==a[i])b[0]++;
			if(a[b[2]]*5==a[i])b[2]++;
		}	
		else
		{
			a[i]=a[b[2]]*5;
			b[2]++;
			if(a[b[1]]*3==a[i])b[1]++;
			if(a[b[0]]*2==a[i])b[0]++;
		}
	}
	scanf("%d",&n);
	while(n)
	{
		printf("%d\n",a[n-1]);
		scanf("%d",&n);
	}
}