#include <stdio.h>
#include <memory.h>

inline int readd(int k)
{
    int d;
    scanf("%d",&d);
    if (d < 0)
    {
        d = k - (-d) % k;
        if (d == k)
            d = 0;
        return d;
    }
    return d % k;
}

inline void swap(char **p1, char **p2)
{
    char *t = *p1;
    *p1 = *p2;
    *p2 = t;
}

int main()
{
    int n, k, j, d, c, t;
    char a[200], *p1, *p2;
    while(scanf("%d%d", &n, &k) == 2)
    {
        p1 = a;
        p2 = a + k;
        memset(p1, 0, k);
        d = readd(k);
        p1[d] = 1;
        c = 0;
        while(--n)
        {
            d = readd(k);
            if (c || d == 0)
                continue;
            memset(p2, 0, k);
            for(c = 0, j = 0; j < k; j++)
            {
                if (p1[j]) // 这里改用加减运算，不用取模。
                {
                    c++;
                    t=j+d;
                    if (t>=k)t-=k;
                    p2[t] = 1;
                    t=j + k - d;
                    if (t>=k)t-=k;
                    p2[t] = 1;
                }
            }
            if (c != k)
            {
                c = 0;
                swap(&p1, &p2);
            }
        }
        printf("%sivisible\n", (*p1||c == k)?"D":"Not d");
    }
    return 0;
}
