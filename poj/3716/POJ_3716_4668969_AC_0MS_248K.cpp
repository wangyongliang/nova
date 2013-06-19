#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<list>
using namespace std;
int main()
{
    int a,b;
    int t;
    scanf("%d",&t);
    while(t--&&scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%.3lf\n",(a+b+10.0)/7.0);
    }
    system("pause");
    return 0;
}
