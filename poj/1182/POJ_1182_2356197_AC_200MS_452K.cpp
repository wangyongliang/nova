#include <stdio.h>
#define maxn 50004

int  parent[maxn];
int    relation[maxn];   
 int result[][3]={1 , -1 , 0, 0 , 1 , -1 , -1 , 0 , 1};
 int result2[][3]={0 , 1 , -1 , -1 , 0 , 1 , 1 , -1 , 0};
 int next[][3]={1 , -1 , 0 , -1 , 0 , 1 , 0 , 1 , -1};
 int behind[][3]={0 , -1 , 1 , 1 , 0 , -1 , -1 , 1 , 0};

 void find(int x,int &y,int &d)
 {
    int z,r,now;
	d=0;z=x;
	 while (parent[x] > 0)
	 { d = next[d+1][relation[x]+1];
        x = parent[x];
     }
	 y = x; now = d;

	  while (z !=y )
	 { 
		  x = parent[z];
        parent[z] = y;
        r = relation[z];
        relation[z] = now;
        now = behind[now+1][r+1];
        z = x;
     } 
 }

 void merge(int a,int b,int r)
 {
   if(parent[a]>parent[b])
     {
	    parent[b] = parent[a] + parent[b];
        parent[a] = b;
        relation[a] = r;
     }
   else {
          parent[a] = parent[a] + parent[b];
        parent[b] = a;
        relation[b] = -r;
        }
 
 }

int main()
{
	 int n , k , lie , i ;    
     int x , y , a , b   ;  
     int u , v , d , nr  ;
	scanf("%d%d",&n,&k);

	for(i=1;i<=n;i++)
	{
	   parent[i] = -1;
      relation[i] = 0;
	}

	lie=0;
	for(i=1;i<=k;i++)
	{
	  scanf("%d%d%d",&d,&x,&y);
	  if(x>n||y>n)
		{
	      lie+=1;
		  continue;
	    }
       find(x , a , u);
       find(y , b , v);
	   if(d==2)  nr = result[u+1][v+1];
	   else  nr = result2[u+1][v+1];
          if(a==b)
		{
		  if(nr!=0) 
			  lie+=1;
		}

		else   merge(a , b , nr);
 
	}

	  printf("%d\n",lie);	
	return 0;
}
