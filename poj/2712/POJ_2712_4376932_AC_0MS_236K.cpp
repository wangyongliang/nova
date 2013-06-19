#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define ABS(x) (x)>0?(x):-(x)
#define SP(x) setprecision(x)
using namespace std;

bool digit[300],aph[300],pau[300];
void init(){
    int i;
    for(i=0;i<300;i++) digit[i]=aph[i]=pau[i]=0;
    for(i='a';i<='z';i++) aph[i]=1;
    for(i='A';i<='Z';i++) aph[i]=1;
    for(i='0';i<='9';i++) digit[i]=1;
    for(i=0;i<300;i++) 
    {
        if(digit[i]==0&&aph[i]==0)pau[i]=1;
    }
    pau[' ']=0;
}
int check(char s[]){
    int i,j;
    if((s[1]==' '||s[1]==0)&&(s[0]!='a'&&s[0]!='A'&&s[0]!='I'&&s[0]!=' ')) return 0;
    for(i=1;s[i];i++){
        if(s[i]>='A'&&s[i]<='Z'){
            if(s[i-1]>='A'&&s[i-1]<='Z') return 0;
        }
        if(digit[s[i]]&&aph[s[i-1]]) return 0;
        if(aph[s[i]]&&digit[s[i-1]]) return 0;
        if(aph[s[i]]||digit[s[i]]||pau[s[i]]){
            if(s[i-1]==' '&&(s[i+1]==' '||s[i+1]==0)){
                if(s[i]!='a'&&s[i]!='A'&&s[i]!='I') return 0;
            }
        }
        if(pau[s[i]]&&pau[s[i-1]]){
            if(s[i]!='"'&&s[i-1]!='"') return 0;
        }
    }
    return 1;
}
char s[1000];
int  main()
{
    init();
    while(gets(s)){
        if(strlen(s)==1&&s[0]=='#') break;
        else {
            if(check(s)) printf("OK\n");
            else printf("suspicious\n");
        }
    }
    system("pause");
    return 0;
}

