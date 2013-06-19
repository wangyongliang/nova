#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

#define ps system("pause")

vector<pair<int,int> > a;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.first+x.second<y.first+y.second;
}
int main()
{
    
    int n;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        a.clear();
        pair<int,int> tmp;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&tmp.first,&tmp.second);
            a.push_back(tmp);
        }
        sort(a.begin(),a.end(),cmp);
        int ans=-a[0].second;
        int total=a[0].first;
//        cout<<"-----------"<<endl;
//        cout<<a[0].first<<" "<<a[0].second<<endl;
        for(i=1;i<a.size();i++)
        {
//                    cout<<a[i].first<<" "<<a[i].second<<endl;
            if(ans<total-a[i].second)
            {
                ans=total-a[i].second;
            }
            total+=a[i].first;
        }
        cout<<ans<<endl;
    }
    return 0;
}
