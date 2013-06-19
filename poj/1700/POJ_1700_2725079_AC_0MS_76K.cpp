#include<stdio.h>
#include<stdlib.h>

int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
void main()
{
	int n, num, a[1002], i;
	
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d",&num);
		
		__int64 total = 0;

		for(i = 0;i < num;i++)
			scanf("%d",&a[i]);
		
		qsort(a, num, sizeof(a[0]), cmp);
		
		for(i = num - 1;i >= 3;i -= 2)
		{
		
           if(2 * a[1] >= a[0] + a[i - 1]) 
                 total += 2 * a[0] + a[i - 1] + a[i];                
                           
           else   
                 total += 2 * a[1] + a[0] + a[i];  
		}
		if(i == 2)total += a[0] + a[1] + a[2];
		if(i == 1)total += a[1];
		if(i == 0)total += a[0];

		printf("%ld\n",total);
	} 
}
