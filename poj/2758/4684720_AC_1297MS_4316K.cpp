/*
 *  pku2758
 *  suffix array rmq etc..
 */

#include <stdio.h>
#include <string.h>
#define Min(x,y) ((x)<(y)?(x):(y))
#define maxn 51000
#define INF  0x7FFFFFFF

char s[maxn];
int count[maxn],lcp[17][maxn],smem[3][maxn];
int *SA,*nSA,*Rank,*nRank;
int Ip[300];
char Ic[300];
int Itop,L;

void init(){
    scanf("%s",s);
    L=strlen(s);
    s[L++]=1; s[L]=0;
    Ip[0]=INF; Ic[0]=1; Itop=1;
}

void suffix_array(){
    int i,j,k;
    SA=smem[0]; nSA=smem[1]; Rank=smem[2];
    memset(count,0,sizeof(int)*200);
    for (i=0;i<L;i++) count[s[i]]++;
    for (i=1;i<200;i++) count[i]+=count[i-1];
    for (i=0;i<L;i++) SA[--count[s[i]]]=i;
    for (Rank[SA[0]]=0,i=1;i<L;i++){
        Rank[SA[i]]=Rank[SA[i-1]];
        if (s[SA[i]]!=s[SA[i-1]]) Rank[SA[i]]++;
    }
    for (k=1;k<L&&Rank[SA[L-1]]<L-1;k*=2){
        for (i=0;i<L;i++) count[Rank[SA[i]]]=i+1;
        for (i=L-1;i>=0;i--) if (SA[i]>=k)
            nSA[--count[Rank[SA[i]-k]]]=SA[i]-k;
        for (i=L-k;i<L;i++) nSA[--count[Rank[i]]]=i;
        nRank=SA; SA=nSA;
        for (nRank[SA[0]]=0,i=1;i<L;i++)
        {
            nRank[SA[i]]=nRank[SA[i-1]];
            if (Rank[SA[i]]!=Rank[SA[i-1]]
                    ||Rank[SA[i]+k]!=Rank[SA[i-1]+k])
                nRank[SA[i]]++;
        }
        nSA=Rank; Rank=nRank;
    }
}

void get_lcp_rmq(){
    int i,j,k;
    for (i=0,k=0;i<L;i++){
        if (Rank[i]==L-1) lcp[0][Rank[i]]=k=0;
        else
        {
            if (k>0) k--;
            j=SA[Rank[i]+1];
            for (;s[i+k]==s[j+k];k++);
            lcp[0][Rank[i]]=k;
        }
    }
    for (i=0,k=1;k<L;i++,k*=2)
    {
        for (j=0;j+k<L;j++)
        {
            lcp[i+1][j]=Min(lcp[i][j],lcp[i][j+k]);
        }
    }
}

int rmq(int a,int b){
    int i,k,t;
    a=Rank[a]; b=Rank[b];
    if (a>b) t=a,a=b,b=t;
    t=b-a;
    for (k=1,i=0;k*2<t;i++,k*=2);
    return Min(lcp[i][a],lcp[i][b-k]);
}

int _Q(int a,int b){
    int na,nb;
    int lr,la,lb,ia,ib,l,res;
    na=a; nb=b; res=0;
    for (ia=0;Ip[ia]<=a;ia++);
    for (ib=0;Ip[ib]<=b;ib++);
    if (a==b) return L-a+Itop-ia-2;
    for (;;)
    {
        lr=rmq(na,nb);
        la=Ip[ia]-na;
        lb=Ip[ib]-nb;
        l=Min(lr,Min(la,lb));
        res+=l; na+=l; nb+=l;
        if (l==la||l==lb)
        {
            while (Ip[ia]==na&&Ip[ib]==nb)
            {
                if (Ic[ia]==Ic[ib]) ia++, ib++, res++;
                else return res;
            }
            while (Ip[ia]==na)
            {
                if (Ic[ia]==s[nb]) ia++, nb++, res++;
                else return res;
            }
            while (Ip[ib]==nb)
            {
                if (s[na]==Ic[ib]) na++, ib++, res++;
                else return res;
            }
        }
        else return res;
    }
    return res;
}

void _I(char c,int a){
    int i,j;
    for (i=0;i<Itop;i++)
    {
        if (Ip[i]<a) a--;
        else break;
    }
    if (a>=L) a=L-1;
    for (j=Itop;j>i;j--)
        Ip[j]=Ip[j-1], Ic[j]=Ic[j-1];
    Ip[i]=a; Ic[i]=c; Itop++;
}

void solve(){
    int cas,i,j;
    char str[3];
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%s",str);
        if (str[0]=='Q')
        {
            scanf("%d%d",&i,&j);
            printf("%d\n",_Q(i-1,j-1));
        }
        else
        {
            scanf("%s%d",str,&j);
            _I(str[0],j-1);
        }
    }
}

int main(){
    init();
    suffix_array();
    get_lcp_rmq();
    solve();
    return 0;
}