#include<stdio.h>
#define max 3000009
int a[max][2];
int father(int &x)
{
	int i,t;
	i=x;
	if(a[x][0]==-1) return 0;
	else
	{
		x=a[x][0];
		t=father(x);
		a[i][1]+=t;
		a[i][0]=x;
		return a[i][1];
	}
}
int main()
{
	int n,m,p;
	int x,y,fx,fy,i;
	char ch;
	scanf("%d",&p);
	for(i=0;i<max;i++) a[i][0]=-1,a[i][1]=1;
	while(p--)
	{
		getchar();
		scanf("%c",&ch);
		if(ch=='M')
		{
			scanf("%d%d",&x,&y);
			fx=father(x);
			if(fx>a[x][1]) a[x][1]=fx;
			fy=father(y);
			if(fy>a[y][1]) a[y][1]=fy;
			if(x!=y)
			{
				a[y][0]=x;
				fx=a[y][1];
				a[y][1]=a[x][1];
				a[x][1]+=fx;
			}
		}
		else
		{
			scanf("%d",&x);
			y=x;
			fx=father(x);
			if(fx>a[x][1]) a[x][1]=fx;
			printf("%d\n",a[x][1]-fx-1);
		}
	}
	return 0;
}