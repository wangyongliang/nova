#include<stdio.h>
#include<algorithm>
using namespace std;
int ck(int x)
{
	int ans=0;
	while(x%2==0) x/=2,ans++;
	if(x==1) return ans;
	else return -1;
}
int f(int x,int y)
{
	if(x==1) return y;
	if(y==1) return x;
	int flag1[40]={0},flag2[40]={0};
	if(x<y) swap(x,y);
	int q[100],k,i,j;
	int tp1=ck(x),tp2=ck(y);
	if(tp1>0&&tp2>0)
	{
		x=tp1;
		y=tp2;
		for(i=0;i<40;i++,x/=2) flag1[i]=x%2;
		for(i=0;i<40;i++,y/=2) flag2[i]=y%2;
		q[0]=1;
		k=1;
		for(i=0;i<40;i++)
		{	
			if(flag1[i]||flag2[i])
			{
				tp1=1<<(1<<i);
				if(flag1[i]&&flag2[i]) 	q[k++]=tp1/2*3;
				else q[0]*=tp1;
			}
		}
		for(i=1;i<k;i++) q[0]=f(q[0],q[i]);
		return q[0];
	}
	else
	{
		int ans=0;
		for(i=0;i<40;i++,x/=2,y/=2) 
		{
			flag1[i]=x%2;
			flag2[i]=y%2;
		}
		for(i=0;i<40;i++)
		{
			for(j=0;j<40;j++)
			{
				if(flag1[i]&&flag2[j])
				{	int tp=f(1<<i,1<<j);
				ans^=tp;
				}
			}
		}
		return ans;
	}
}
int main()
{
	int n;
	int ans=0;
	int tp1,tp2,i;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&tp1,&tp2);
			tp1=f(tp1,tp2);
			scanf("%d",&tp2);
			tp1=f(tp1,tp2);	
		//	printf("%d\n",tp1);
		ans^=tp1;
		}

		if(!ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}