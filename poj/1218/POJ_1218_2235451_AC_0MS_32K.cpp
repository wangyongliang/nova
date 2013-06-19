#include<stdio.h>//只有平方数字最后才是打开的，所以只要计算有多少个平方数字就可以了
#include<math.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",(int)sqrt(m));
	}
	return 0;
}