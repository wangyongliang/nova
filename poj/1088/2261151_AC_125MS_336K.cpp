#include <stdio.h>

#define maxsize 100
#define inf 10001

int hill[maxsize+2][maxsize+2];
int vis[maxsize+2][maxsize+2];
const int dis[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int DFS(int x,int y)
{
    int i;
    for(i=0; i<4; i++){
        if(hill[x][y]>hill[x+dis[i][0]][y+dis[i][1]]&&vis[x][y]+1>vis[x+dis[i][0]][y+dis[i][1]]){
                vis[x+dis[i][0]][y+dis[i][1]]=vis[x][y]+1;
                DFS(x+dis[i][0],y+dis[i][1]);
        }    
    }    
    return 0;
}    

int main()
{
    int m,n;
    int i,j,max;
    int x,y;
    
    scanf("%d %d",&m,&n);

    for(i=0; i<=m+1; i++) hill[i][0]=hill[i][n+1]=inf;
    for(i=0; i<=n+1; i++) hill[0][i]=hill[m+1][i]=inf;
    
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            scanf("%d",&hill[i][j]);
            vis[i][j]=0;  
  }
 }  
    
    while(1){
        max=-1;
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++)
          if(vis[i][j]==0&&hill[i][j]>max){ max=hill[i][j]; x=i; y=j; }
    if(max==-1) break;
     vis[x][y]=1;
    DFS(x,y);
 }
 for(i=1; i<=m; i++)
  for(j=1; j<=n; j++){
      if(max<vis[i][j]) max=vis[i][j];
  }
    printf("%d",max);
    return 0;
}
