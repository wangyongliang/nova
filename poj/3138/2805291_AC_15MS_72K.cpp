
//pku 1468 1470 的其他方法

//pku 2559,3250 的共同点

//pku1690--pku1697
#include<stdio.h>
int main()
{
	int a[110],flag[110];
	int s,t,m,i,j,k,l;
	int ans;
	int p=1;
	while(scanf("%d%d%d",&s,&t,&m)&&(s+m+t))
	{
		ans=0;
		for(i=1;i<=s;i++) a[i]=flag[i]=0;
		for(i=0;i<s;i++)
		{
			scanf("%d%d%d",&j,&k,&l);
			a[j]+=k+l;
		}
		for(i=0;i<t;i++)
		{
			scanf("%d%d",&j,&k);
			if(k>=m)  flag[j]=1;
		}
		for(i=1;i<=s;i++) ans+=a[i]+flag[i];
		printf("Case %d: %d\n",p++,ans);
	}
	return 0;
}