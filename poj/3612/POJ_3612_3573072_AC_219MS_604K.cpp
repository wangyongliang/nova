#include <cstdio>

#define maxn 110000
#define maxh 101

int h[maxn], bes[2][maxh], ans, bes1, c, n;
int min(int x,int y){return x>y?y:x;};
inline int sqr (int x){return x*x; }

int main (){
    int i, j, pre, cur;
    int inf = 2100000000;
    scanf ("%d%d", &n, &c);
    for (i = 0; i<n; i++)    scanf ("%d", &h[i]);
    for (i = 0; i<maxh; i++)
	{
		if(i>=h[0]) bes[0][i]=sqr(h[0]-i);
		else bes[0][i]=inf;
	}
    for (i = 1; i<n; i++){
        pre = (i+1)%2;
        cur = i%2;
        for (bes1 = inf, j = 0; j<maxh; j++){
            bes1 = min(bes1,bes[pre][j]-j*c);
            bes[cur][j] = bes1+j*c;
        }
        for (bes1 = inf, j = maxh-1; j>= 0; j--){
            bes1 =min(bes1, bes[pre][j]+j*c);
            bes[cur][j] =min(bes[cur][j], bes1-j*c);
        }
        for (j = 0; j<maxh; j++)
		{
			if(j>=h[i]) bes[cur][j]=bes[cur][j] + sqr(j-h[i]);
			else bes[cur][j]=inf;
		}
    }
    ans = inf;
    for (i = 0; i<maxh; i++) ans =min(ans,bes[cur][i]);
    printf ("%d\n", ans);
    return 0;
}


