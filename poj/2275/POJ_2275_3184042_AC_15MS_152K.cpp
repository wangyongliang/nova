#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100];
int b[110],c[110];
int main()
{
    int n;
    int i,j,k;
  int ans;
  while(scanf("%d",&n)&&n)
  {
        for(i=0;i<n;i++) 
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        ans=0;
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<=i;j++)
            {
                if(a[j]==b[i]) break;
            }
            if(j==i) continue;
            else
            {
                if(j!=0)
                {
                    reverse(a,a+j+1);
                    c[ans++]=j+1;
                }
                if(i!=0)
                {
                    reverse(a,a+i+1);
                    c[ans++]=i+1;
                }
            }
        }
        printf("%d",ans);
        for(i=0;i<ans;i++) printf(" %d",c[i]);
        printf("\n");
    }
    return 0;
}
