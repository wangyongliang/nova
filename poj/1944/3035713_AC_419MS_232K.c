
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//pku 3293

#include<stdio.h>
int i,j,w,n,k,sum,Min,t1,t2;
int p[10100],q[10100],g[1010];
/*
void Change(int t1,int t2){
	int k=p[t1];p[t1]=p[t2];p[t2]=k;
	    k=q[t1];q[t1]=q[t2];q[t2]=k;
}
void Qsort(int p1,int p2){
	if (p1>=p2) return;
	int i=p1,j=p2;
	do{
	  while(i<j&&p[i]<=p[j]) i++;
	  Change(i,j);
	  while(i<j&&p[i]<=p[j]) j--;
	  Change(i,j);
	}while(i<j);
	Qsort(p1,i-1);
	Qsort(i+1,p2);
} */
int main()
{
	scanf("%d%d",&n,&k);
	for (j=1;j<=n;j++) g[j]=j;
	for (i=1;i<=k;i++) {
		scanf("%d%d",&p[i],&q[i]);
		if (p[i]>q[i]){w=p[i];p[i]=q[i];q[i]=w;};
		if (q[i]>g[p[i]]) g[p[i]]=q[i];
	}
	Min=n-1;
	for (i=1;i<=n;i++){
	  sum=0;t1=1;t2=1;
	  for (j=1;j<=n;j++){
		if (j>t2){sum+=t2-t1;t1=j;t2=g[j];};
        if (g[j]>t2) t2=g[j];
	  }
	  sum+=t2-t1;
	  if (sum<Min) Min=sum;
	  for (j=1;j<=n;j++) g[j]=j;
	  for (j=1;j<=k;j++){
		p[j]=p[j]%n+1;q[j]=q[j]%n+1;
		if (p[j]>q[j]) {w=p[j];p[j]=q[j];q[j]=w;};
		if (q[j]>g[p[j]]) g[p[j]]=q[j];
	  }	
	}
	printf("%d\n",Min);
	return 0;
}