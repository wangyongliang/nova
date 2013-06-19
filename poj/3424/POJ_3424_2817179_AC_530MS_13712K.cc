#include <stdio.h>
#include <map>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000023;
int x[110],y[110],n,m,d[maxn];
char ans[maxn][110];
typedef struct HNODE
{
    char s[110];
    HNODE *next;
}HNODE;
HNODE * H[maxn];
int code(char *s)
{
    int ret = 0;
    while (*s)
    {
        ret = ret * 31 + *s++;
    }
    ret %= maxn;
    if (ret<0) ret += maxn;
    return ret;
}
int Insert(char *s)
{
    int h = code(s);
    HNODE *p;
    for (p=H[h]; p; p=p->next)
    {
        if (strcmp(p->s,s) == 0)
            return 0;
    }
    p = new HNODE;
    strcpy(p->s,s);
    p->next = H[h];
    H[h] = p;
    return 1;
}
void calc(int num, int i, int j, int &xi, int &yi)
{
    switch(num)
    {
    case 1: xi = x[0]-i; yi = y[0] - j - 200;break;
    case 2: xi = x[0]-i-100; yi = y[0] - j - 200; break;
    case 3: xi = x[0]-i-200; yi = y[0] - j - 200; break;
    case 4: xi = x[0]-i; yi = y[0] - j - 100;break;
    case 5: xi = x[0]-i-100; yi=y[0]-j-100;break;
    case 6: xi = x[0]-i-200; yi=y[0]-j-100;break;
    case 7: xi = x[0]-i; yi = y[0] - j;break;
    case 8: xi = x[0]-i-100; yi = y[0] - j;break;
    case 9: xi = x[0]-i-200; yi = y[0] - j;break;
    }
}
int num[3][3]={7,4,1,8,5,2,9,6,3};
bool cmp(int a, int b){    return strcmp(ans[a],ans[b])<0; }
int main()
{
    int i,j,k,x0,y0,v,e,f,dx,dy,len = 0;
    char s[110];
    scanf("%d",&n);
    m = e = 0;;
    for (i=0; i<n; i++)        scanf("%d%d",&x[i],&y[i]);
    for (k=1; k<=9; k++)
    {
        for (i=0; i<100; i++)
        {
            for (j=0; j<100; j++)
            {
                calc(k,i,j,x0,y0);
                f = 1;
                len = 0;
                s[len++] = char('0' + k);
                for (v=1; v<n; v++)
                {
                    if (x[v]>=x0+300 || y[v] >= y0+300 || x[v]<x0 || y[v]<y0)
                    {
                        f = 0;break;
                    }
                    dx = x[v] - x0; dy = y[v] - y0;
                    dx /= 100;
                    dy /= 100;
                    s[len++] = char('0' + num[dx][dy]);                 
                }
                s[len] = '\0';
                if (f && Insert(s))
                {
                    strcpy(ans[m],s);
                    d[m] = m;
                    m++;
                }
            }
        }
    }
    sort(d,d+m,cmp);
    if (m==0)
    {
        puts("NONE");
        return 0;
    }
    for (i=0; i<m; i++)
    {
        printf("%s\n",ans[d[i]]);
    }
    return 0;
}
