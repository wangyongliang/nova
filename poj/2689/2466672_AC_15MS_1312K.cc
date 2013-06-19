#include <iostream> 

#include <string>

using namespace std;

typedef long long elem;

elem plist[4800],pcnt;

 

void getprime()

{ 

       plist[0] = 2, plist[1] = 3, pcnt = 2;

       for (long n=5,i; n<=47000; n+=2) {

              for (i=1; plist[i]*plist[i]<=n && n%plist[i]; i++);

              if (plist[i]*plist[i] > n) plist[pcnt++] = n;

       }

}

 

bool flag[1000010];

void sieve (elem L, elem U)

{

       elem c[2],d[2],first;

       if (L == 1) L++;

       memset(flag, 1, sizeof(flag[0])*(U-L+1));

       for (elem i=0,j; plist[i]*plist[i]<=U; i++) {

              j = L/plist[i]+(L%plist[i]>0);

              if (j == 1) j++; 

              for (j*=plist[i]; j<=U; j+=plist[i]) flag[j-L] = 0;

       } 

       c[0] = c[1] = d[0] = d[1] = 0;

       first = 0;

       for (elem i=L; i<=U; i++) {

              if (flag[i-L]) {

                     if (first) {

                            if (!c[0] || c[0] && i-first<c[1]-c[0])

                                   c[0] = first, c[1] = i;

                            if (!d[0] || d[0] && i-first>d[1]-d[0])

                                   d[0] = first, d[1] = i;

                     }

                     first = i;

              }

       }

       if (c[0]) cout << c[0] << "," << c[1] << " are closest, " << d[0] << "," << d[1] << " are most distant." << endl;

       else cout << "There are no adjacent primes." << endl;

}

 

int main()

{

       elem L,U;

       getprime();

       

       while (cin >> L >> U) 

              sieve (L,U);

       return 0;

}