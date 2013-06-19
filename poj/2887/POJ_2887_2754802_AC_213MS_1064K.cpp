#include<stdio.h>
#include<string.h>
char s[1000100];
int a[2100][2];
int main()
{
	int n,i,j,p,sum,k;
	char s1[10];
	char ans;
	while(scanf("%s",s)!=EOF)
	{
		sum=strlen(s);
		scanf("%d",&n);
		k=0;
		while(n--)
		{
			scanf("%s",s1);
			if(s1[0]=='I')
			{
				scanf("%s%d",s1,&p);
				if(p>sum) p=sum+1;
				for(i=k;i>0;i--)
				{
					if(a[i-1][1]>=p)
					{
						a[i][0]=a[i-1][0];
						a[i][1]=a[i-1][1]+1;
					}
					else break;
				}
				k++;
				sum++;
				a[i][0]=s1[0];
				a[i][1]=p;
			}
			else 
			{
				scanf("%d",&p);
				if(!k||a[0][1]>p) 
				{
					printf("%c\n",s[p-1]);
					continue;
				}
				if(a[0][1]==p) ans=a[0][0];
				else 
				{
					j=a[0][1]-1;
					for(i=1;i<k;i++)
					{
						if(p<a[i][1]) 
						{
							ans=s[j+p-a[i-1][1]-1];
							break;
						}
						else if(p==a[i][1]) 
						{
							ans=a[i][0];
							break;
						}
						else j+=a[i][1]-a[i-1][1]-1;
					}
					if(p>a[k-1][1]) ans=s[j+p-a[k-1][1]-1];
				}
				printf("%c\n",ans);
			}
		}
	}
	return 0;
}
