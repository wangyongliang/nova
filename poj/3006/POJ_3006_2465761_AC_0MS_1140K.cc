#include<stdio.h>
#define max 1000009
bool a[max]={0};
void init()
{
	long i,j;
	a[0]=a[1]=1;
	for(i=2;i*i<max;i++)
	{
		if(!a[i])
		{
			for(j=i*i;j<max;j+=i) a[j]=1;
		}
	}
}
int main()
{
	long b,d,count,num,i;
	init();
	while(scanf("%ld%ld%ld",&b,&d,&num)&&(b+d+num))
	{
		count=0;
		for(i=b;count<num;i+=d)
		{
			if(!a[i]) count++;
			if(count==num) break;
		}
		printf("%ld\n",i);
	}
	return 0;
}