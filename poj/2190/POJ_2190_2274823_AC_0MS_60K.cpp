#include<stdio.h>
int main()
{
	char isbn[11];
	int n=0,i,x,y;
	scanf("%s",isbn);
	if(isbn[9]=='X') n=10;
	else if(isbn[9]=='?') n=0,x=1;
	else n=isbn[9]-'0';
	for(i=10;i>1;i--)
	{
		if(isbn[10-i]=='?') {x=i;continue;}
		n+=(isbn[10-i]-'0')*i;
	}
	y=10-(n-1)%11;
	while(1)
	{
		if(y%x==0||y/x>10) break;
		y+=11;
	}
	if(y/x<10&&y/x>=0) printf("%d\n",y/x);
	else if(y==10&&x==1) printf("X\n");
	else printf("-1\n");
	return 0;
}