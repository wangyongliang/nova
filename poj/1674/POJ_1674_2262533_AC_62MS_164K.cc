#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main()
{
    int N;
    scanf("%d",&N);
    while(N--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            while(arr[i]!=i){
                swap(arr[i],arr[arr[i]]);
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}

