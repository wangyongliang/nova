#include<stdio.h>
char s[20][20];
int dx[]={0,1,-1,0,1,1,-1,-1};
int dy[]={1,0,0,-1,1,-1,1,-1};
int cnt[10];
int main()
{
	int i,j,k,l,x,y;
	int sum;
	int flag;
	for(i=0;i<10;i++) scanf("%s",s[i]);
	for(i=0;i<10;i++)
	{
		if(s[0][i]=='1'||s[9][i]=='1'||s[i][0]=='1'||s[i][9]=='1') break;
	}
	if(i<10) printf("incorrect\n");
	else
	{
		flag=1;
		cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
		for(i=1;i<9&&flag;i++)
		{
			for(j=1;j<9&&flag;j++)
			{
				if(s[i][j]=='1')
				{
					x=i;y=j;
					sum=0;
					if(s[x+1][y]=='1') k=1;
					else  k=0;
					while(s[x][y]=='1'&&flag)
					{
						sum++;
						s[x][y]='.';
						for(l=0;l<8;l++)
						{
							if(l==k||l+k==3) continue;
							if(s[x+dx[l]][y+dy[l]]=='1') break;
						}
						if(l<8) flag=0;
						x+=dx[k];
						y+=dy[k];
					}
					cnt[sum]++;
				}
			}
		}
		if(flag&&cnt[1]==4&&cnt[2]==3&&cnt[3]==2&&cnt[4]==1) printf("correct\n");
		else printf("incorrect\n");
	}
	return 0;
}