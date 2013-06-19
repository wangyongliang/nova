#include <stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int comp(const void* a,const void *b) 
{ 
	return *(unsigned int*)a-*(unsigned int*)b; 
}
unsigned int a[1000010];
int main()
{int i;
	int n,flag1,flag2;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
   // qsort(a,n,sizeof(unsigned int),comp); 
    flag1=0,flag2=0;
		if(a[0]+a[1]<=a[n-1])
		{
			flag1=1;
		}
		if(flag1&&n>200)
		{
			printf("The set is accepted.\n");
			continue;
		} 
	for(i=2;i<n;i++)
		{
			if(a[i-1]+a[i-2]>a[i])
			{
				flag2=1;
				break;
			}
		}
		if(flag1==1&&flag2==1)
		{
			printf("The set is accepted.\n");
		}
		else
		{
			printf("The set is rejected.\n");
		}
	}
}