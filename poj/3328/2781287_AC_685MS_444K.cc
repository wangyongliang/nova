#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct
{
    int h;
    int w;
}point;

typedef struct
{
    point foot;
    int time;
    char next_move;
}statu;

int w, h;

char map[65][35];
int rhash[65][35];
int lhash[65][35];

int lw[] = { -1,-1,-2,-1,-2,-3,-1,-2,-1 };    // move left foot
int lh[] = { 2, 1, 1, 0, 0, 0, -1, -1, -2};

int rw[] = { 1, 1, 2, 1, 2, 3, 1, 2, 1 };    // move right foot
int rh[] = { 2, 1, 1, 0, 0, 0, -1, -1, -2};

statu arr[2][10000];
int ap[2];

#define INPUT(c) (c=='T'||c=='S'||c=='X'||(c>='1'&&c<='9'))
void read_init()
{
    memset(rhash, -1, sizeof(rhash));
    memset(lhash, -1, sizeof(lhash));
    ap[0]=ap[1]=0;
    
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            char c=getchar();
            while (!INPUT(c))
                c=getchar();
            map[i][j] = c;
        }
    }
        
    for (int i=0; i<w; i++) 
        if (map[h-1][i]=='S')
        {
            rhash[h-1][i] = 0;
            arr[0][ap[0]].foot.h = h-1;
            arr[0][ap[0]].foot.w = i;
            arr[0][ap[0]].next_move = 'l';
            arr[0][ap[0]++].time = 0;
                
            lhash[h-1][i] = 0;
            arr[0][ap[0]].foot.h = h-1;
            arr[0][ap[0]].foot.w = i;
            arr[0][ap[0]].next_move = 'r';
            arr[0][ap[0]++].time = 0;
        }
}

#define VALID(x) (x.w>=0&&x.w<w&&x.h>=0&&x.h<h&&map[x.h][x.w]!='X')
#define RHASH(r) (rhash[r.h][r.w])
#define LHASH(l) (lhash[l.h][l.w])
#define T(x) (map[x.h][x.w]=='T')
#define TIME(x) ((map[x.h][x.w]=='S'||map[x.h][x.w]=='T')?0:map[x.h][x.w]-'0')

void perform()
{
    read_init();
    
    int st; // step
    int ans = -1;
    
    for (st=1; ; st++)
    {
        int nt = st%2;
        int th = 1-nt;
        ap[nt] = 0;
        if (ap[th]==0) break;
        for (int i=0; i<ap[th]; i++)
        {
            if (arr[th][i].next_move=='l')
            {
                // move l foot 
                point rr = arr[th][i].foot;
                for (int d=0; d<9; d++)
                {
                    point nl = rr;
                    nl.w += lw[d];
                    nl.h += lh[d];
                    int tt = arr[th][i].time;
                    
                    if (VALID(nl))
                    {
                        tt += TIME(nl);
                        if ( T(nl) ) 
                        {
                            if (ans==-1||ans>tt)
                            {
                                ans=tt; 
                                //printf ("##R l: %d %d r: %d %d\n", nl.h, nl.w, rr.h, rr.w);
                            }
                        }
                        if ( -1==LHASH(nl)  
                        ||   tt<LHASH(nl) )
                        {
                            LHASH(nl) = tt;
                            
                            // expand
                            arr[nt][ap[nt]].foot = nl;
                            arr[nt][ap[nt]].next_move = 'r';
                            arr[nt][ap[nt]++].time = tt;
                        }
                    }
                    
                }
            }
            else // move r foot   
            {
                point ll = arr[th][i].foot;
                for (int d=0; d<9; d++)
                {
                    point nr = ll;
                    nr.w += rw[d];
                    nr.h += rh[d];
                    int tt = arr[th][i].time;
                    
                    if (VALID(nr))
                    {
                        tt += TIME(nr);
                        if ( T(nr) ) 
                        {
                            if (ans==-1||ans>tt) 
                            { 
                                ans=tt; 
                                //printf ("##L l: %d %d r: %d %d\n", ll.h, ll.w, nr.h, nr.w);
                            }
                        }
                        if ( -1==RHASH(nr)  
                        ||   tt<RHASH(nr) )
                        {
                            RHASH(nr) = tt;
                            
                            // expand
                            arr[nt][ap[nt]].foot = nr;
                            arr[nt][ap[nt]].next_move = 'l';
                            arr[nt][ap[nt]++].time = tt;
                        }
                    }
                }
                
            }
            
        }
        
    }

    printf ("%d\n", ans);
    return ;
}

int main(int argc, char *argv[])
{
    while (EOF!=scanf ("%d%d", &w, &h)&&!(w==0&&h==0))
        perform();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
