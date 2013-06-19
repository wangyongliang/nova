#include <cstdio>
#include <cstring>
const int M=16;
const int INF=0x7fffffff;
int sum[8],a[8][M],res,n;
void DFS(int dep){
	if(dep==n){
		int mn=-INF;
		for(int i=0;i<n;i++) if(sum[i]>mn) mn=sum[i];
		if(res>mn) res=mn;
	}else{
		int j,k,v;
		bool flag;
		for(j=0;j<n;j++){
			flag=false;
			for(k=0;k<n;k++){
				sum[k]+=a[dep][j+k];
				if(sum[k]>res){
					for(v=0;v<=k;v++) sum[v]-=a[dep][j+v];
					flag=true;
					break;
				}
			}
			if(!flag){
				DFS(dep+1);
				for(k=0;k<n;k++) sum[k]-=a[dep][j+k];
			}
		}
	}
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF&&n!=-1){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) scanf("%d",&a[i][j]);
			memcpy(a[i]+n,a[i],sizeof(int)*n);
		}
		res=INF;
		memset(sum,0,sizeof(sum));
		for(i=0;i<n;sum[i]+=a[0][i],i++);
		DFS(1);
		printf("%d\n",res);
	}
	return 0;
}
