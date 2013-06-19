#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	int cnt,len,id,ix;
	int i,j;
	int m;
	while(gets(s))
	{
		if(strcmp(s,"END")==0) break;
		cnt=-1;
		m=strlen(s);
		for(i=0;i<m;i++)
		{
			for(j=1;j<m;j++)
			{
				int x=i;
				int time=-1;
				for(time=0;x<m&&s[x]=='.';x+=j) time++;
				if(x>=m) x-=j;
				if(time>cnt||(time==cnt&&x>len)||(time==cnt&&x==len&&i>id)
					||(time==cnt&&x==len&&id>id&&ix<j))
				{
					cnt=time;
					len=x;
					id=i;
					ix=j;
				}
			}
		}
		printf("%d %d\n",id,ix);
	}
	return 0;
}