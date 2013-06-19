#include<iostream>
using namespace std;
int n,sum=0;
int a[1000],b[1000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n && a[i]!=b[j]) j++;
        sum+=j-i;
        while(j>i){
              b[j]=b[j-1]; 
              j--;
        }       
    }
    printf("%d\n",sum);
    system("pause");
    return 0;
}
