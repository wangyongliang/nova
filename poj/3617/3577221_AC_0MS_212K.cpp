#include<cstdio>

char S[2010],ln=0;

void prnt(char a) {
	if(ln==80) {printf("\n");ln=0;}
	printf("%c",a);ln++;
}

int main() {
	int i,j,N,pi,pj,val;
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf(" %c ",S+i);
	i=0,j=N-1;
	while(i<=j) {
		if(S[i]<S[j])		{prnt(S[i]);i++;}
		else if(S[i]>S[j])	{prnt(S[j]);j--;}
		else {
			pi=i+1;pj=j-1;val=S[i];
			while( pj-pi>1 && S[pi]==S[pj]) {pi++,pj--;}
			if(S[pi]<S[pj]) prnt(S[i]),i++;
			else prnt(S[j]),j--;
		}
	}
	printf("\n");
	return 0;
}
