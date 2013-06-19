#include <stdio.h>
int main()
{	int p,e,i,d,a,t=0;
	while(1)
	{
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==-1 && e==-1 && i==-1 && d==-1)
			break;
		a=(5544*p+14421*e+1288*i-d+21252)%21252;
		if(!a)
			a=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",++t,a);
	}
	return 0;
}