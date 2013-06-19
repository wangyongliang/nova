#include <vector>
#include <iostream>
#include<time.h>
#define MIN(x,y) ((x)>(y)?(y):(x))
using namespace std;
#define maxn 1000
int ID[30][30];
char s[30][30];

vector<int> a[1000];
int flow[1000][1000],cal[maxn][maxn];
int st,en;
#define inf 0x7ffffff
bool vis[maxn];
int pre[maxn];
int bfs(int x,int r)
{
    int rr=0;
    int i;
    vis[x]=1;
    if(x==en) return r;
    for(i=0;i<a[x].size()&&rr==0;i++){
		int tp=MIN(r,cal[x][a[x][i]]);
        if(vis[a[x][i]]==0&&cal[x][a[x][i]]>0&&tp){			
            rr=bfs(a[x][i],MIN(r,cal[x][a[x][i]]));
            if(rr){
                cal[x][a[x][i]]-=rr;
                cal[a[x][i]][x]+=rr;
            }
        }
    }
	return rr;
}
int max_flow(){
    int i;
    int ans=0,fl;
    do{
        for(i=0;i<=en;i++) vis[i]=0;
        fl=bfs(0,inf)       ;
        ans+=fl; 
    }while(fl);
	
    return ans;
}
int  main()
{
	int n,m;
	int t,dis,i,j,k;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&dis);
		for(i=0;i<n;i++) scanf("%s",s[i]);
		m=strlen(s[0]);		k=1;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)  ID[i][j]=k++;
		}
		for(i=0;i<maxn;i++){
			for(j=0;j<maxn;j++){
				cal[i][j]=flow[i][j]=0;
			}
		}
		for(i=0;i<maxn;i++) a[i].clear();
		en=2*k;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j]>='0'){
					if(i-dis<0||i+dis>=n||j-dis<0||j+dis>=m){
						cal[ID[i][j]*2+1][en]=inf;
					}
					cal[ID[i][j]*2][ID[i][j]*2+1]=s[i][j]-'0';
					for(int ii=0;ii<n;ii++){
						for(int jj=0;jj<m;jj++){
							if(s[ii][jj]>'0'&&(ii!=i||jj!=j)){
								if((i-ii)*(i-ii)+(j-jj)*(j-jj)<=dis*dis){
									cal[ID[i][j]*2+1][ID[ii][jj]*2]=inf;
								}
							}
						}
					}
				}

			}
		}
		int total=0;
		for(i=0;i<n;i++) scanf("%s",s[i]);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j]=='L'){
					total++;
					cal[0][ID[i][j]*2]=1;
				}
			}
		}
		for(i=0;i<=en;i++)
		{
			a[i].clear();
			for(j=0;j<=en;j++)
			{
				if(cal[i][j]>0||cal[j][i]>0) a[i].push_back(j);
			}
		}
		printf("Case #%d: ",cas);
		total-=max_flow();
		if(total==0) printf("no lizard was");
		else if(total==1) printf("1 lizard was");
		else printf("%d lizards were",total);
		printf(" left behind.\n");
	}
	return 0;
}
