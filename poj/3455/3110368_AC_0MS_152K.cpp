#include<stdio.h>
#define maxn 1000
struct node
{
	int x,y;
}q[maxn];
char s[10][10];
int flag[10][10][2];
int dx[]={0,0,-1,1,1,-1,-1,1};
int dy[]={1,-1,0,0,1,-1,1,-1};
int main()
{
	int x1,y1,x2,y2;
	int t,i,j,en,st,k;
//	freopen("a.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<8;i++) scanf("%s",s[i]);
		scanf("%d%d%d%d",&y2,&x2,&y1,&x1);
		y1--;
		y2--;
		x1=8-x1;
		x2=8-x2;
		if(x1==x2&&y1==y2) printf("White\n");
		else
		{
			for(i=0;i<8;i++)
			{
				for(j=0;j<8;j++) flag[i][j][0]=0;
			}
			flag[x2][y2][0]=1;
		//	if(x1==7) printf("Black\n"),x1++;
			while(x1<=8)
			{
				for(i=0;i<8;i++)
				{
					for(j=0;j<8;j++) 
					{
						flag[i][j][1]=0;
					}
				}
				for(i=0;i<8;i++)
				{
					for(j=0;j<8;j++)
					{
						if(flag[i][j][0])
						{
							for(k=0;k<8;k++)
							{
								x2=i+dx[k];
								y2=j+dy[k];
								if((x2>=0&&x2<8)&&(y2>=0&&y2<8)&&s[x2][y2]=='.') flag[x2][y2][1]=1;
							}
						}
					}
				}
				if(y1) flag[x1+1][y1-1][1]=0;
				if(y1<7) flag[x1+1][y1+1][1]=0;
				for(k=i=0;i<8;i++)
				{
					for(j=0;j<8;j++)
					{
						flag[i][j][0]=flag[i][j][1];
						k+=flag[i][j][0];
					//	printf("%d",flag[i][j][0]);
					}
				//	printf("\n");
				}
			/*	for(i=0;i<8;i++)
				{
					for(j=0;j<8;j++) printf("%d",flag[i][j][0]);
					printf("\n");
				}
				printf("\n"); */
				if(k==0)
				{
					printf("Black\n");
					break;
				}
				if(flag[x1][y1][0])
				{
					printf("White\n");
					break;
				}
				x1++;
				if(s[x1][y1]=='F'||flag[x1][y1][0])
				{
					printf("White\n");
					break;
				}
				if(x1==8) 
				{
					printf("Black\n");
					break;
				}
			}
		}
	}
	return 0;
}