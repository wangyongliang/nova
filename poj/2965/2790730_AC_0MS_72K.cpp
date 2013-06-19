#include<stdio.h>
bool flag[4][4]={0};
char s[5][5];
void f(int i,int j)
{
	int k;
	for(k=0;k<4;k++) flag[i][k]=1-flag[i][k];
	for(k=0;k<4;k++)
	{
		if(k!=i) flag[k][j]=1-flag[k][j];
	}
}
int main()
{
	int i,j;
	for(i=0;i<4;i++) scanf("%s",s[i]);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(s[i][j]=='+') f(i,j);
		}
	}
	int cnt=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++) cnt+=flag[i][j];
	}
	printf("%d\n",cnt);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(flag[i][j]) printf("%d %d\n",i+1,j+1);
		}
	}
	return 0;
}