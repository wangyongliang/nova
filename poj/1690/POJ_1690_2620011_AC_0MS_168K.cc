#include <stdio.h>
int q[255];
char s[300];
char ans[300];
int main()
{
	int i,j,t,st,k,cnt,l;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		st=0;
		j=0;
		for(i=0;s[i];i++)
		{
			if(s[i]=='(')
			{
				ans[j++]='#';
				q[st++]=i;
			}
			else  if(s[i]==')')
			{
				k=q[st-1];
				for(k--;s[k]==' ';k--);
				for(l=k+1,cnt=0;l<i;l++)
				{
					if(s[l]>='A'&&s[i]<='Z')cnt++;
				}
				if(k>0&&s[k]=='-'&&cnt>1)
				{
					ans[q[st-1]]='(';
					ans[j++]=')';
				}
				else 
				{
					ans[j++]='#';
				}
				st--;
			}
			else ans[j++]=s[i];
		}
		for(i=0;i<j;i++)
		{
			if(ans[i]!='#'&&ans[i]!=' ') printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}