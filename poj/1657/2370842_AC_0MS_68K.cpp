#include <math.h>
#include <stdio.h>


void read()
{
	int t,i,x1,y1,x2,y2;
	int r1,r2,r3,r4;
	char s1[2],s2[2];
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%s %s",s1,s2);
		x1=s1[0]-'a'+1;
		y1=s1[1]-'0';
		x2=s2[0]-'a'+1;
		y2=s2[1]-'0';
		if ((x1>8)||(x2>8)||(y1>8)||(y2>8)) continue;
		if ((x1==x2)&&(y1==y2)) {printf("0 0 0 0\n");continue;}
		if (fabs(x1-x2)>fabs(y1-y2)) r1=int(fabs(x1-x2)); else r1=int(fabs(y1-y2));
		r2=2;r3=2;r4=2;
		if ((x1==x2)||(y1==y2)) {r2=1;r3=1;}
		if (fabs(x1-x2)==fabs(y1-y2)) {r2=1;r4=1;}
		if ((x1+y1)%2!=(x2+y2)%2) r4=0;
		if (r4==0) printf("%d %d %d Inf\n",r1,r2,r3); else printf("%d %d %d %d\n",r1,r2,r3,r4);
	}
}


int main()
{
	read();
	return 0;
}