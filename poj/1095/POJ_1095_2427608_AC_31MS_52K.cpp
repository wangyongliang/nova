
#include <iostream.h>

void makeTree(int n){
	int i, j, sum, m;
	int a[19] = {0, 1, 3, 8, 22, 64, 196, 625, 2055, 6917, 23713, 82499, 290511, 1033411,
		   3707851, 13402696, 48760366, 178405156, 656043856};
	if(n == 0);
	else if(n == 1){ cout << 'X';}
	else if(n == 2){ cout << "X(X)";}
	else if(n == 3){ cout << "(X)X";}
	else if(n == 4){ cout << "X(X(X))";}
	else if(n == 5){ cout << "X((X)X)";}
	else if(n == 6){ cout << "(X)X(X)";}
	else if(n == 7){ cout << "(X(X))X";}
	else if(n == 8){ cout << "((X)X)X";}
	else{
		for(i=2; i<19; ++i){
			if(a[i] <n && a[i+1]>=n) m= i+1;
		}
		if(n <=(2*a[m-1]-a[m-2])){
			cout<<"X(";
			makeTree(n-a[m-1]+a[m-2]);
			cout<<')';
		}else if((n>a[m]+a[m-2]-a[m-1]) && n<=a[m]){
			cout<<'(';
			makeTree(a[m-1]-a[m]+n);
			cout <<")X";
		}else{
			sum =2*a[m-1] - a[m-2];
			for(i=1; i<m; ++i){
				if(n>sum+(a[i]-a[i-1])*(a[m-i-1]-a[m-i-2])){
					sum +=(a[i]-a[i-1])*(a[m-i-1]-a[m-i-2]);
				}else break;
			}
			j=1;
			while((sum+j*(a[m-i-1]-a[m-i-2]))<n) j++;
			cout<<'(';
			makeTree(j+a[i-1]);
			cout << ")X(";
			makeTree(n-sum-(j-1)*(a[m-i-1]-a[m-i-2])+a[m-i-2]);
			cout <<")";
		}
	}
}

int main(void){
	int n;
	cin >> n;
	while(n != 0){
		makeTree(n);
		cout << endl;
		cin >> n;
	}
	return 0;
}
