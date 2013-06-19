#include<stdio.h>
#define maxn 5000010
int a[maxn]={0};
int ans[maxn];
int c[32];
int main()
{
	int n,i,j,k;
	for(i=2;i<maxn;i++)
	{
		if(a[i]==0)
		{
			for(j=i;j<maxn;j+=i) a[j]=i;
		}
	}
	for(i=1,c[0]=0;i<32;i++)  c[i]=c[i-1]+i*i*i;
	ans[1]=1;
	for(i=2;i<maxn;i++)
	{
		n=i;
		k=a[n];
		for(j=0;n%k==0;j++) n/=k;
		ans[i]=ans[n]*c[j+1];
		if(ans[i]<0||ans[i]<ans[n]) printf("bad\n");
	}
	scanf("%d",&i);
	while(i--){scanf("%d",&n);  printf("%d\n",ans[n]);}
	return 0;
}