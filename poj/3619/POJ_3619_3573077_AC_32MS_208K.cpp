#include <cstdio>

int ans, n, r, s, t;

int main() {
    int ct;
    scanf ("%d%d", &n, &ct);
    while (ct--) {
        scanf ("%d%d%d", &r, &s, &t);
        ans = (s+t)*(n/(r*s));
        if( n%(r*s)==0 && n!=0) ans -= t;
        ans += ((n%(r*s))+r-1)/r;
        printf("%d\n",ans);
    }
    return 0;
}


