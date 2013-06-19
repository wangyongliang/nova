#include <stdio.h>
void main(){
long i,j,k,n,counter,max;
while(scanf("%ld %ld",&i,&j)!=EOF)
{
	
	printf("%ld %ld ",i,j);
	if(i>j) {n=i;i=j;j=n;}
	max=0;
	
	for(k=i;k<=j;k++)
	{counter=1;
		n=k;
		while(n!=1)
		{
			if(n%2) {n=3*n+1;counter++;}
			else {n=n/2;counter++;}
		}
		if(max<counter) max=counter;
	}
	printf("%ld\n",max);
}
} 