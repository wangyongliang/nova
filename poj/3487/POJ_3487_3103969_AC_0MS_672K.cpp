#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 300
int main()
{
	char f[maxn],m[maxn],s[maxn][maxn],c[maxn][maxn];
	int flag[maxn],a[maxn][maxn];
	int i,j,t,n,k,min;
	char tp[maxn];
//	freopen("h.in","r",stdin);
//	freopen("h.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=j=0;i<n;i++)
		{
			scanf("%s",tp);
			m[j++]=tp[0];
		}
		m[j]='\0';
		for(i=j=0;i<n;i++)
		{
			scanf("%s",tp);
			f[j++]=tp[0];
		}
		f[j]='\0';
		for(i=0;i<n*2;i++)
		{
			scanf("%s",tp);
			for(j=2;tp[j];j++) a[tp[0]][tp[j]]=j;
			strcpy(s[tp[0]]+1,tp+2);
			s[tp[0]][0]=1;
		}
		for(i=0;i<maxn;i++) flag[i]=0;
		while(1)
		{
			for(i='A';i<='Z';i++) c[i][0]=1;
			for(i=0;m[i]&&flag[m[i]];i++);
			if(m[i]=='\0') break;
			for(i=0;m[i];i++)
			{
				if(flag[m[i]]==0)
				{
					j=m[i];
					k=s[j][s[j][0]++];
					c[k][c[k][0]++]=j;
				}
			}
			for(i='A';i<='Z';i++)
			{
				if(c[i][0]>1)
				{
					min=c[i][1];
					for(j=1;j<c[i][0];j++)
					{
						k=c[i][j];
						if(a[i][min]>a[i][k]) min=k;
					}
					if(flag[i])
					{
						if(a[i][flag[i]]>a[i][min])
						{
							flag[flag[i]]=0;
							flag[i]=min;
							flag[min]=i;
						}
					}
					else flag[i]=min,flag[min]=i;
				}

			}
		}
		i=strlen(m);
		sort(m,m+i);
		for(i=0;m[i];i++) printf("%c %c\n",m[i],flag[m[i]]);
	//	if(t)
			printf("\n");
	}
	return 0;
}
