#include <stdio.h>

int main()
{
	char a[1000000];
	char tmp;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		getchar(); 
		scanf("%c %c",&a[i],&tmp);
		j=i;
		a[j]+=tmp-'0';
		while(a[j]>'9')
		{
			a[j]-=10;
			a[j-1]++;
			j--;
		}
	}
	a[n]='\0';
	puts(a);
	return 0;
}
