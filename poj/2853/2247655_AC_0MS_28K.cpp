#include<stdio.h>
#include<math.h>
int main()
{
long m,sum,i,k,t,j,n;
double x1,x2;
scanf("%d",&t);
while(t--)
{
	scanf("%d%ld",&j,&n);
	x2=n;
   x1=(sqrt(8*x2+1)-1)/2;
   i=(long)x1;
   n*=2;
   for(m=1,sum=0;m<=i;m++)
   {
    if(n%m==0)
    {
     k=n/m;
     if((m%2^k%2==0)==0) sum++;
    }
   }
   printf("%d %ld\n",j,sum-1);
}
return 0;
}
