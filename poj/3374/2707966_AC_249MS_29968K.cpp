#include <stdio.h>
int seq[2][4000000];
int n,c,t;
int total;
void makeseq(int x1,int y1,int x2,int y2)
{
	if(y1+y2>n)
		return;
	makeseq(x1,y1,x1+x2,y1+y2);
	total++;
	seq[0][total]=x1+x2;
	seq[1][total]=y1+y2;
	makeseq(x1+x2,y1+y2,x2,y2);
	
}
int main(int argc, char* argv[])
{
	scanf("%d%d",&n,&c);
	if(n==1)
	{
		while(c--)
		{
			scanf("%d",&t);
			if(t==1)
				printf("0/1\n");
			else
				if(t==2)
					printf("1/1\n");
				else
					printf("No Solution\n");
		}
		return 0;
	}
	total++;
	seq[0][total]=0;
	seq[1][total]=1;
	makeseq(0,1,1,2);
	total++;
	seq[0][total]=1;
	seq[1][total]=2;
	while(c--)
	{
		scanf("%d",&t);
		if(t>=2*total)
			printf("No Solution\n");
		else
			if(t<=total)
				printf("%d/%d\n",seq[0][t],seq[1][t]);
			else
				printf("%d/%d\n",seq[1][2*total-t]-seq[0][2*total-t],seq[1][2*total-t]);
	}
	return 0;
}