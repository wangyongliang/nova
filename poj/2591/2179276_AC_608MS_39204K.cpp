#include <stdio.h>

const long max=10000000;
	long num[max+5];

int main()
{
	long j,k,m;

	__int64 form[3][3];//form[i][0]表示指向第几个num，form[i][1]存值
	num[0]=1;
	form[0][0]=0;
	form[0][1]=3;
	form[1][0]=0;
	form[1][1]=4;
	k=0;
	for (j=1;j<=max;j++)
	{
		if (form[0][1]<form[1][1])
		{
			k++;
			num[k]=form[0][1];
			form[0][0]++;
			form[0][1]=num[form[0][0]]*2+1;
		}
		else if (form[0][1]>form[1][1])
		{
			k++;
			num[k]=form[1][1];
			form[1][0]++;
			form[1][1]=num[form[1][0]]*3+1;
		}
		else
		{
			k++;
			num[k]=form[1][1];
			form[0][0]++;
			form[0][1]=num[form[0][0]]*2+1;
			form[1][0]++;
			form[1][1]=num[form[1][0]]*3+1;
		}
	}
	while (scanf("%ld",&m) != EOF)
	{
		printf("%ld\n",num[--m]);
	}

	return 1;
}