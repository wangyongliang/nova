#include<stdio.h>
#include<math.h>
int main()
{
	int a[16][3];
	int aa,b,c,i,j;
	double min,k;
	for(i=0;i<16;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	while(1)
	{
		scanf("%d%d%d",&aa,&b,&c);
		if(aa==-1) break;
		else
		{
			j=0;
			min=sqrt((a[0][0]-aa)*(a[0][0]-aa)+(a[0][1]-b)*(a[0][1]-b)+(a[0][2]-c)*(a[0][2]-c));
			for(i=1;i<16;i++)
			{
				k=sqrt((a[i][0]-aa)*(a[i][0]-aa)+(a[i][1]-b)*(a[i][1]-b)+(a[i][2]-c)*(a[i][2]-c));
				if(k<min) min=k,j=i;
			}
			printf("(%d,%d,%d) maps to (%d,%d,%d)\n",aa,b,c,a[j][0],a[j][1],a[j][2]);
		}
	}
	return 0;
}
