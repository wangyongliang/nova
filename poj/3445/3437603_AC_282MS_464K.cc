#include<stdio.h>
#include<string.h>
char s1[1000000],s2[1000000];
void print(int n)
{
	if(n==0) printf("{}");
	else
	{
		int i;
		printf("{{}");
		for(i=1;i<n;i++) 
		{
			printf(",");
			print(i);
		}
		printf("}");
	}
}
int sum[300];
int main()
{
	int t,i,j;
	scanf("%d",&t);
	int n1,n2;
	sum[0]=sum[1]=0;
	for(i=2;i<20;i++)
	{
		sum[i]=i-1;
		for(j=0;j<i;j++) sum[i]+=sum[j];
	}
	while(t--)
	{
		scanf("%s%s",s1,s2);
		if(strlen(s1)==2) n1=0;
		else
		{
			n1=0;
			for(i=0;s1[i];i++) n1+=(s1[i]==',');
			for(i=1;i<16&&sum[i]!=n1;i++);
			n1=i;
		}
		if(strlen(s2)==2) n2=0;
		else
		{
			n2=0;
			for(i=0;s2[i];i++) n2+=(s2[i]==',');
			for(i=1;i<16&&sum[i]!=n2;i++);
			n2=i;
		}
		n1+=n2;
		print(n1);
		printf("\n");
	}
	return 0;
}