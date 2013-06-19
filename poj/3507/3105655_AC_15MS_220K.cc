#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10];
	int i,j,k;
	while(1)
	{
		k=0;
		for(i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
			k+=a[i];
		}
		sort(a,a+6);
		if(a[5])
		{
			k-=a[0]+a[5];
			if(k%4==3) printf("%d.75\n",k/4);
			else  if(k%4==2) printf("%d.5\n",k/4);
			else if(k%4==1) printf("%d.25\n",k/4);
			else printf("%d\n",k/4);
		}
		else break;
	}
	return 0;
}