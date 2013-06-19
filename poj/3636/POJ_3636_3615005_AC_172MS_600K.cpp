#include<stdio.h>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 200100
struct node
{
    int x,y;
}a[maxn];
bool cmp(const node &x,const node &y)
{
    if(x.x==y.x) return x.y<y.y;
    return x.x>y.x;
}
vector<int> heap;
vector<int> ::iterator it;
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    int w,h,max,min;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmp);
        heap.clear();
        for(i=0;i<n;i++)
        {
        //    it=heap.lower_bound(a[i].y);
        //    if()
        //    for(it=heap.begin();it!=heap.end();it++) printf("%d ",*it);
        //    printf("\n");
            it=upper_bound(heap.begin(),heap.end(),a[i].y);
            if(it==heap.end()) heap.push_back(a[i].y);
            else 
            {
            //    it++;
                j=*it;
                *it=a[i].y;
                j=*it;
            }
        }
        printf("%d\n",heap.size());
    }
    return 0;
}
