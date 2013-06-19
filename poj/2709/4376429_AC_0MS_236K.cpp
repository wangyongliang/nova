#include <iostream>
#include<algorithm>
using namespace std;
int a[15],n,g;
int  main()
{
    int n,i,j;
    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        scanf("%d",&g);
        sort(a,a+n);
        for(i=0;i<g;i++)        
        {
            sort(a,a+n);
            a[0]++;
            a[1]++;
            a[2]++;
        }
        sort(a,a+n);
        int ans=a[n-1]/50+(a[n-1]%50!=0);
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}

