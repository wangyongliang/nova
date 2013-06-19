#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool flag[2010]={0};
int p[2010];
void init()
{
	int i,j,k;
	int x,y;
	p[0]=0;
	p[1]=p[2]=p[3]=1;
	for(i=4;i<=2010;i++)
	{
//		m=0;
		for(j=1;j<=i;j++)
		{
			x=j-3;
			y=i-j-2;
			if(x<0) x=0;
			if(y<0) y=0;
			k=p[x]^p[y];
		//	a[m++]=k;
			flag[k]=1;
		}
	//	sort(a,a+m);
	//	printf("%d\n",m);
	//	if(max<m) max=m;
		for(j=0;j<=i;j++)
		{
			if(!flag[j]) break;
			else flag[j]=0;
		}
		p[i]=j;
		for(;j<=i;j++) flag[j]=0;
	}
//	printf("OK\n");
//	printf("%d\n",max);
}
int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		if(n<3) break;
		if(p[n]==0) p[n]=2;
		else  p[n]=1;
		printf("%d\n",p[n]);
	}
	return 0;
}
