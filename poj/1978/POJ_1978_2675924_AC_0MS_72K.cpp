#include<stdio.h>
int a[60],n,p,c;
void f()
{
	int b[60],i,j;
	for(j=i=0;j<c;j++,i++) b[i]=a[p+j];
	for(j=0;j<p;i++,j++) b[i]=a[j];
	for(j=p+c;j<n;j++,i++) b[i]=a[j];
	for(i=0;i<n;i++) a[i]=b[i];
}
int main()
{
	int r,i;
	while(scanf("%d%d",&n,&r)&&(n+r))
	{
		for(i=0;i<n;i++) a[i]=n-i;
		while(r--)
		{
			scanf("%d%d",&p,&c);
			if(p==1) continue;
			p--;
			f();
		}
		printf("%d\n",a[0]);
	}
}