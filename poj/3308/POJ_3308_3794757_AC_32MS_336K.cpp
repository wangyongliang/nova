#include<stdio.h>        
#include<memory.h>
#include <math.h>
#define SIZE 110

double con[SIZE][SIZE];
int s,t,queue[SIZE],head,tail,pre[SIZE],visit[SIZE],n;

bool findroad()
{
	int i,k;
	memset(visit,0,sizeof(visit));
	head = tail = 0;
	queue[tail++] = s;
	pre[s] = -1;
	while(tail > head){
		k = queue[head++];
		for(i = 0; i < n; i++)
			if(!visit[i] && con[k][i] > 0){
				pre[i] = k;
				visit[i] = 1;
				if(i == t)
					return true;
				queue[tail++] = i;
			}
	}
	return false;
}

double Maxflow()
{
	int j;
	double maxflow = 0;;
	while(findroad()){
		double min = 1e10;
		for(j = t; j != s; j = pre[j])
			if(min > con[pre[j]][j])
				min = con[pre[j]][j];
			maxflow += min;
			for(j = t; j != s; j = pre[j]){
				con[pre[j]][j] -= min;         
				con[j][pre[j]] += min;
			}
	}
	return maxflow;
}
int main()
{
	int m,nn,l,i,T,a,b;
	double w;
	scanf("%d",&T);
	s = 0;
	while(T--){
		scanf("%d%d%d",&m,&nn,&l);
		t = m+nn+1;
		memset(con,0,sizeof(con));
		for(i = 1; i <= m; i++){
			scanf("%lf",&w);
			con[s][i] = log(w);
		}
		for(i = m+1; i <= m+nn; i++){
			scanf("%lf",&w);
			con[i][t] = log(w);
		}
		for(i = 0; i < l; i++){
			scanf("%d%d",&a,&b);
			con[a][b+m] = 1e10;
		}
		n = m+nn+2;
		printf("%.4lf\n",exp(Maxflow()));
	}
	return 0;
}



