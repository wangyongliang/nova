#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

#define maxn 100010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

int cnt[maxn];
int index[maxn];
int heap[maxn];
vector<int> a[maxn];
bool flag[maxn];

int m;
int n;
void shiftdown(int k)
{
    int i=k;
    int j=k*2;
    heap[0]=heap[k];
  //  cout<<"m = "<<m<<endl;
    while(j<=m)
    {
        if(j+1<=m&&cnt[heap[j+1]]<cnt[heap[j]]) j++;
        if(cnt[heap[j]]<cnt[heap[0]])
        {
            heap[i]=heap[j];
            index[heap[i]]=i;
            i=j;
            j=i*2;
        }
        else break;
    }
    heap[i]=heap[0];
    index[heap[i]]=i;
  /*  cout<<"------------"<<endl;
    for(i=1;i<=m;i++)
    {
        cout<<heap[i]<<" "<<index[i]<<" "<<cnt[heap[i]]<<endl;
    }
    */
    
}

void heap_pop()
{
    if(m>1)
    {
        heap[1]=heap[m];
        m--;
        shiftdown(1);
    }
    else if(m==1) m=0;
    else return ;
}

struct node
{
    int x,y;
};
vector<node> test;
bool cmp(const node &x,const node &y)
{
    if(x.x==y.x) return x.y<y.y;
    else return x.x<y.x;
}
int main()
{
    int i,j;
    int t=1;
    while(scanf("%d%d",&n,&m)&&(n+m))        
    {
        for(i=1;i<=n;i++)
        {
            cnt[i]=0;
            index[i]=i;
            heap[i]=i;
            a[i].clear();
            flag[i]=1;
        }
        test.clear();
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==y) continue;
            a[x].push_back(y);
            a[y].push_back(x);
            if(x>y) swap(x,y);
            node tp;
            tp.x=x;
            tp.y=y;
            test.push_back(tp);
            if(x==y) while(1);
          
        }
        sort(test.begin(),test.end(),cmp);
        for(i=0;i+1<test.size();i++)
        {
            node tp1=test[i];
            node tp2=test[i+1];
            if(tp1.x==tp2.x&&tp1.y==tp2.y) while(1);
         //   if(test[i]==test[i+1]) while(1);
        }
        m=n;
        int pre=1;
        int ans=0;
        do
        {
            pre=heap[1];
            if(pre!=1&&cnt[pre]>=ans) break;
            flag[pre]=0;
            ans++;
            heap_pop();
           // cout<<pre<<" is conected "<<endl;
            for(i=0;i<a[pre].size();i++)
            {
                if(flag[a[pre][i]]==0) continue;
                cnt[a[pre][i]]++;
                shiftdown(index[a[pre][i]]);
            }
        }while(m>0);
        printf("Case %d: %d\n",t++,ans-1);
        
    }
    return 0;
}
