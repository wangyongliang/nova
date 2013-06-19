#define maxn 50002
#include<stdio.h>
#include<string.h>
long int  n,m,father[maxn],rank[maxn];
long int find(long int a)
 {long int r,q;
  r=a;
  while (r!=father[r]) r=father[r];
  while (a!=r) {q=father[a];father[a]=r;a=q;}
  return(r);
 }
void main()
{ long int num=0,x1,y1,i,x,y,sum;
  scanf("%ld %ld",&n,&m);
  while (n!=0)
   {
    sum=n;num+=1;
    memset(father,0,sizeof(father));memset(rank,0,sizeof(rank));
    for (i=1;i<=n;i++) rank[i]=1;
    for (i=1;i<=n;i++) father[i]=i;
    for (i=1;i<=m;i++)
     {
       scanf("%ld %ld",&x,&y);
       if (x!=y)
	   {
	    x1=find(x);y1=find(y);
	    if (x1!=y1)
			{ if (rank[x1]>rank[y1]) {father[y1]=x1;rank[x1]+=rank[y1];}
			 else {father[x1]=y1;rank[y1]+=rank[x1];}
		    sum=sum-1;;
	       }
       }
     }
    printf("Case %ld: %ld\n",num,sum);
    scanf("%ld %ld",&n,&m);
   }
}

