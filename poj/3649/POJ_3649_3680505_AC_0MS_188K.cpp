#include<stdio.h>
#include<string>
char s[50][100];
char ans[40][100];
int main()
{
	int n,i,j,k;
	int l,cnt[21], t=1;
	while(scanf("%d",&n)&&n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<100;j++) s[i][j]='.';
			s[i][100]=0;
		}
		for(i=0;i<n;i++)gets(s[i]+20);
		int len=strlen(s[0]);
		for(i=0;i<len;i++)
		{
			if(s[0][i]==' ')
			{
				for(k=0;k<n;k++)
				{
					s[k][i]='.';
					for(j=i+1;j<len;j++) if(s[k][j]==' '||s[k][j]=='#'||s[k][j]=='0') break;
					if(j==len||s[k][j]==' ') j=1000;
					cnt[k]=j;
					for(j=i;j>=0;j--) if(s[k][j]=='#'||s[k][j]=='0') break;
					if(j==-1) j=-1000;
					cnt[k]=cnt[k]-j-2;
					for(j=0;j<len;j++) ans[k][j]='.';
					ans[k][j]=0;
				}
				int min=0;
				for(k=0;k<n;k++) min=cnt[min]>cnt[k]?k:min;	
				for(l=0;l<i;l++)
				{
					for(k=0;k<n;k++)  ans[k][l]=s[k][l];
				}
				for(l=i;l<len;l++)
				{
					for(k=0;k<n;k++) if(s[k][l]!='.') break;
					if(k<n) break;
				} 
				min=cnt[min];
				for(;l<len&&s[0][l]!=' ';l++)
				{
					for(k=0;k<n;k++) 
						if(s[k][l]!='.') ans[k][l-min]=s[k][l];
				}
				for(;l<=len;l++)
					for(k=0;k<n;k++) ans[k][l]=s[k][l];
				for(k=0;k<n;k++) 	strcpy(s[k],ans[k]);
				len=strlen(s[0]);
			}
		}
		for(l=len-1;l>=0;l--)
		{
			for(k=0;k<n;k++) if(s[k][l]=='#') break;
			if(k<n) break;
		}
		for(k=0;k<n;k++) s[k][l+1]=0;
		len=strlen(s[0]);
		for(l=0;l<len;l++)
		{
			for(k=0;k<n;k++) if(s[k][l]=='#') break;
			if(k<n) break;
		}
		printf("%d\n",t++);
		for(k=0;k<n;k++)
		{
			for(i=l;i<len;i++)
			{
				if(s[k][i]=='#') printf("#");
				else printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}