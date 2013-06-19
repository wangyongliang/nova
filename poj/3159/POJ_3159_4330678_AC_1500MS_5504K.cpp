#include<stdio.h>
#define N 30005
#define MAX 99999999
int dist[N],heap[N],index[N];
int visit[N];
int heap_size;
int n,m;
struct edge
{
    int id;
    int len;
    struct edge *next;
};
struct node
{
        struct edge *first;
};
struct node vert[N];

int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return i*2;
}
int right(int i)
{
    return i*2+1;
}
void swap(int &a,int &b)
{
    a^=b;
    b^=a;
    a^=b;
}
void heapify(int i)
{
    int smallest;
    if(left(i)<=heap_size&&dist[heap[i]]>dist[heap[left(i)]])
    smallest=left(i);
    else
    smallest=i;
    if(right(i)<=heap_size&&dist[heap[smallest]]>dist[heap[right(i)]])
    smallest=right(i);
    if(smallest!=i)
    {
        swap(heap[smallest],heap[i]);
        swap(index[heap[smallest]],index[heap[i]]);
    }
}
int minextract()
{
    int min=heap[1];
    swap(heap[1],heap[heap_size]);
    index[heap[1]]=1;
    heap_size--;
    heapify(1);
    return min;//heap[heap_size] WA!!!!
}
void buildheap()
{
    heap_size=n;
    for(int i=heap_size/2;i>0;i--)
    {
        heapify(i);
    }
}
void increase(int i)
{
    while(i>0&&parent(i)>0)
    {
        if(dist[heap[i]]<dist[heap[parent(i)]])
        {
            swap(heap[i],heap[parent(i)]);
            swap(index[heap[i]],index[heap[parent(i)]]);
            i=parent(i);
        }    
        else
        break;
    }
}
int empty()
{
    return heap_size>0;
}
int dijkstra()
{
    int g=0;
    while(empty()!=0)
    {
        int w=minextract();
        visit[w]=1;
        if(w==n)
        {
            return dist[n];
        }
        edge *p=vert[w].first;
        while(p)
        {
            if(visit[p->id]==0)
            {
                int v=p->len;
                if(dist[p->id]>dist[w]+v)
                {
                    dist[p->id]=dist[w]+v;
                    increase(index[p->id]);
                }
            }
            p=p->next;
        }
    }
}
void solve()
{
    edge *p=vert[1].first;
    while(p)
    {
        dist[p->id]=p->len;
        p=p->next;
    }
    dist[1]=0;
    buildheap();
    printf("%d\n",dijkstra());
}
int main()
{
    edge *p;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        vert[i].first=0;
        heap[i]=i;
        visit[i]=0;
        index[i]=i;
        dist[i]=MAX;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,s;
        scanf("%d%d%d",&a,&b,&s);
        p=new edge;
        p->next=vert[a].first;
        p->id=b;
        p->len=s;
        vert[a].first=p;
    }
    solve();
    scanf("%d",&n);
    return 0;

}