#include<stdio.h>
int a[100],sum;
void find(int m,int n,int k)
{
    int i;
    if(m==0)
    {
 /*       for(i=0;i<k;i++)
            printf("%d ",a[i]);
        printf("\n");*/
		sum++;
    }
    else
    {
        for(i=n;i>0;i--)
        {
            if(i>m)
                continue;
            else
            {
                a[k]=i;
                find(m-i,i,++k);
                k--;
            }    
        }
    }
}
void main()
{
    int n,t,m,i;
	scanf("%d",&t);
	while(t--)
    {
		sum=0;
		scanf("%d %d",&n,&m);
			find(n,m,0);
		printf("%d\n",sum);
	}
}