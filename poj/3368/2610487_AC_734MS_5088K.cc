#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct
{ int v,b,e; }seg;

int n, q;
seg arr[100000];
int id[100000];
int ap;

int tree[1000000];

#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
inline void insert (int v, int at, int iv, int ib, int ie)
{
    if (v>tree[iv]) tree[iv]=v;
    if (ib==ie) return ;
    
    int mid=(ib+ie)/2;
    if (at>mid) insert (v, at, R(iv), mid+1, ie);
    else insert (v, at, L(iv), ib, mid);
}    

inline int query (int b, int e, int iv, int ib, int ie)
{
//    printf ("QUERY: %d, %d\n", b, e);
//    system ("PAUSE");
    
    if (b==ib&&e==ie) return tree[iv];
    
    int mid = (ib+ie)/2;
    if (b>mid)
    {
        return query( b, e, R(iv), mid+1, ie);
    }    
    else
    {
        if (e<=mid) return query (b, e, L(iv), ib, mid);
        else 
        {
            int a = query (b, mid, L(iv), ib, mid);
            int b = query (mid+1, e, R(iv), mid+1, ie);
            return max(a,b);
        }    
    }    
}    

void perform()
{
    memset (tree, 0, sizeof(tree));
    
    ap = 0;
    scanf ("%d", &q);
    
    int a;
    scanf ("%d", &a);
    arr[0].v=a; arr[0].b=0; ap=1;
    for (int i=1; i<n; i++)
    {
        scanf ("%d", &a);
        if (arr[ap-1].v!=a) 
        {
            arr[ap-1].e=i-1;
            for (int j=arr[ap-1].b; j<=arr[ap-1].e; j++)
            { id[j] = ap-1; }
                
            arr[ap].v=a;
            arr[ap].b=i;
            ap++;
        }    
    }    
    arr[ap-1].e=n-1;
    for (int j=arr[ap-1].b; j<=arr[ap-1].e; j++)
    { id[j] = ap-1; }
    
    for (int i=0; i<ap; i++)
    {
        insert (arr[i].e-arr[i].b+1, i, 0, 0, ap);
    }
            
    for (int i=0; i<q; i++)
    {
        int b, e, ans;
        scanf ("%d%d", &b, &e);
        b--; e--;
        
        if (id[b]+1<=id[e]-1)
        {
            ans = query (id[b]+1,id[e]-1, 0, 0, ap);
        }    
        else ans = 0;
        
        if (id[b]!=id[e])
        {
            if ( arr[id[b]].e-b+1>ans ) ans = arr[id[b]].e-b+1;
            if ( e-arr[id[e]].b+1>ans ) ans = e-arr[id[e]].b+1;
        }
        else 
        {
            if (e-b+1>ans) ans=e-b+1;
        }        
        
        printf ("%d\n", ans);
    }    
    
    return ;
}    

int main(int argc, char *argv[])
{
    while ( scanf ("%d", &n)!=EOF && n!=0 )
        perform();	
    return 0;
}
