#include <stdio.h>
#include <string.h>

int n;
char tb[1001][1001];

void work()
{
	int i,j,k=0,L = strlen(tb[0]),s=0;
	char str[1001];
	for (j=0; j<L; j++)
	{
		for (i=0; i<n; i++)
		{
			str[k++] = tb[i][j];
		}
	}
	while (str[s] == '_') s++;
	for (i=k-1; i>=s; i--)
	{
		if (str[i] == '\\')
			printf("\n");
		else if (str[i] == '_')
			printf(" ");
		else
			printf("%c",str[i]);
	}
	printf("\n\n");
}

int main()
{
	int i;
	while (scanf("%d",&n) != EOF)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s",tb[i]);
		}
		work();
	}
	return 0;
}
