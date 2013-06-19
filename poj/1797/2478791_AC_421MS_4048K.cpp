#define maxn 1001
#include<string.h>
#include<stdio.h>
long int use[maxn],f[maxn][maxn],d[maxn];
long int min(long int a,long int b)
 {long int z;
  if (a>=b) z=b;
     else z=a;
  return(z);
 }
void main()
{ long int max,k,q,i1,j1,i,j,x,y,n,m;
  scanf("%ld",&q);
  for(i1=1;i1<=q;i1++)
   {scanf("%ld %ld",&n,&m);
    memset(f,0,sizeof(f));
    for (j1=1;j1<=m;j1++)
     {scanf("%ld %ld",&x,&y);
      scanf("%ld",&f[x][y]);
      f[y][x]=f[x][y];}
    memset(d,0,sizeof(d));memset(use,0,sizeof(use));
    for (i=1;i<=n;i++) d[i]=f[1][i];use[1]=1;
    for (k=1;k<=n-1;k++)
     {max=0;
      for (i=1;i<=n;i++)
	if (use[i]==0&&d[i]>max) {j=i;max=d[i];}
      use[j]=1;
      for (i=1;i<=n;i++)
	if ((use[i]==0)&&(min(d[j],f[j][i])>d[i])) d[i]=min(d[j],f[j][i]);
     }
    printf("Scenario #%ld:\n",i1);
    printf("%ld\n",d[n]);
    printf("\n");
   }
}