#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *n,const void *m)
{
return *(int *)m-*(int *)n;
}
int main()
{
	int a[100];
	int i,j,k;
scanf("%d",&k);
for(i=0;i<k;i++) scanf("%d",&a[i]);
qsort(a,k,sizeof(a[0]),cmp);
double ans=(double) a[0];
for(i=1;i<k;i++) ans=2*sqrt(ans*a[i]);
printf("%.3lf\n",ans);
}