#include<stdio.h>
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node
{
	int x,y;
}a[1000];
int n;
int flag[300]={0};
int f(double x,double y)
{
	int i;
	int cnt=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i].y==a[i+1].y) continue;
		else
		{
			if(a[i].x>x&&a[i].y>y&&y>a[i+1].y) cnt++;
			if(a[i].x>x&&a[i+1].y>y&&y>a[i].y) cnt++;
		}
	}
	return cnt&1;
}
char ans[40][40];
char s[100];
int main()
{
	int t,i,j,xx,yy,k,cas=1;
	scanf("%d",&t);
	double x,y;
	while(t--)
	{
		scanf("%d%d",&a[0].x,&a[0].y);
		scanf("%s",s);
		for(n=1;s[n-1];n++) 
		{
			if(s[n-1]=='.') break;
			if(s[n-1]=='E') j=2;
			else if(s[n-1]=='W') j=3;
			else if(s[n-1]=='N') j=0;
			else j=1;
			a[n].x=a[n-1].x+dx[j];
			a[n].y=a[n-1].y+dy[j];
		}
		for(i=0;i<40;i++)
		{
			for(j=0;j<40;j++) ans[i][j]='.';
			ans[i][j]=0;
		}
		for(i=0;i<40;i++)
		{
			for(j=0;j<40;j++)
			{
				x=i+0.5;
				y=j+0.5;
				if(f(x,y)) ans[i][j]='*';
			}
		}
		for(i=0;i<32;i++)
		{
			for(j=0;j<32;j++)
			{
				if(ans[i][j]=='*')
				{
					for(k=0;k<4;k++)
					{
						xx=i+dx[k];
						yy=j+dy[k];
						if(xx>=0&&xx<32&&y>=0&&yy<32&&ans[xx][yy]=='.') ans[xx][yy]='X';
					}
				}
			}
		}
		printf("Bitmap #%d\n",cas++);
		for(i=31;i>=0;i--)
		{
			for(j=0;j<32;j++)
			{
				if(ans[j][i]=='*') ans[j][i]='.';
				printf("%c",ans[j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}