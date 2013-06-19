#include<stdio.h>
#include<vector>
using namespace std;
struct node
{
    int x,y,z;
}heap[2000000];
int fun(int i,int j)
{
    return heap[i].z>heap[j].z;
}
int m;
int ID[1010][110];
void shiftdown(int l)
{
    int i,j;
    i=l;
    j=2*i;
    heap[0]=heap[i];
    while(j<m)
    {
        if(j<m&&fun(j,j+1)) j++;
        if(fun(0,j))
        {
            heap[i]=heap[j];
            ID[heap[i].x][heap[i].y]=i;
            i=j;
            j=2*i;
        }
        else 
        {
            heap[i]=heap[0];
            ID[heap[i].x][heap[i].y]=i;
            return ;
        }
    }
    heap[i]=heap[0];
    ID[heap[i].x][heap[i].y]=i;
}
void shiftup(int l)
{
    int i,j;
    heap[0]=heap[l];
    i=l;
    j=i/2;
    while(j>=1)
    {
        if(fun(j,0))
        {
            heap[i]=heap[j];
            ID[heap[i].x][heap[i].y]=i;
            i=j;
            j=i/2;
        }
        else
        {
            heap[i]=heap[0];
            ID[heap[i].x][heap[i].y]=i;
            return ;
        }
    }
    heap[i]=heap[0];
    ID[heap[i].x][heap[i].y]=i;
}

#define maxn 11000
int c,p[maxn];
struct road
{
    int x,y;
};
vector<road> a[maxn];
int b[1010][110],n;
#define inf 0xffffff
int dij(int s,int e)
{
    int i,j,k;
    node tp;
    m=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<110;j++)
        {
            b[i][j]=inf;
            ID[i][j]=m;
            heap[m].x=i;
            heap[m].y=j;
            heap[m].z=inf;
            m++;
        }
    }
    for(i=0;i<=c;i++)
    {
        b[s][i]=i*p[s];
        j=ID[s][i];
        heap[j].z=b[s][i];
        shiftup(ID[s][i]);
    }
    int x,y,l,z,v;
    while(1)
    {
        tp=heap[1];
        if(tp.x==e) return tp.z;
        if(tp.z==inf) return -1;
        heap[1].z=inf;
        shiftdown(1);
        x=tp.x;
        y=tp.y;
        z=tp.z;
        if(b[x][y]==tp.z)
        {
            if(y+1<=c&&z+p[x]<b[x][y+1])
            {
                k=ID[x][y+1];
                heap[k].z=z+p[x];
                b[x][y+1]=z+p[x];
                shiftup(k);
            }
            for(i=0;i<a[x].size();i++)
            {
                y=a[x][i].x;
                l=a[x][i].y;
                for(j=tp.y;j<=tp.y;j++)
                {
                    if(j>=l)
                    {
                        v=(j-tp.y)*p[tp.x]+tp.z;
                        if(v<b[y][j-l])
                        {
                            b[y][j-l]=v;
                            k=ID[y][j-l];
                            heap[k].z=v;
                            shiftup(k);
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int mm,i,j,q;
    road tp;
    scanf("%d%d",&n,&mm);
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            a[i].clear();
        }
        while(mm--)
        {
            scanf("%d%d%d",&i,&j,&tp.y);
            tp.x=i;
            a[j].push_back(tp);
            tp.x=j;
            a[i].push_back(tp);
        }
        scanf("%d",&mm);
        while(mm--)
        {
            scanf("%d%d%d",&c,&j,&i);
            q=dij(j,i);
            if(q==-1) printf("impossible\n");
            else printf("%d\n",q);
        }
    }
    return 0;
}