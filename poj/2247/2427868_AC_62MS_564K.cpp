//pku2047
#include<stdio.h>
__int64 a[66666];
int f[4]={6,4,3,2};
int c[4]={2,3,5,7};
int main()
{
	int i,j,n,min,t;
	for(i=1;i<=10;i++) a[i]=i;
	for(;i<66666;i++)
	{
		min=0;
		for(j=0;j<4;j++)
		{
			if(a[f[min]]*c[min]>a[f[j]]*c[j]) min=j;
		}
		a[i]=a[f[min]]*c[min];
		f[min]++;
		for(j=0;j<4;j++)
		{
			if(a[f[j]]*c[j]==a[f[min]-1]*c[min]) f[j]++;
		}
	}
	while(scanf("%d",&n)&&n)
	{
		

		if(n%10==1&&n%100!=11)printf("The %dst humble number is %I64d.\n",n,a[n]); 
		else if(n%10==2&&n%100!=12)printf("The %dnd humble number is %I64d.\n",n,a[n]); 
		else if(n%10==3&&n%100!=13)printf("The %drd humble number is %I64d.\n",n,a[n]); 
		else printf("The %dth humble number is %I64d.\n",n,a[n]); 
	
		
	}
	return 0;
}

