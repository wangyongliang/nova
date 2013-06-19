#include<iostream>
#include<algorithm>
using namespace std;
char s[100][100];
void clear(int x1,int y1,int x2,int y2)
{
	int i,j;
	for(i=x1;i<=x2;i++)
	{
		for(j=y1;j<=y1;j++)
		{
			s[i][j]=' ';
		}
	}
}
int n,m;
void paint(int x,int y,char ch)
{
	if(x>0&&x<n&&y>0&&y<m);
	else return ;
	if(ch==s[x][y]) return ;
	if(ch==' ') {
		s[x][y]=ch;
		return;
	}
	 if(ch=='-')
	{
		if(s[x][y]==' ') s[x][y]='-';
		else if(s[x][y]=='|') s[x][y]='+';
		else if(s[x][y]=='+');
		else s[x][y]='*';
	}
	else if(ch=='|')
	{
		if(s[x][y]==' ') s[x][y]='|';
		else if(s[x][y]=='-') s[x][y]='+';
		else if(s[x][y]=='+');
		else s[x][y]='*';
	}
	else if(ch=='\\')
	{
		if(s[x][y]==' ') s[x][y]='\\';
		else if(s[x][y]=='/') s[x][y]='x';
		else if(s[x][y]=='x');
		else s[x][y]='*';
	}
	else if(ch=='/')
	{
		if(s[x][y]==' ') s[x][y]='/';
		else if(s[x][y]=='\\') s[x][y]='x';
		else if(s[x][y]=='x');
		else s[x][y]='*';
	}
	else
	{
	if(s[x][y]==' ')s[x][y]=ch;
	else s[x][y]='*';
	}
}

int main()
{

	char cmd[100];
	int x1,x2,y1,y2;
//	printf(" \\\n");
	//printf("   \\\n");
//	freopen("1.out","w",stdout);
	while(scanf("%d%d",&m,&n)&&(n+m))
	{
		n++;
		m++;
		int i,j;
		for(i=0;i<=m;i++) s[n][i]=s[0][i]='-';
		for(i=0;i<=n;i++) s[i][0]=s[i][m]='|';
		s[0][0]=s[n][0]=s[0][m]=s[n][m]='+';	
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++) s[i][j]=' ';
		}
		while(scanf("%s",cmd))
		{
			if(cmd[0]>='0'&&cmd[0]<='9') 
			{
				return 0;
			}

			if(strcmp(cmd,"PRINT")==0)
			{
				for(i=0;i<=n;i++)
				{
					for(j=0;j<=m;j++) printf("%c",s[i][j]);
					printf("\n");
				}
				printf("\n");
				break;
			}
			else if(strcmp(cmd,"LINE")==0)
			{
				
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				if(x1==x2)
				{
					for(j=min(y1,y2);j<=max(y1,y2);j++) paint(j,x1,'|');
				}
				else if(y1==y2)
				{
					for(i=min(x1,x2);i<=max(x1,x2);i++) paint(y1,i,'-');
				}
				else if(y2-y1==x2-x1)
				{
					if(y1>y2) {
						swap(x1,x2),swap(y1,y2);
					}
					for(;;x1++,y1++)
					{
						paint(y1,x1,'\\');						
						if(x1==x2&&y1==y2) break;
					}
				}
				else
				{
					if(y1>y2)
					{
						swap(x1,x2);
						swap(y1,y2);
					}
					for(;;x1--,y1++)
					{
						paint(y1,x1,'/');
						if(x1==x2&&y1==y2) break;
					}
				}
			}
			else if(strcmp("CLEAR",cmd)==0)
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				for(i=min(x1,x2);i<=max(x1,x2);i++)
				{
					for(j=min(y1,y2);j<=max(y1,y2);j++)
					{
						paint(j,i,' ');
					}
				}
			}
			else if(strcmp(cmd,"TEXT")==0)
			{
				char tp[100];
				scanf("%d%d%s",&x1,&y1,tp);
				for(i=0;tp[i];i++)
				{
					paint(y1,x1,tp[i]);
					x1++;
				}
			}
			else
			{
				scanf("%d%d",&x1,&x2);
				paint(x2,x1,'o');
			}
		}
	}
	return 0;
}