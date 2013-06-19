#include<stdio.h>
#include<math.h>
int a[3610]={0};
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF){
	scanf("%d",&i);
	for(k=1;k<n;k++)
	{
		scanf("%d",&j);
		a[abs(j-i)]=1;
		i=j;
	}
	for(k=1;k<n;k++)
	{
		if(!a[k]) break;
	}
	if(k==n) printf("Jolly\n");
	else printf("Not jolly\n");
	for(i=1;i<n;i++) a[i]=0;}
	return 0;
}