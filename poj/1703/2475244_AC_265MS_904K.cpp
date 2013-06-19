#include<stdio.h>
#define max 100009
int n;
int a[max][2];
int father (int &x)
{
	int i,j=0;
	i=x;
	int t;
	if(a[i][0]==-1) return 0;
	else
	{
		x=a[x][0];
		t=father(x);
		a[i][1]+=t;
		a[i][1]%=2;
		a[i][0]=x;
		return a[i][1];
	}
}
int main()
{
	int t,m,i;
	int x,y,fx,fy;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) a[i][0]=a[i][1]=-1;
		while(m--)
		{ 
			getchar();
			scanf("%c %d %d",&ch,&x,&y); 
			
			if(ch=='D')
			{
				fx=father(x);
				fy=father(y);
				if(x!=y)
				{
					a[y][0]=x;
					fx=(fx+fy)%2;
					a[y][1]=1-fx;
				}
			}
			else
			{
				fx=father(x);
				fy=father(y);
				if(x!=y)
					printf("Not sure yet.\n");
				else
				{
					if((fx+fy)%2) printf("In different gangs.\n");
					else printf("In the same gang.\n");
				}
			}
		}
	}
	return 0;
}