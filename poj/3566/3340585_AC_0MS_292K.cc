#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
char tb[60],gh[50][10];

int main()
{
	int i,j,k,l;
	m = 0;
	for (i=0; i<26; i++)
	{
		tb[m++] = char(i+'A');
	}
	for (i=0; i<26; i++)
	tb[m++] = char(i+'a');
	scanf("%d",&n);
	if (n>50 || n<1) while (1);
	if (n==1)
	{
	printf("1 1 1\nA\n");
	}
	else if (n==2)
	{
		printf("1 2 1\nAB\n");
	}
	else if (n==3)
	{
		printf("1 2 2\nAB\nCC\n");
	}
	else if(n==4)
	{
		printf("2 2 2\nAB\nCC\n\nDD\nDD\n");
	}
	else
	{
		l = n/3*2;
		if (n%3) l++;
		k = 0;
		for (i=0; i<l && k<n; i++)
		{
		    if (i%2==0)
		    {
		    	gh[i][0] = tb[k++];
		    	if (k==n) break;
		    	gh[i][4] = tb[k++];
		    }
		    else
		    	gh[i][2] = tb[k++];
		}
		printf("%d %d %d\n",k,5,l);
		for (int u=0; u<k; u++)
		{
			int t = 0;
			for (i=0; i<l; i++)
			{
				if (i%2==0)
				{
					for (j=0; j<5; j++)
					{
						if ((j==0 || j==4) && t<k) printf("%c",gh[i][j]),t++;
						else printf("%c",tb[u]);
					}
				}
				else
				{
					for (j=0; j<5; j++)
					{
						if (j==2 && t<k) printf("%c",gh[i][j]),t++;
						else printf("%c",tb[u]);
					}
				}
				printf("\n");
			}
   			printf("\n");
			//printf("\n");
			//system("PAUSE");
		}
	}
	return 0;
}
