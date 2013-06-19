#include<stdio.h>
char s[1000][8],c[9];
int main()
{
	int n,i,j,a[8],k,b[8],flag,sum;
	while(scanf("%d",&n)&&n)
	{
		sum=0;
		for(i=0;i<n;i++) scanf("%s",s[i]);
		scanf("%s",c);
		for(flag=i=0;c[i];i++)
		{
			if(c[i]=='_')flag++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;c[j];j++) a[j]=1;
			for(j=0;s[i][j];j++)
			{
				b[j]=0;
				for(k=0;c[k];k++)
				{
					if(c[k]==s[i][j]&&a[k]) 
					{
						b[j]=1;
						a[k]=0;
						break;
					}
				}
			}
			for(j=0,k=0;s[i][j];j++)
			{
				if(!b[j]) k++;
			}
			if(k<=flag) sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}