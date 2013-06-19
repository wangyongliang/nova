#include<stdio.h>
#define maxn 10000000
int q[maxn],p[maxn],qq,pp;
char ch;
int main()
{
	char ch;
	int i,j,k,n;
	int flag,flg,flg1;
	while(1)
	{
		ch=getchar();
		if(ch==EOF) break;
		if(ch=='\n') continue;
		pp=qq=i=0;
		flg1=flg=flag=1;
		while(1)
		{
			while(ch==' ')ch=getchar();
			if(ch=='\n') 
			{
				break;
				flg1=0;
			}
			if(ch=='-') k=-1,n=0;
			else k=1,n=ch-'0';
			for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) n=n*10+ch-'0';
			n*=k;
			if(n>0)
			{
				if(pp==0)
				{
					flag=0;
					break;
				}
				if(q[pp-1]==-n)
				{
					if(p[pp-1]>=n)
					{
						flag=0;
						break;
					}
					if(pp-1>0) p[pp-2]+=n;
					else
					{
						if(flg) flg=0;
						else 
						{
							flag=0;
							break;
						}
					}
					pp--;
				}
				else
				{
					flag=0;
					break;
				}
			}
			else
			{
				q[pp]=n;
				p[pp++]=0;
			}
		}
		if(flag&&pp==0) printf(":-) Matrioshka!\n");
		else
		{
			printf(":-( Try again.\n");
			if(ch!='\n')
			{
				while(getchar()!='\n');
			}
		}
	}
	return 0;
}
