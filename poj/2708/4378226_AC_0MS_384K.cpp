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
#include <queue>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define ABS(x) (x)>0?(x):-(x)
#define SP(x) setprecision(x)
using namespace std;
map<string ,int>mp;
vector<int> a[13];
int dp[(1<<12)+10][2];
int tp[13],b[13];
int cnt,n,m;
struct node
{
	int x,y;
};
struct cmp
{
	bool operator ()(const node &x,const node &y)
	{
		if(x.y==y.y) return x.x<y.x;
		return x.y>y.y;
	}
};
priority_queue<node,vector<node>,cmp> heap;

void dfs(int deep,int k,int sum){
    if(deep==n){
        if(dp[sum][cnt%2]>cnt) {
			dp[sum][cnt%2]=cnt;
			node tp;
			tp.x=sum;
			tp.y=cnt;
			heap.push(tp);
        }
    }
    else{
        if(tp[deep]==0) dfs(deep+1,k,sum*2);
        else if(tp[deep]==1){
            dfs(deep+1,k,sum*2);
            if(k>0&&(b[deep]==2||b[deep]==cnt%2)) dfs(deep+1,k-1,sum*2+1);
        }
        else dfs(deep+1,k,sum*2+1);
    }
}
void check(int sum){
    int i,j;
    for(i=n-1;i>=0;i--){
        tp[i]=sum%2;
        sum/=2;
        if(tp[i]==1) tp[i]=2;
    }
 //   for(i=0;i<n;i++) printf("%d ",tp[i]);
 //   printf("\n");
    for(i=0;i<n;i++){
        if(tp[i]==0){
//            printf("%d\n",a[tp[i]])
            for(j=0;j<a[i].size();j++){
                if(tp[a[i][j]]!=2) break;
            }
            if(j==a[i].size()) tp[i]=1;
        }
     //   else tp[i]=2;
    }
}
void bfs()
{
	int i;
	for(i=0;i<(1<<n);i++) dp[i][0]=dp[i][1]=0x7ffffff;
	node tq;
	tq.x=0;
	tq.y=1;
	dp[0][1]=1;
	heap.push(tq);
	while(heap.size())
	{
		tq=heap.top();
		heap.pop();
		if(tq.y>dp[tq.x][tq.y%2]) continue;
		cnt=tq.y+1;
		check(tq.x);
//		for(int i=0;i<n;i++) printf("%d ",tp[i]);
	//	if(cnt%2==0) printf("F");
	//	else printf("S");
//		printf("\n");
		dfs(0,m,0);
	/*	if(dp[tp.x][cnt%2]>tp.y+1)
		{
			dp[tp.x][(1+tp.y)%2]=tp.y+1;
			tp.y++;
			heap.push(tp);
		} */
	}
}
int  main()
{
    string str,str1,str2;
    int i,j;
    while(cin>>n>>m){
        if(n==-1&&m==-1) break;
        mp.clear();
        for(i=0;i<n;i++) {
            cin>>str;
            mp[str]=i+1;
        }
        for(i=0;i<n;i++){
            cin>>str>>str1>>j;
            int x=mp[str]-1;
            if(str1[0]=='F') b[x]=0;
            else if(str1[0]=='S') b[x]=1;
            else b[x]=2;
            a[x].clear();
            while(j--){
                cin>>str;
                a[x].push_back(mp[str]-1);
            }
        }
      //  bfs(0);
        //int ans1=dp[(1<<n)-1];
        bfs();
		int ans;
        if(dp[(1<<n)-1][0]>dp[(1<<n)-1][1]) ans=dp[(1<<n)-1][1];
		else ans=dp[(1<<n)-1][0];
        cout<<"The minimum number of semesters required to graduate is "<<ans-1<<"."<<endl;
       // if(ans1<ans2) cout<<ans1<<endl;
       // else cout<<ans2<<endl;
        
    }
    system("pause");
    return 0;
}

