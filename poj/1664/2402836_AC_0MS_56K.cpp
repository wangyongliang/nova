#include <stdio.h>
#include <iostream.h>
#include <malloc.h>
int f(int x,int y){
	if(x<y)
		y=x;
	if(x==0)
		return 1;
	if(y==1)
		return 1;
	return f(x,y-1)+f(x-y,y);
}
void main(){
	int t,i,x,y;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>x>>y;
		cout<<f(x,y)<<endl;
	}
}
