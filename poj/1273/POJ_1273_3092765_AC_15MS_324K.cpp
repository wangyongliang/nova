#include<stdio.h>
#include<string.h>
#define MAX 210
int Map[MAX][MAX];
int n, M, SUM, Path[MAX], distance[MAX], Min;
int IN(){
      int i, x, y, d;
      if( scanf( "%d %d", &M, &n ) == EOF )return 0;    // M 是 边的数目， n 是点的数目
      memset( Map, 0, sizeof( Map ) );
      for( i = 1; i <= M; i++ ){
          scanf( "%d %d %d", &x, &y, &d );     // 点x 到点y流量为 d 
          Map[x][y] += d;
      }
      return 1;
}
void Dijkstra(){
      int mindis, i, j, u, s[MAX];
      for( i = 1; i <= n; i++ ){
          distance[i] = Map[1][i];
          s[i] = 0;
        
          if( i != 1 && distance[i] > 0 )Path[i] = 1;
          else Path[i] = -1;
      }
      s[1] = 1;
      for( i = 2; i <= n; i++ ){
          mindis = 0;
          for( j = 1; j <= n; j++ ){
              if( s[j] == 0 && distance[j] > mindis ){
                  u = j;
                  mindis = distance[j];
              }
          }
          if( mindis == 0 )return;
          s[u] = 1;
          for( j = 1; j <= n; j++ ){
              if( s[j] == 0 && Map[u][j] > 0 && distance[u] + Map[u][j] > distance[j] ){
                  distance[j] = distance[u] + Map[u][j];
                  Path[j] = u;
              }
          }
      }
}

void Find(){
      int s, t;
      Min = 2000000000;
      s = n;
      t = Path[n];
      while( t != -1 ){
          if( Map[t][s] < Min )Min = Map[t][s];
          s = t;
          t = Path[t];
      }
}

void Change(){
      int s, t;
      s = n;
      t = Path[n];
      while( t != -1 ){
          Map[t][s] -= Min;
          Map[s][t] += Min;
          s = t;
          t = Path[t];
      }
}

void SOLVE(){
      int i, j, k;
      SUM = 0;
      while( 1 ){
          Dijkstra();
          if( Path[n] == -1 )return;
          Find();
          SUM += Min;
          Change();
      }
}

void OUT(){
      printf( "%d\n", SUM );
}

int main(){
      while( IN() ){
        
          SOLVE();
          OUT();
      }
      return 0;
}

