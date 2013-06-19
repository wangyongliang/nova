#include <stdio.h>

#include <stdlib.h>

#include <algorithm>

#include <string.h>

#include <vector>

using namespace std;

 

vector <int> tree[100100];

int nodetag[100005];

int s[100100], e[100100];

int c[100100];

int t, N;

 

int lowbit(int n)

{

    return n & (-n);

}

 

void update(int n, int num)

{

    while(n <= N){

        c[n] += num;

        n += lowbit(n);

    }

}

 

int sum(int n)

{

    int SUM = 0;

    while(n >= 1){

        SUM += c[n];

        n -= lowbit(n); 

    }

    return SUM;

}

 

void dfs(int now, int father)

{

    int i;

    s[now] = t;   //前序遍历序号 

    for(i = 0;i < tree[now].size();i++){

        if(tree[now][i] != father){

            t++;

            dfs(tree[now][i], now);

        }   

    }

    e[now] = t;   //后序遍历序号 

}

 

int main()

{

    int i, m, n, a, b, num;

    char chr;

    while(scanf("%d", &N) != EOF){

        for(i = 1;i <= N - 1;i++){

            scanf("%d%d", &a, &b);

            tree[a].push_back(b);

            tree[b].push_back(a);        

        }

        t = 1;

        dfs(1, 0);

        memset(c, 0, sizeof(c));

        for(i = 1;i <= N;i++){

            update(i, 1);

            nodetag[i] = 1;   

        }

        scanf("%d", &m);

        for(i = 1;i <= m;i++){            

            getchar();

            scanf("%c%d", &chr, &n);            

            if(chr == 'C'){

                if(nodetag[n] == 1){  

                    nodetag[n] = 0;   

                    update(s[n], -1);

                  

                }

                else { 

                    nodetag[n] = 1;                   

                    update(s[n], 1);   

                }

            }

            else printf("%d\n", sum(e[n]) - sum(s[n] - 1));

        }

    }

    return 0;

} 