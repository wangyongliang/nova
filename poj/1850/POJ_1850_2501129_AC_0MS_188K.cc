#include<stdio.h>
#include<string.h>
__int64 a[27][27];
__int64 com(int x,int y){
	if(a[x][y]) return a[x][y];
	else{
		__int64 sum=1,i,j;
		for(i=0,j=1; i<y; i++){	sum*=(x-i);	for(;j<=y&&sum%j==0;j++) sum/=j; }
	    a[x][y]=sum;
		return sum;
	}
}
int main(){
	char s[13];
	__int64 n, i,j;
	while(scanf("%s",s)!=EOF){
		for(i=0;s[i+1];i++) if(s[i]>=s[i+1]) break;
		if(s[i+1]) printf("0\n");
		else{
			i=strlen(s);
			for(--i,n=0; i; i--)  n+=com(26,i);
			for(i=0;s[i];i++){
				if(i==0) j='a';	 else j=s[i-1]+1;
				for(;j<s[i];j++) n+=com('z'-j, strlen(s)-i-1);
			}  
			printf("%I64d\n",n+1);
		}  
	} 
	return 0;
}