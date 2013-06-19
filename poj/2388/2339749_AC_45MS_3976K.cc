//pku 1455

#include<stdio.h>
int a[1000011]={0};
int main()
{
	int i,n,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<1000011;i++) a[i]=0;
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&j);
		a[j]++;
	}
	for(i=n/2+1,j=0;i;j++)
	{
		if(a[j])
		{
			if(a[j]>i) {j++;break;}
			else i-=a[j];
		}
	}
	printf("%d\n",j-1);
	}
	return 0;
}