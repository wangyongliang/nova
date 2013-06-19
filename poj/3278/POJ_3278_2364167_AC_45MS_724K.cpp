#include<stdio.h>
#define max 900000
int a[1000010];
int b[1000010],n,k;
int bfs()
{
	int start=0,end=2,i,sum=9999999,flag=0;
	b[0]=n;
	a[n]=1;
	b[1]=-1;
	while(1)
	{
		if(b[start]==k){ sum=sum>flag?flag:sum;break;}
		else if(b[start]==-1){b[end]=-1;end=(end+1)%max;flag++;}
		else
		{
			if(b[start]*2>k)
			{
				i=flag+1+b[start]*2-k;
				sum=sum>i?i:sum;
			}
			else 
			{
				if(!a[b[start]*2])
				{
					b[end]=b[start]*2;
					end=(end+1)%max;
					a[b[start]*2]=1;
				}
			}
			if(!a[b[start]+1]){b[end]=b[start]+1;end=(end+1)%max;a[b[start]+1]=1;}
			if(b[start]-1>0&&!a[b[start]-1]){
				b[end]=b[start]-1;
				end=(end+1)%max;
				a[b[start]-1]=1;
			}		
		}
		start=(start+1)%max;
	}
	return sum;

}
int main()
{
	int i;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n>=k) printf("%d\n",n-k);
		else
		{
			for(i=0;i<=k;i++)
				a[i]=0;
			printf("%d\n",bfs());
		}
	}
	return 0;
}