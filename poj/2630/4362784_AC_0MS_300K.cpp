#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define ABS(x) (x)>0?(x):-(x)
#define SP(x) setprecision(x)
using namespace std;

int r,c;
int dx[]={-1,-1,-1, 0, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 0, 1,-1, 0, 1};
#define maxn 25
int change[30][30];
int ans1,ans2;
void dfs(int s,int t,int cnt,int x)
{
    if(cnt>ans1) return;
    if(s==(1<<(r*c))-1)
    {
        while(x<r*c) t*=2,x++;
        if(ans1>cnt) {
            ans1=cnt;
            ans2=t;
        }
    }
    else
    {
        int i=(x+1)/c;
        int j=(x+1)%c;
        if(i>=2)
        {
            int tq=(i-1)*c;
            tq=(1<<tq)-1;
            if((s&tq)<tq) return;
        }
        if(x+1<r*c){
        dfs(s,t*2+0,cnt,x+1);        
        int tp1=(~change[i][j])&s;
        int tp2=change[i][j]&s;
        tp2^=change[i][j];
        tp1+=tp2;
        dfs(tp1,t*2+1,cnt+1,x+1);
    }
    }
}
int  main()
{
    char s[10][10];
    int i,j,k;
    bool flg[10];
    int t=1;
    while(cin>>r>>c){
        if(r+c==0) return 0;
        for(i=0;i<3;i++) scanf("%s",s[i]);        
        for(k=i=0;i<3;i++){
            for(j=0;j<3;j++) {
                if(s[i][j]=='*') flg[k]=1;
                else flg[k]=0;
                k++;
            }
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                change[i][j]=0;
                for(k=0;k<9;k++){
                    int xx=i+dx[k];
                    int yy=j+dy[k];
                    if(xx>=0&&xx<r&&yy>=0&&yy<c&&flg[k])
                    {
                        change[i][j]+=(1<<(xx*c+yy));
                    }                
                    
                }
            }
        }
        printf("Case #%d\n",t++);
        ans1=1000;
        dfs(0,0,0,-1);
        if(ans1==1000) printf("Impossible.\n");
        else 
        {
            int ck=0;
            vector<int> ans;
            ans.clear();
            for(i=r*c;i>=0;i--)
            {
                if(ans2%2==1){ans.push_back(i);
                }
                ans2/=2;
            }
            for(i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]+1);
            printf("\n");
        }
    }
    system("pause");
    return 0;
}
