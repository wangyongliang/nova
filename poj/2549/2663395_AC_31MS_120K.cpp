#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(void)
{
    int   n,i,j,k,m,flag,a[1010],s,t=0,b[10]={0};
    while(scanf("%d",&n)==1&&n)
    {
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
    
      flag=0;
      sort(a,a+n);
      for(i=n-1;!flag&&i>=0;i--)
         for(j=0;!flag&&j!=i&&j<n;j++)  
           for(m=0,k=n-1;m<k;){
               if(m==i||m==j)
                   m++;
               if(k==i||k==j)
                   k--;
               if(m<k)
               {
                   if(a[i]-a[j]==a[m]+a[k])
                   {  
					   flag=1,s=a[i];
					   b[t++]=s;
					   break;
				   }
                   else if(a[i]-a[j]<a[m]+a[k])
                        k--;
                   else
                      m++;
               }    
           }  
       if(flag)
         printf("%d\n",s);
       else
         printf("no solution\n");
    }
	return 0;
}  
