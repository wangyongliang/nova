#include<stdio.h>
#include<string.h>
typedef __int64 int64;
__int64 pow(int n)
{
	__int64 ans=1;
	while(n)
	{
		ans*=3;
		n--;
	}
	return ans;
}
void polya(int n,int c)//旋转和翻转都看作相同
{
	bool b1[52]={0},b2[52]={0};
	int i,j,k;
	int x,y;
	__int64 temp;
	__int64 ans=0;
	for(i=0;i<n;i++)
	{
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		for(x=y=j=0;j<n;j++)
		{
			if(!b1[(i+j)%n])
			{
				for(x++,k=(i+j)%n;!b1[k];k=(i+k)%n) b1[k]=1;
			}
			if(!b2[n-1-(i+j)%n])
				for(y++,k=n-1-(i+j)%n;!b2[k];k=n-1-(i+k)%n) b2[k]=1;
		}
		ans+=pow(x)+pow(y);
	}
	ans/=n;
	ans/=2;
	printf("%I64d\n",ans);
}
int main()
{
	int n,c=3;
	int i;
	while(scanf("%d",&n)&&n!=-1)
	{
		c=3;
		if(c==0||n==0)
		{
			printf("0\n");
			continue;
		} 
		polya(n,c);
	}
	return 0;
}

