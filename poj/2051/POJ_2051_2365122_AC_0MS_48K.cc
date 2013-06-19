#include<stdio.h>
int a[1005][3],n;
void shiftdown(int t)
{
	int b[3],i,j;
	i=t;
	j=t*2;
	b[0]=a[t][0];
	b[1]=a[t][1];
	b[2]=a[t][2];
	while(j<n)
	{
		if((a[j][2]>a[j+1][2]&&j+1<n)||(a[j][2]==a[j+1][2]&&a[j][0]>a[j+1][0])) j++;
		if(b[2]>a[j][2])
		{
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[i][2]=a[j][2];
			i=j;
			j*=2;
		}
		else if(b[2]==a[j][2])
		{
			if(b[0]>a[j][0])
			{
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[i][2]=a[j][2];
			i=j;
			j*=2;
			}
			else break;
		}
		else break;
	}
	a[i][0]=b[0];
	a[i][1]=b[1];
	a[i][2]=b[2];
}
int main()
{
	int i,k;
	char s[20];
	n=1;
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='#') break;
		else
		{
			scanf("%d%d",&a[n][0],&a[n][1]);
			a[n][2]=a[n][1];
			n++;
		}
	}
	scanf("%d",&k);
	for(i=n/2;i>0;i--)
	{
		shiftdown(i);
	}
	for(;k;k--)
	{
		printf("%d\n",a[1][0]);
		a[1][2]+=a[1][1];
		shiftdown(1);
	}
	return 0;
}