#include<stdio.h>
#define max 1000009
int a[max][2];
int father(int &x)
{
	int i=x,j;
	if(a[x][0]==-1) return 0;
	else
	{
		x=a[x][0];
		j=father(x);
		a[i][0]=x;
		a[i][1]+=j;
		return a[i][1];
	}
}
int main()
{
	int p;
	int x,y,fx,fy;
	char ch;
	int i;
	for(i=1;i<max;i++) a[i][0]=-1,a[i][1]=1;
	scanf("%d",&p);
	while(p--)
	{
		getchar();
		scanf("%c",&ch);
		if(ch=='M')
		{
			scanf("%d%d",&x,&y);
			fx=father(x);
			fy=father(y);
			if(fx>a[x][1]) a[x][1]=fx;
			if(fy>a[y][1]) a[y][1]=fy;
			if(x!=y)
			{
				a[y][0]=x;
				fy=a[y][1];
				a[y][1]=a[x][1];
				a[x][1]+=fy;
			}
		}
		else
		{
			scanf("%d",&x);
			fx=father(x);
			if(fx>a[x][1]) a[x][1]=fx;
			printf("%d\n",a[x][1]-fx-1);
		}
	}
	return 0;
}