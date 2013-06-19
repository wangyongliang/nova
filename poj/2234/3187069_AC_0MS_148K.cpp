#include<stdio.h>
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    
    {
        int ans=0;
        for(i=0;i<n;i++) 
        {
            scanf("%d",&j);
            ans^=j;
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
        
    }
    return 0;
}
