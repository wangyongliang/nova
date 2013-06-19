#include<iostream>
#include<map>
using namespace std;
 // hash for int
#define PRIME 99991
struct hashnode
{
    int key;
    int num;
    int next;
}a[1000005];
int b[1000005];
int hashl;
int hash(int num,int flag)
{
    int i;
    i = (num % PRIME+PRIME)%PRIME;
    while(a[i].next != -1){
        if(num > a[a[i].next].key) break;
        else if(num == a[a[i].next].key)
        {
            if(flag)
              a[a[i].next].num++;
            return a[i].next;
        }
        i = a[i].next;
    }
    if(flag==0) return -1;
    //插入新结点 
    a[hashl].key = num;
    a[hashl].next = -1;
    a[hashl].num = 1;
    a[hashl].next = a[i].next;
    a[i].next = hashl;
    hashl++;
    return hashl - 1;
}
void init()
{
    int i;
    for(i=0;i<PRIME;i++)
    {
        a[i].next=-1;
    }
    hashl=PRIME;
}
map<int,int> mp;
int main()
{
    int a1,a2,a3,a4,a5;
    while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)!=EOF)
    {
        mp.clear();
        init();
        for(int x1=-50;x1<=50;x1++)
        {
            for(int x2=-50;x2<=50;x2++)
            {
                if(x1==0||x2==0) continue;
                int tp=a1*x1*x1*x1+a2*x2*x2*x2;
                hash(tp,1);
             //   mp[tp]++;
            }
        }
        //cout<<"OK"<<endl;
       // cout<<mp[0]<<endl;
        long long ans=0;
        for(int x1=-50;x1<=50;x1++)
        {
            if(x1==0) continue;
            for(int x2=-50;x2<=50;x2++)
            {
                if(x2==0) continue;
                for(int x3=-50;x3<=50;x3++)
                {
                    if(x3==0) continue;
                    if(x1==0||x2==0||x3==0) continue;
                    int tp=a3*x1*x1*x1+a4*x2*x2*x2+a5*x3*x3*x3;
                    tp=-tp;
                    int index=hash(tp,0);
                    if(index!=-1) ans+=a[index].num;
                  //  cout<<tp<<endl;
//                    ans+=mp[tp];
                }
            }
        }
        printf("%I64d\n",ans);
    }
    
}
