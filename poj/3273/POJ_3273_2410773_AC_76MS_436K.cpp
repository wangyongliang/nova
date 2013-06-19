#include<stdio.h>
int a[1000010];
int n,m;
int f(int mid)
{
	int temp=0,i,month=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>mid) return -1;
		temp+=a[i];
		if(temp>mid) month++,temp=a[i];
		if(month>m) return -1;
	}
	if(temp!=0)	month++;
	if(month>m) return -1;
	return month;
}
int main()
{
	int i,j;
	long mid,min,max,temp;
	scanf("%d%d",&n,&m);
	max=0;
	min=999999;
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		max+=a[i];
		min=min>a[i]?a[i]:min;
	}
	while(min<max)
	{
		mid=(min+max)/2;
		temp=f(mid);
		if(temp==-1) min=mid+1;
		else  max=mid;
	} 
		printf("%ld\n",min);
	return 0;
}
