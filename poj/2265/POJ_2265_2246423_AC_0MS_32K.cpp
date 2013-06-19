#include<stdio.h>
#include<math.h>
int main()
{
	double x;
	int n,t,p,x0,y0,i;
	while(scanf("%d",&n)!=EOF)
	{
		x=(sqrt(12*n-3)-3)/6;
		p=(int)x;
		if(3*p*p+3*p+1!=n)
		{ 
			t=n-(3*p*p+3*p+1);
			p++;
			x0=p-1;
			y0=0;
			while(t)
			{
				t--;
				y0++;
				for(i=1;i<=p-1&&t;i++,t--)x0--,y0++;

				for(i=1;i<=p&&t;i++,t--)x0--;		
				for(i=1;i<=p&&t;i++,t--)y0--;
				for(i=1;i<=p&&t;i++,t--)x0++,y0--;	
				for(i=1;i<=p&&t;i++,t--)x0++;
				for(i=1;i<=p&&t;i++,t--)y0++;
			}
			printf("%d %d\n",x0,y0);
		}
		else
			printf("%d 0\n",p);
		
	}
	return 0;
}